/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check_inputs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:17:35 by cova              #+#    #+#             */
/*   Updated: 2024/02/06 18:38:45 by cova             ###   ########.fr       */
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
            if (argc == 6)
                table->n_eat = ft_atoi(argv[5]);
    }
	else 
			ft_error ("Error: Wrong arguments\n");
	if (table->philo < 2 || table->philo > 200)
		ft_error("Error: Wrong number of philos\n");
	
	printf(RED "Nª total philos: %ld\n" RESET, table->philo);
	printf(GREEN "time_life: %ld\n" RESET, table->time_life);
	printf(BLUE "time_eat: %ld\n" RESET, table->time_eat);
	printf(MAGENTA "time_sleep: %ld\n" RESET, table->time_sleep);
	printf(WHITE "n_eat: %ld\n" RESET, table->n_eat);
	

} 