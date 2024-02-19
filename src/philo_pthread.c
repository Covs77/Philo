/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_pthread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:48:59 by cleguina          #+#    #+#             */
/*   Updated: 2024/02/19 20:58:02 by cleguina         ###   ########.fr       */
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
	usleep(ms * 920);
	while (ft_init_time() < time + ms)
		usleep(ms * 3);
}

void	*routine(void *args)
{
	t_philo	*p;

	p = (t_philo *)args;
	if (p->id % 2 == 0)
		ft_usleep(1);
	while (p->table->dead != 0 || p->meals != 0)
		ft_simulator(p);
	if (p->meals == 0)
		ft_print_action(p, "Has finished eating\n");
	return (NULL);
}

void	ft_init_pthread(t_table	*table)
{
	int	i;

	i = 0;
	while (i < table->philo)
	{
		if (pthread_create(&table->ph[i].thread, NULL, routine, &table->ph[i]))
			ft_error("Error creating thread");
		pthread_mutex_lock(&table->mtx_table);
		table->ph[i].last_eat = ft_init_time();
		pthread_mutex_unlock(&table->mtx_table);
		i++;
	}
}
