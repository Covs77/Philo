/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:39:44 by cleguina          #+#    #+#             */
/*   Updated: 2024/02/28 12:52:33 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_free_all(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo)
	{
		pthread_mutex_destroy(&table->ph[i].fork_l);
		pthread_mutex_destroy(table->ph[i].fork_r);
		i++;
	}
	pthread_mutex_destroy(&table->mtx_table);
	pthread_mutex_destroy(&table->mtx_print);
	pthread_mutex_destroy(&table->mtx_dead);
	free(table->ph);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_table	table;
	t_philo	philo;

	ft_init_table(&table);
	ft_init_philo(&philo);
	ft_check_args(argc, argv, &table);
	ft_start_table(&table);
	ft_init_mutex(&table);
	ft_init_pthread(&table);
	ft_free_all(&table);
	ft_l();
	return (0);
}
