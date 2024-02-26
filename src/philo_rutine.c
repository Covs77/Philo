/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rutine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:20:43 by cleguina          #+#    #+#             */
/*   Updated: 2024/02/26 21:14:00 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
void	ft_left_fork (t_philo	*ph)
{
		pthread_mutex_lock(&ph->table->fork[ph->id].fork_l);
		ph->table->fork[ph->id].busy = 1;
		pthread_mutex_unlock(&ph->table->fork[ph->id].fork_l);
		ft_print_action(ph, "take left fork\n");
}

void ft_right_fork(t_philo *ph)
{
	int right;

	right = 0;	
	if (ph->id != ph->table->philo)
		right = ph->id +1;
	else
		right = 1;
	printf("Right fork = %d (%d)\n", ph->table->fork[right].busy, right);
	pthread_mutex_lock(&ph->table->fork[right].fork_r);
	ph->table->fork[ph->id+1].busy = 1;
	pthread_mutex_unlock(&ph->table->fork[ph->id + 1].fork_r);
	ft_print_action(ph, "take right fork\n");
	printf("Right fork = %d (%d)\n", ph->table->fork[right].busy, right);
}
	
void ft_release_forks(t_philo *ph)
{
	int right;

	right = 0;	
	if (ph->id != ph->table->philo)
		right = ph->id +1;
	else
		right = 1;
	if (ph->table->fork[ph->id].busy == 1 || ph->table->fork[right].busy == 1)
	{
		pthread_mutex_lock(&ph->table->fork[ph->id].fork_l);
		ph->table->fork[ph->id].busy = 0;
		pthread_mutex_unlock(&ph->table->fork[ph->id].fork_l);
		pthread_mutex_lock(&ph->table->fork[right].fork_r);
		ph->table->fork[right].busy = 0;
		pthread_mutex_unlock(&ph->table->fork[right].fork_r);
		printf("Release\nLeft fork = %d (%ld)\n", ph->table->fork[ph->id].busy, ph->id);
		printf("Right fork = %d (%d)\n", ph->table->fork[right].busy, right);
		printf("Left fork = %d (%ld)\n", ph->table->fork[ph->id].busy, ph->id);
	
	}
}

void	ft_take_forks(t_philo *ph)
{
	int right;

	right = 0;
	if (ft_stop_all(ph->table) == 0)
	{
		printf("left block (%ld)= %d\n", ph->id, ph->table->fork[ph->id].busy);
		while (ph->table->fork[ph->id].busy == 0)
			ft_left_fork(ph);
	/* 	if (ph->table->fork[ph->id].busy == 0)
			ft_left_fork(ph);
		else
				break ; */
		
		printf("left block(%ld)= %d\n", ph->id, ph->table->fork[ph->id].busy);
		if (ph->table->philo != 1)
		{
			if (ph->id != ph->table->philo)
				right = ph->id +1;
			else
				right = 1;
		
			while (ph->table->fork[right].busy == 0)
				ft_right_fork(ph);
		}
	}	
	else
	
		//	ft_release_forks(ph);
			return ;
}
int ft_both_forks(t_philo *ph)
{
	int right;
	
	right = 0;
	if (ph->id != ph->table->philo)
		right = ph->id +1;
	else
		right = 1;
	if (ph->table->fork[ph->id].busy == 1 && ph->table->fork[right].busy == 1)
		return (1);
	else
		return (0);
}



void	ft_eating(t_philo *ph)
{
	if (ph->table->dead == 0 && ft_both_forks(ph) == 1)
	{
		
		ft_print_action(ph, "is eating\n");
		ft_usleep(ph->table->time_eat);
		ph->meals--;
		ph->last_eat = ft_init_time();
		ft_release_forks(ph);
		
	}
}

void	ft_sleeping(t_philo *ph)
{
	if (ph->table->dead == 0 && ph->table->food == 0)
	{
		ft_print_action(ph, "is sleeping\n");
		ft_usleep(ph->table->time_sleep);
	}
}

void	ft_thinking(t_philo *ph)
{
	if (ph->table->dead == 0 && ph->table->food == 0)
		ft_print_action(ph, "is thinking\n");
}

void	ft_simulator(t_philo *ph)
{
//	while (ph->table->dead == 0 && ph->table->food == 0)
//	{
		ft_take_forks(ph);
		ft_eating(ph);
		ft_sleeping(ph);
		ft_thinking(ph);
	
//	}
}
