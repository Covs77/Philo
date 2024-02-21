/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_pthread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:48:59 by cleguina          #+#    #+#             */
/*   Updated: 2024/02/21 19:54:41 by cleguina         ###   ########.fr       */
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
	while (p->table->dead == 0)
		ft_simulator(p);
	if (p->meals == 0)
		ft_print_action(p, "Has finished eating\n");
	if (p->table->dead == 1)
		ft_print_action(p, "dead\n");
	return (NULL);
}

void	ft_init_pthread(t_table	*table)
{
	int	i;
	table->time_start = ft_init_time();
	
	i = 0;
	if (pthread_create(&table->control, NULL, controller, table) != 0)
		ft_error("Error creating thread");
	while (i < table->philo)
	{
		
		if (pthread_create(&table->ph[i].thread, NULL, routine, &table->ph[i]) != 0)
			ft_error("Error creating thread");
		table->ph[i].last_eat = table->time_start;
		i++;
	}
	ft_init_joins(table); ///no se si va aqui ni si ha de estar en bucle??
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