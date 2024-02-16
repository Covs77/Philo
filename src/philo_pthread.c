/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_pthread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:48:59 by cleguina          #+#    #+#             */
/*   Updated: 2024/02/16 19:16:42 by cova             ###   ########.fr       */
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
	ft_simulator(p);
	if (p->id == 1)
		return (NULL);
//	else if (ft_num_meals(p))
//		return (NULL);
//	else if (ft_dead(p))
//		return (NULL);
	return (NULL);
} 

void	ft_init_pthread(t_table	*table)
{
	int i;

	i = 0;
	while (i < table->philo)
	{
		if (pthread_create(&table->ph[i].thread, NULL, routine, &table->ph[i]))
			ft_error("Error creating thread");
		i++;
	}

}