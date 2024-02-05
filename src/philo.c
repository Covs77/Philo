/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:39:44 by cleguina          #+#    #+#             */
/*   Updated: 2024/02/05 19:43:41 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


void ft_init_table(t_table *t)
{
	t->philo = 0;
	t->ph = NULL;
	t->fork = NULL;
	t->time_life = 0;
	t->time_eat = 0;
	t->time_sleep = 0;
	t->n_eat = 0;

}

void	ft_check_args(int argc, char *argv, t_table *table)
{
	int i;

	i= 0;
	if (argc == 5 || argc == 6)
	{
	
		table->philo = ft_atoi(&argv[1]);
		table->time_life = ft_atoi(&argv[2]);
		table->time_eat = ft_atoi(&argv[3]);
		table->time_sleep = ft_atoi(&argv[4]);
		if (argc == 6)
			table->n_eat = ft_atoi(&argv[5]);
	}
	else 
		ft_error ("Error: Wrong number of arguments\n");
/* 	while (i < argc -1)
	{
		printf("philo: %d\n", table->philo);
		printf("time_life: %ld\n", table->time_life);
		printf("time_eat: %ld\n", table->time_eat);
		printf("time_sleep: %ld\n", table->time_sleep);
		printf("n_eat: %ld\n", table->n_eat);
		i++;

	} */
}
		


int main(int argc, char **argv)
{
	t_table	*table;

	table = NULL;
	
	ft_init_table(table);
	ft_check_args(argc, *argv, table);
	return (0);
	
}