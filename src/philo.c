/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:39:44 by cleguina          #+#    #+#             */
/*   Updated: 2024/02/06 17:20:02 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


void ft_init_table(t_table **t)
{
	*t = (t_table *)malloc(sizeof(t_table));
	if (*t == NULL)
	{
		ft_error("Error: Malloc failed\n");
		
	}
	(*t)->philo = 0;
	(*t)->ph = NULL;
	(*t)->fork = NULL;
	(*t)->time_life = 0;
	(*t)->time_eat = 0;
	(*t)->time_sleep = 0;
	(*t)->n_eat = 0;

}





int main(int argc, char **argv)
{
	t_table	*table;

	
	table = NULL;
	ft_init_table(&table);
	ft_check_args(argc, argv, table);
	return (0);
	
}