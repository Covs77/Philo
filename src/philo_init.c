/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:50:22 by cleguina          #+#    #+#             */
/*   Updated: 2024/02/27 20:49:27 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_init_mutex(t_table *t)
{
	long	i;

	i = 0;
	while (i < t->philo)
	{
		if (pthread_mutex_init(&t->ph[i].fork_l, NULL) != 0)
			ft_error("Error: Mutex init failed\n");
		if (pthread_mutex_init(&t->ph[i].fork_r, NULL) != 0)
			ft_error("Error: Mutex init failed\n");
		i++;
	}
	if (pthread_mutex_init(&t->mtx_table, NULL) != 0)
		ft_error("Error: Mutex init failed\n");
	if (pthread_mutex_init(&t->mtx_dead, NULL) != 0)
		ft_error("Error: Mutex dead failed\n");
	if (pthread_mutex_init(&t->mtx_print, NULL) != 0)
		ft_error("Error: Mutex dead failed\n");
	
}

void	ft_init_table(t_table *t)
{
	t->philo = 0;
	t->ph = NULL;
	t->fork = NULL;
	t->time_life = 0;
	t->time_eat = 0;
	t->time_sleep = 0;
	t->n_eat = -1;
	t->dead = 0;
	t->food = 0;
}

void	ft_init_philo(t_philo *p)
{
	p->id = 1;
	p->last_eat = 0;
	p->meals = 0;
	p->table = NULL;
}

void	ft_init_fork(t_fork *fork)
{
	fork->id = 0;
}

void	ft_start_table(t_table *table)
{
	long	i;

	i = table->philo;
	table->ph = malloc(sizeof(t_philo) * i);
	if (table->ph == NULL)
		ft_error("Error: Malloc failed\n");
	table->fork = malloc(sizeof(t_fork) * i);
	if (table->fork == NULL)
		ft_error("Error: Malloc failed\n");
	i = 0;
	while (i < table->philo)
	{
		table->fork[i].id = i + 1;
		table->ph[i].id = i + 1;
		table->ph[i].meals = table->n_eat;
		table->ph[i].table = table;
		table->ph[i].last_eat = table->time_start;
		table->ph[i].fork_l_id = table->fork[i].id;
		if (i == table->philo - 1)
			table->ph[i].fork_r_id = 1;
		else
			table->ph[i].fork_r_id = table->fork[i].id + 1;
		i++;
		
	}
	//ft_print_table(table);
}
