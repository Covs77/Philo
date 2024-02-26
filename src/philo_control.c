/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:53:58 by cleguina          #+#    #+#             */
/*   Updated: 2024/02/26 20:19:17 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


void *controller (void *args)
{
	t_table *t;
	
	
	t = (t_table *)args;
	while (1)
	{
		if (ft_check_is_died(t) != 0)
			return (NULL);
		if (ft_foodie(t) != 0)
			return (NULL) ;
		
	}
	return (NULL);
}

int	ft_check_is_died(t_table *t)
{
	int	i;
	long time;

	i = 0;
	time = ft_init_time();
	//pthread_mutex_lock(&t->mtx_dead);
	while (i < t->philo && t->dead == 0)
	{
		if (ft_init_time() - t->ph[i].last_eat >= t->time_life)
		{
			//pthread_mutex_lock(&t->mtx_dead);
			t->dead = 1;
			//pthread_mutex_unlock(&t->mtx_dead);
			ft_print_action(&t->ph[i], "dead\n");
			return (1);
		}
		i++;
	} 
	//pthread_mutex_unlock(&t->mtx_dead);
	return (0);
}

int	ft_foodie(t_table *t)
{
	int i;
	
	i = 0;
	while (i < t->philo && t->ph[i].meals == 0)
		i++;
	if (i == t->philo)
	{	
		t->food = 1;
		return (1);
	}
	return (0);
}


int	ft_dead(t_table *t)
{
	//pthread_mutex_lock(&t->mtx_dead);
	if (t->dead == 1)
	{
	//	pthread_mutex_unlock(&t->mtx_dead);
		return (1);
	}
	else
	//	pthread_mutex_unlock(&t->mtx_dead);
	return (0);
}

int ft_stop_all(t_table *t)
{
	//pthread_mutex_lock(&t->mtx_dead);
	if (t->dead == 1 || t->food == 1)
	{
	//	pthread_mutex_unlock(&t->mtx_dead);
		return (1);
	}
	else
	{
	//	pthread_mutex_unlock(&t->mtx_dead);
		return (0);
	}
}	