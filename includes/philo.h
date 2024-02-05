/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:40:46 by cleguina          #+#    #+#             */
/*   Updated: 2024/02/05 20:34:36 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
#include <pthread.h>


typedef struct s_philo
{
	int eat_times; //numero de veces que ha comido
	int time_to_die; //tiempo desde la ultima vez q comió	
}					t_philo;

typedef struct s_fork
{
	pthread_mutex_t		*mutex; //mutex para los tenedores
	int					valor; //valor del tenedor
}					t_fork;

typedef struct s_table
{
	
	long 	philo; //numero de filósofos
	t_philo	*ph; //tipo filosofo
	t_fork	*fork; //tipo tenedor
	long	time_life; //tiempo de vida
	long	time_eat; //tiempo de comer
	long	time_sleep; //tiempo de dormir
	long 	n_eat; //numero de veces que debe comer
}				t_table;




void	ft_l(void);
int		ft_strlen(char *str);
long int	ft_atoi(char *str);
void	ft_init_table(t_table **table);
void	ft_check_args(int argc, char **argv, t_table *table);
void ft_error (char *str);

#endif