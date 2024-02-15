/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_pthread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:48:59 by cleguina          #+#    #+#             */
/*   Updated: 2024/02/15 20:59:21 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


long	init_time(void)
{
	unsigned long	nbr;
	struct timeval	init;

	if (gettimeofday(&init, NULL) < 0)
		ft_error("Time init error");
	nbr = (init.tv_sec * 1000) + (init.tv_usec / 1000);
	return (nbr);
}

/* 
void	*routine(void *args)
{
	t_philo	*p;

	p = (t_philo *)args;
	if (p->id % 2 == 0)
		ft_usleep(1, p->t);
	ft_simulator(p);
	if (p->philo == 1)
		return (NULL);
	else if (ft_num_meals(p))
		return (NULL);
	else if (ft_dead(p))
		return (NULL);
	return (NULL);
} */

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