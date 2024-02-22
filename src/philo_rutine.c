/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rutine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:20:43 by cleguina          #+#    #+#             */
/*   Updated: 2024/02/22 21:09:44 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"



void	ft_take_forks(t_philo *ph)
{
	if (ft_stop_all(ph->table) == 0)
	{	ft_print_action(ph, "take left fork\n");
		ft_print_action(ph, "take right fork\n"); ///aqui no va
	}
}
	

void	ft_eating(t_philo *ph)
{
	if (ph->table->dead == 0 && ph->table->food == 0)
	{	
		//pthread_mutex_lock(&ph->table->mtx_table);
		ft_print_action(ph, "is eating\n");
		ft_usleep(ph->table->time_eat);
		ph->meals--;
		ph->last_eat = ft_init_time();
		//	pthread_mutex_unlock(&ph->table->mtx_table);
	}
}
void	ft_sleeping(t_philo *ph)
{
	if (ph->table->dead == 0)
	{
		ft_print_action(ph, "is sleeping\n");
		ft_usleep(ph->table->time_sleep);
	}
}

void	ft_thinking(t_philo *ph)
{
	if (ph->table->dead == 0)
		ft_print_action(ph, "is thinking\n");
}

void	ft_simulator(t_philo *ph)
{
	while (ph->table->dead == 0 && ph->table->food == 0)
	{
		ft_take_forks(ph);
		ft_eating(ph);
		ft_sleeping(ph);
		ft_thinking(ph);
		printf("dead == %d\n", ph->table->dead);
		printf("food == %d\n", ph->table->food);
	}
}
