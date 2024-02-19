/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rutine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:20:43 by cleguina          #+#    #+#             */
/*   Updated: 2024/02/19 21:17:06 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"



void controller (t_table *t)
{

///con un bucle infinito chequeo que han comido y
//que ninguno esté muerto
/* void	controller(void *args)
{
	while (1)
	{
		if (ft_exit_for_eat(t))
			exit(0); // break? // cerrar hilos // free all??????
		if (check_is_died(t))
			exit(0); // break? // cerrar hilos // free all??????
	}
	return (NULL);
}*/
}

/*
int	check_is_died(t_table *t)
{
	int	i;

	i = 0;
	while (i < t->n_philo)
	{
		pthread_mutex_lock(&t->table);
		if (time_start_prog() - t->arr_p[i].last_eat >= t->die_to_time
			&& t->has_eaten == 0)
		{
			pthread_mutex_unlock(&t->table);
			pthread_mutex_lock(&t->table);
			t->is_dead = 1;
			pthread_mutex_unlock(&t->table);
			pthread_mutex_lock(&t->table);
			printf("%ld" RED " %d died\n" RESET, time_start_prog()
				- t->time_curr, t->arr_p[i].index);
			pthread_mutex_unlock(&t->table);
			return (1);
		}
		else
			pthread_mutex_unlock(&t->table);
		i++;
	}
	return (0);
}

*/


int	ft_dead(t_table *t)
{
	pthread_mutex_lock(&t->mtx_table);
	if (t->dead == 1)
	{
		pthread_mutex_unlock(&t->mtx_table);
		return (1);
	}
	else
		pthread_mutex_unlock(&t->mtx_table);
	return (0);
}

void	ft_take_forks(t_philo *ph)
{
	ft_print_action(ph, "take left fork\n");
	ft_print_action(ph, "take right fork\n");
}
void	ft_eating(t_philo *ph)
{
	ft_print_action(ph, "is eating\n");
	ft_usleep(ph->table->time_eat);
	//ft_print_table(ph->table);
	ph->meals--;
	//ft_print_table(ph->table);
}
void	ft_sleeping(t_philo *ph)
{
	ft_print_action(ph, "is sleeping\n");
	ft_usleep(ph->table->time_sleep);
}

void	ft_thinking(t_philo *ph)
{
	ft_print_action(ph, "is thinking\n");
}

void	ft_simulator(t_philo *ph)
{
	ft_take_forks(ph);
	ft_eating(ph);
	ft_thinking(ph);
	ft_sleeping(ph);
}
