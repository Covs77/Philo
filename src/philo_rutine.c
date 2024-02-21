/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rutine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:20:43 by cleguina          #+#    #+#             */
/*   Updated: 2024/02/21 19:53:28 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"



void *controller (void *args)
{
	t_table *t;
	
	
	t = (t_table *)args;
	printf("Controller\n");
	while (1)
	{
		
		if (ft_check_is_died(t) != 0)
			return (NULL) ; // break? // cerrar hilos // free all??????
		//if (ft_exit_for_eat(t))
		//	return (NULL); // break? // cerrar hilos // free all?????? */
	}
	return (NULL);
}


int	ft_check_is_died(t_table *t)
{
	int	i;
	long time;

	i = 0;
	time = ft_init_time();
	//ft_usleep(100);
	pthread_mutex_lock(&t->mtx_table);
	while (i < t->philo && t->dead == 0)
	{
		if (ft_init_time() - t->ph[i].last_eat >= t->time_life)
		{
			t->dead = 1;
			ft_print_action(&t->ph[i], "dead\n");
			return (1);
		}
		i++;
	} 
	pthread_mutex_unlock(&t->mtx_table);
	return (0);
}

int	ft_exit_for_eat(t_table *t)
{
	int i;
	int all;
	
	i= 0;
	all = t->philo;
	if (t->n_eat == -1)
		return (0);
	while (all != 0)
	{
		if (t->ph[i].meals == 0)
			all--;
		else
			return (0);
		i++;
	}
	return (1);
	
}

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
	
	ft_print_action(ph, "take left fork\n");
	ft_print_action(ph, "take right fork\n"); ///aqui no va
	/* if (ph->table->philo != 1)
	{
		if (ph->id == ph->table->philo)
			pthread_mutex_lock(&ph->table->fork[1].fork_r);
		else
			pthread_mutex_lock(&ph->table->fork[ph->id + 1].fork_r);
		ft_print_action(ph, "has take right fork\n");
	}
	else
	{
		pthread_mutex_unlock(&ph->table->fork[ph->id].fork_l);
		return ;
	} */
}
	

void	ft_eating(t_philo *ph)
{
	ft_print_action(ph, "is eating\n");
	ft_usleep(ph->table->time_eat);
	ph->meals--;
	ph->last_eat = ft_init_time();
	//printf("Meals: %d %ld\n", ph->meals, ph->id);
}
void	ft_sleeping(t_philo *ph)
{
	ft_print_action(ph, "is sleeping\n");
	ft_usleep(ph->table->time_sleep);
}

void	ft_thinking(t_philo *ph)
{
	ft_print_action(ph, "is thinking\n");
}

void	ft_simulator(t_philo *ph)
{
	while (ph->table->dead != 1)
	{
		ft_take_forks(ph);
		ft_eating(ph);
		if (ph->meals == 0)
			break ;
		ft_sleeping(ph);
		ft_thinking(ph);
		
	}
}
