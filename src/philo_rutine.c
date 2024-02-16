/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rutine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:20:43 by cleguina          #+#    #+#             */
/*   Updated: 2024/02/16 19:16:18 by cova             ###   ########.fr       */
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





void	ft_take_forks(t_philo *ph)
{
	ft_print_action(ph->id, "take left fork\n");
	ft_print_action(ph->id, "take right fork\n");
	
}
void ft_eating(t_philo *ph)
{
	ft_print_action(ph->id, "is eating\n");
	
}
void ft_sleeping(t_philo *ph)
{
	ft_print_action(ph->id, "is sleeping\n");
}

void ft_thinking(t_philo *ph)
{
	ft_print_action(ph->id, "is thinking\n");
}

void ft_simulator(t_philo *ph)
{
	ft_take_forks(ph);
	ft_eating(ph);
	ft_thinking(ph);
	ft_sleeping(ph);
}
