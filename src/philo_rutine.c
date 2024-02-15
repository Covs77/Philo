/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rutine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:20:43 by cleguina          #+#    #+#             */
/*   Updated: 2024/02/15 20:57:19 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


int	ft_dead(t_table *t)
{
	pthread_mutex_lock(&t->mtx_table);
	if (t->dead == 1)
	{
		pthread_mutex_unlock(&t->mtx_table);
		return (1);
	}
	else
		pthread_mutex_unlock(&t->mtx_table);
	return (0);
}





void	ft_take_forks(t_table *t, t_philo *ph)
{
	pthread_mutex_lock(&t.fork[ph->id]->fork_l);
	printf("Philosopher %ld taken left fork\n", ph->id);
	if (t->philo != 1)
	{
		pthread_mutex_lock(&t->fork[ph->id + 1]->fork_l);
		printf("Philosopher %ld taken right fork\n", ph->id);
	}
	else
	{
		pthread_mutex_unlock(&t->fork[ph->id]->fork_l);
		return ;		
	}
}



void ft_simulator(t_table *table, t_philo *ph)
{
	while (table->dead != 0)
	{
		if (ft_is_dead(&table))
			break ;
		ft_take_forks(table, ph);
		


	}
}