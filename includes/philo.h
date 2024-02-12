/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:40:46 by cleguina          #+#    #+#             */
/*   Updated: 2024/02/12 18:44:47 by cleguina         ###   ########.fr       */
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


# define RESET "\x1B[0m"
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define BLUE "\x1B[34m"
# define MAGENTA "\x1B[35m"
# define CYAN "\x1B[36m"
# define WHITE "\x1B[37m" 
# define BOLD   "\033[1m"

typedef struct s_philo t_philo;


typedef struct s_table
{
	
	long 	philo; //numero de filósofos
	t_philo	*ph; //tipo filosofo
	long	time_life; //tiempo de vida
	long	time_eat; //tiempo de comer
	long	time_sleep; //tiempo de dormir
	long 	n_eat; //numero de veces que debe comer
	int		dead; //muerte
}				t_table;


typedef struct s_philo
{
	long id; //id del filosofo
	t_table *t;
	pthread_mutex_t		*mutex; //mutex para los tenedores
}				t_philo;

void		ft_l(void);
int			ft_strlen(char *str);
long int	ft_atoi(char *str);
void		ft_init_table(t_table *table);
void		ft_check_args(int argc, char **argv, t_table *table);
void		ft_error (char *str);
int			ft_isdigit(int c);
int			ft_check_num(char **str);
void		ft_start_table(t_table *table, t_philo *p);
void		ft_print_table(t_table *table);

#endif