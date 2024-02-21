/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check_inputs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:17:35 by cova              #+#    #+#             */
/*   Updated: 2024/02/21 19:02:12 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_isdigit(int c)
{
	if ((c > 47) && (c < 58))
		return (0);
	return (1);
}

int	ft_check_num(char **str)
{
	int	error;
	int	i;
	int	j;

	error = 0;
	i = 1;
	j = 0;
	if (!str[i])
		return (1);
	while (str[i])
	{
		while (str[i][j] != '\0')
		{
			if (j == 0 && (str[i][j] == '-' || str[i][j] == '+'))
				j++;
			error = ft_isdigit(str[i][j]);
			if (error == 1)
				return (1);
			j++;
		}
		i++;
		j = 0;
	}
	return (error);
}

void	ft_check_args(int argc, char **argv, t_table *table)
{
	if ((argc == 5 || argc == 6) && (ft_check_num(argv) == 0))
	{
		table->philo = ft_atoi(argv[1]);
		table->time_life = ft_atoi(argv[2]);
		table->time_eat = ft_atoi(argv[3]);
		table->time_sleep = ft_atoi(argv[4]);
		table->time_start = ft_init_time();
		table->dead = 0;
		if (argc == 6)
		{
			table->n_eat = ft_atoi(argv[5]);
			if (table->n_eat > INT_MAX)
				ft_error_inputs("Gloton, no puedes comer tanto");
			else if (table->n_eat < 1)
				ft_error_inputs("Debes comer 1 vez o morirás de hambre");
		}
	}
	else
		ft_error_inputs("Error: Wrong arguments\n");
	if (table->philo < 2 || table->philo > 200)
		ft_error_inputs("Error: Wrong number of philos\n");
}
