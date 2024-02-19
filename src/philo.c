/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:39:44 by cleguina          #+#    #+#             */
/*   Updated: 2024/02/19 20:35:38 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_kill_pthread(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo)
	{
		if (pthread_join(table->ph[i].thread, NULL))
			ft_error("Error joining thread");
		i++;
	}
}

void	ft_free_all(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo)
	{
		pthread_mutex_destroy(&table->fork[i].fork_l);
		i++;
	}
	pthread_mutex_destroy(&table->mtx_table);
	free(table->ph);
	free(table->fork);
}

int	main(int argc, char **argv)
{
	t_table	table;
	t_philo	philo;
	t_fork	fork;

	ft_init_table(&table);
	ft_init_philo(&philo);
	ft_init_fork(&fork);
	ft_check_args(argc, argv, &table);
	ft_start_table(&table);
	ft_init_mutex(&table);
	ft_init_pthread(&table);
	ft_kill_pthread(&table);
	ft_free_all(&table);
	//ft_print_table(&table); // solo para verificar
	//ft_l();
	return (0);
}
