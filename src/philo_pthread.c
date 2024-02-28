/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_pthread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:48:59 by cleguina          #+#    #+#             */
/*   Updated: 2024/02/28 12:56:00 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	ft_init_time(void)
{
	unsigned long	nbr;
	struct timeval	init;

	if (gettimeofday(&init, NULL) < 0)
		ft_error("Time init error");
	nbr = (init.tv_sec * 1000) + (init.tv_usec / 1000);
	return (nbr);
}

void	ft_usleep(int ms)
{
	long			time;

	time = ft_init_time();
	usleep(ms * 1000);
	while (ft_init_time() < time + ms)
		usleep(ms * 3);
}

void	*routine(void *args)
{
	t_philo	*p;

	p = (t_philo *)args;
	if (p->id % 2 == 0)
		ft_usleep(1);
	while (p->table->dead == 0 && p->table->food == 0)
		ft_simulator(p);
	return (NULL);
}

void	ft_init_pthread(t_table	*t)
{
	int	i;

	t->time_start = ft_init_time();
	i = 0;
	if (pthread_create(&t->control, NULL, controller, t))
		ft_error("Error creating thread");
	while (i < t->philo)
	{
		if (pthread_create(&t->ph[i].thread, NULL, routine, &t->ph[i]) != 0)
			ft_error("Error creating thread");
		t->ph[i].last_eat = t->time_start;
		i++;
	}
	ft_init_joins(t);
}

void	ft_init_joins(t_table *t)
{
	int	i;

	i = 0;
	while (i < t->philo)
	{
		if (0 != pthread_join(t->ph[i].thread, NULL))
			ft_error("Error al esperar al filósofo\n");
		i++;
	}
	if (0 != pthread_join(t->control, NULL))
		ft_error("Error al esperar al filósofo\n");
}
