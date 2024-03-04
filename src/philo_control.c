/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:53:58 by cleguina          #+#    #+#             */
/*   Updated: 2024/03/04 17:30:46 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*controller(void *args)
{
	t_table	*t;

	t = (t_table *)args;
	while (1)
	{
		if (ft_check_is_died(t))
			return (NULL);
		if (ft_foodie(t))
			return (NULL);
	}
	return (NULL);
}

int	ft_check_is_died(t_table *t)
{
	int	i;

	i = 0;
	while (i < t->philo && ft_dead(t) == 0)
	{
		pthread_mutex_lock(&t->mtx_table);
		if ((ft_init_time() - t->ph[i].last_eat) >= t->time_life)
		{
			pthread_mutex_unlock(&t->mtx_table);
			pthread_mutex_lock(&t->mtx_dead);
			t->dead = 1;
			pthread_mutex_unlock(&t->mtx_dead);
			ft_print_action(&t->ph[i], "died\n");
			return (1);
		}
		pthread_mutex_unlock(&t->mtx_table);
		i++;
	}
	return (0);
}

int	ft_foodie(t_table *t)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&t->mtx_meal);
	while (i < t->philo && t->ph[i].meals == 0)
	{
		pthread_mutex_unlock(&t->mtx_meal);
		i++;
		pthread_mutex_lock(&t->mtx_meal);
	}
	pthread_mutex_unlock(&t->mtx_meal);
	if (i == t->philo)
	{
		pthread_mutex_lock(&t->mtx_meal);
		t->food = 1;
		pthread_mutex_unlock(&t->mtx_meal);
		return (1);
	}
	return (0);
}

int	ft_dead(t_table *t)
{
	pthread_mutex_lock(&t->mtx_dead);
	if (t->dead == 1)
	{
		pthread_mutex_unlock(&t->mtx_dead);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&t->mtx_dead);
		return (0);
	}
}

int	ft_stop(t_table *t)
{
	if (ft_dead(t) == 1)
		return (1);
	else if (ft_foodie(t) == 1)
		return (1);
	return (0);
}
