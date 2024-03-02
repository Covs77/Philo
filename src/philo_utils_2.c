/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:11:46 by cova              #+#    #+#             */
/*   Updated: 2024/03/02 12:20:19 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else if (s1[i] > s2[i])
			return (1);
		else
			return (-1);
	}
	return (0);
}

void	ft_print_action(t_philo *ph, char *str)
{
	long	time;

	time = ft_init_time() - ph->table->time_start;
	pthread_mutex_lock(&ph->table->mtx_print);
	if (ph->table->dead == 1 && (ft_strcmp(str, "died\n") == 0))
	{	
		printf(RED "%ld %ld %s" RESET, (time), ph->id, str);
		pthread_mutex_unlock(&ph->table->mtx_print);
		return ;
	}
	if (ft_stop_all(ph->table) == 0)
	{
		if (ft_strcmp(str, "is eating\n") == 0)
			printf(MAGENTA "%ld %ld %s" RESET, (time), ph->id, str);
		else if (ft_strcmp(str, "is sleeping\n") == 0)
			printf(YELLOW "%ld %ld %s" RESET, (time), ph->id, str);
		else if (ft_strcmp(str, "is thinking\n") == 0)
			printf(CYAN "%ld %ld %s" RESET, (time), ph->id, str);
		else if (ft_strcmp(str, "has taken a fork\n") == 0)
			printf(BLUE "%ld %ld %s" RESET, (time), ph->id, str);
		else
			printf("%ld %ld %s", (time), ph->id, str);
	}
	pthread_mutex_unlock(&ph->table->mtx_print);
}

void	ft_print_table(t_table *table)
{
	long	i;

	if (table->philo != 0)
	{
		i = 0;
		while (i < table->philo)
		{
			printf(YELLOW "Philosofo nº: %ld\n" RESET, table->ph[i].id);
			printf(MAGENTA "Philosofo id: %ld\n" RESET, table->ph[i].id);
			printf(CYAN "time_life: %ld\n" RESET, table->time_life);
			printf(CYAN "Time_eat: %ld\n" RESET, table->time_eat);
			printf(CYAN "Time_sleep: %ld\n" RESET, table->time_sleep);
			printf(BLUE "Eat times: %d\n" RESET, table->ph[i].meals);
			i++;
		}
	}
}

int	ft_food(t_table *t)
{
	pthread_mutex_lock(&t->mtx_meal);
	if (t->food == 1)
	{
		pthread_mutex_unlock(&t->mtx_meal);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&t->mtx_meal);
		return (0);
	}
}
