/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:53:58 by cleguina          #+#    #+#             */
/*   Updated: 2024/02/22 21:04:18 by cleguina         ###   ########.fr       */
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

int	ft_foodie(t_table *t)
{
	int i;
	
	i = 0;
	//if (t->n_eat == -1)
	//	return (0);
	//pthread_mutex_lock(&t->mtx_table);
	//printf("meals: %d ph[%d]\n", t->ph[i].meals, i);
	while (i < t->philo && t->ph[i].meals == 0)
		i++;
	//printf("El filosofo %d, tiene q comer %d veces\n", i, t->ph[i].meals);
	if (i == t->philo)
	{	
		t->food = 1;
		return (1);
	}
	return (0);
}


int	ft_dead(t_table *t)
{
	//pthread_mutex_lock(&t->mtx_table);
	if (t->dead == 1)
	{
	//	pthread_mutex_unlock(&t->mtx_table);
		return (1);
	}
	else
		pthread_mutex_unlock(&t->mtx_table);
	return (0);
}
int ft_stop_all(t_table *t)
{
	if (t->dead == 1 || t->food == 1)
		return (1);
	else
		return (0);
}	