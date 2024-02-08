/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:39:44 by cleguina          #+#    #+#             */
/*   Updated: 2024/02/08 20:44:20 by cleguina         ###   ########.fr       */
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
	t->dead = 0;
}
void ft_init_philo(t_philo *p, t_table *t)
{
	p->id = 0;
	p->t = t;
}

void	ft_start_table(t_table *table, t_philo *p)
{
	long i;

	i = 0;
	//printf("philo(i): %ld\n", i);
	table->ph = malloc(sizeof(t_philo) * i);
	if (table->ph == NULL)
		ft_error("Error: Malloc failed\n");
	while (i < table->philo)
	{
		table->ph[i] = *p;
		table->ph[i].id = i + 1;
		printf("philo(%ld): %ld\n", i, table->ph[i].id);
		i++;
	}
} 


int main(int argc, char **argv)
{
	t_table	table;
	t_philo	philo;

	ft_init_table(&table);
	ft_check_args(argc, argv, &table);
	ft_start_table(&table, &philo);
	// ft_print_table(&table); // solo para verificar
	// init_forks(&table); //inicializar mutex de tenedores diciendo cuál es cuál left/right
	// init_threads(&table); // Crear hilos y controlador (si alguno ha muerto o si todos han comido(5ªvble)
	return (0);
	
}