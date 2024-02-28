/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rutine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:20:43 by cleguina          #+#    #+#             */
/*   Updated: 2024/02/28 12:49:58 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_eating(t_philo *ph)
{
	if (ph->table->dead == 0 || ph->table->food == 0)
	{
		pthread_mutex_lock(&ph->fork_l);
		ft_print_action(ph, "has taken left fork\n");
		pthread_mutex_lock(*&ph->fork_r);
		ft_print_action(ph, "has taken right fork\n");
	}
	if (ft_stop_all(ph->table) == 0 && ph->table->philo != 1)
	{
		ft_print_action(ph, "is eating\n");
		ft_usleep(ph->table->time_eat);
		ph->last_eat = ft_init_time();
		ph->meals--;
		pthread_mutex_unlock(&ph->fork_l);
		pthread_mutex_unlock(*&ph->fork_r);
	}
}

void	ft_sleeping(t_philo *ph)
{
	if (ft_stop_all(ph->table) == 0)
	{
		ft_print_action(ph, "is sleeping\n");
		ft_usleep(ph->table->time_sleep);
	}
}

void	ft_thinking(t_philo *ph)
{
	if (ph->table->dead == 0 || ph->table->food == 0)
		ft_print_action(ph, "is thinking\n");
}

void	ft_simulator(t_philo *ph)
{
	ft_eating(ph);
	ft_sleeping(ph);
	ft_thinking(ph);
}
