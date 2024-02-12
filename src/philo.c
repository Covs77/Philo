/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:39:44 by cleguina          #+#    #+#             */
/*   Updated: 2024/02/12 20:51:20 by cleguina         ###   ########.fr       */
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
	ft_init_pthread(&table);
	
	ft_print_table(&table); // solo para verificar
	//init_forks(&table); //inicializar mutex de tenedores diciendo cuál es cuál left/right
	// init_threads(&table); // Crear hilos y controlador (si alguno ha muerto o si todos han comido(5ªvble)
	return (0);
	
}