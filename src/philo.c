/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:39:44 by cleguina          #+#    #+#             */
/*   Updated: 2024/02/14 19:44:29 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main(int argc, char **argv)
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
	ft_init_pthread(&table); //iniciar los hilos???
	
	ft_print_table(&table); // solo para verificar
	
	
	return (0);
}