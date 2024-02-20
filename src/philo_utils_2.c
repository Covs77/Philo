/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:11:46 by cova              #+#    #+#             */
/*   Updated: 2024/02/20 20:51:30 by cleguina         ###   ########.fr       */
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
	long	time_act;
	long	clock;
	int		id;

	id = ph->id;
	time_act = ft_init_time();
	clock = ph->table->time_start;
	if (ft_strcmp(str, "dead") == 0)
		printf(RED "%ld %d %s" RESET, (time_act - clock), id, str);
	else if (ft_strcmp(str, "is eating\n") == 0)
		printf(WHITE "%ld %d %s" RESET, (time_act - clock), id, str);
	else if (ft_strcmp(str, "is sleeping\n") == 0)
		printf(YELLOW "%ld %d %s" RESET, (time_act - clock), id, str);
	else if (ft_strcmp(str, "is thinking\n") == 0)
		printf(CYAN "%ld %d %s" RESET, (time_act - clock), id, str);
	else if (ft_strcmp(str, "take left fork\n") == 0)
		printf(GREEN "%ld %d %s" RESET, (time_act - clock), id, str);
	else if (ft_strcmp(str, "take right fork\n") == 0)
		printf(BLUE "%ld %d %s" RESET, (time_act - clock), id, str);
	else
	{
		printf("%ld %d %s", (time_act - clock), id, str);
	}
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
			//printf(MAGENTA "fork (id): %d\n" RESET, table->fork[i].id);
			printf(CYAN "time_life: %ld\n" RESET, table->time_life);
			//printf(CYAN "Time_eat: %ld\n" RESET, table->time_eat);
			//printf(CYAN "Time_sleep: %ld\n" RESET, table->time_sleep);
			printf(BLUE "Eat times: %d\n" RESET, table->ph[i].meals);
			i++;
		}
	}
}

