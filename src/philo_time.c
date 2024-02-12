/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:48:59 by cleguina          #+#    #+#             */
/*   Updated: 2024/02/12 20:52:45 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

ft_init_pthread(t_table *t)
{

}
void	init_threads(t_table *t)
{
	int	i;

	t->time_curr = time_start_prog();
	i = 0;
	while (i < t->n_philo)
	{
		if (0 != pthread_create(&t->arr_p[i].thread, NULL, philo_routine,
				&t->arr_p[i]))
			ft_error("No se pudo crear el hilo\n");
		pthread_mutex_lock(&t->table);
		t->arr_p[i].last_eat = t->time_curr;
		pthread_mutex_unlock(&t->table);
		i++;
	}
	if (0 != pthread_create(&t->control, NULL, controller, t))
		ft_error("No se pudo crear el hilo\n");
	init_joins(t);
}

void	init_joins(t_table *t)
{
	int	i;

	if (0 != pthread_join(t->control, NULL))
		ft_error("Error al esperar al filósofo\n");
	i = 0;
	while (i < t->n_philo)
	{
		if (0 != pthread_join(t->arr_p[i].thread, NULL))
			ft_error("Error al esperar al filósofo\n");
		i++;
	}
}




long	init_time(void)
{
	unsigned long	nbr;
	struct timeval	init;

	if (gettimeofday(&init, NULL) < 0)
		ft_error("no time");
	nbr = (init.tv_sec * 1000) + (init.tv_usec / 1000);
	return (nbr);
}