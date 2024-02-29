/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:40:46 by cleguina          #+#    #+#             */
/*   Updated: 2024/02/29 19:19:19 by cleguina         ###   ########.fr       */
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
# include <pthread.h>
# define RESET "\x1B[0m"
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define BLUE "\x1B[34m"
# define MAGENTA "\x1B[35m"
# define CYAN "\x1B[36m"
# define WHITE "\x1B[37m" 
# define BOLD   "\033[1m"

typedef struct s_table	t_table;

typedef struct s_philo
{
	long				id; //id del filosofo
	int					meals; //veces que ha comido
	long				last_eat; //tiempo de la ultima comida
	pthread_mutex_t		fork_l; //mutex para el tenedor
	pthread_mutex_t		*fork_r; //mutex para el tenedor
	pthread_t			thread; //hilo del filosofo
	t_table				*table; //mesa
}				t_philo;

/* typedef struct s_fork
{
	int				id;		//id del tenedor
}				t_fork; */

typedef struct s_table
{
	long			philo; //numero de filósofos
	t_philo			*ph; //tipo filosofo
	long			time_start; //tiempo de inicio
	long			time_life; //tiempo de vida
	long			time_eat; //tiempo de comer
	long			time_sleep; //tiempo de dormir
	long			n_eat; //numero de veces que debe comer
	int				food; //check de comidas
	int				dead; // check de muerte
	pthread_t		control;
	pthread_mutex_t	mtx_dead; //mutex para la muerte
	pthread_mutex_t	mtx_meal; //mutex para la comida
	pthread_mutex_t	mtx_print; //mutex para imprimir
	pthread_mutex_t	mtx_table; //mutex para la mesa
}				t_table;

void		ft_l(void);
int			ft_strlen(char *str);
long int	ft_atoi(char *str);
long		ft_init_time(void);
void		ft_init_philo(t_philo *philo);
void		ft_init_mutex(t_table *t);
void		ft_init_table(t_table *t);
void		ft_check_args(int argc, char **argv, t_table *table);
void		ft_error(char *str);
void		ft_error_inputs(char *str);
int			ft_isdigit(int c);
int			ft_check_num(char **str);
void		ft_start_table(t_table *table);
int			ft_dead(t_table *t);
void		ft_rutine(t_table *table, t_philo *ph);
void		ft_eating(t_philo *ph);
void		ft_thinking(t_philo *ph);
void		ft_sleeping(t_philo *ph);
void		ft_simulator(t_philo *ph);
void		ft_init_pthread(t_table	*table);
void		ft_kill_pthread(t_table	*table);
void		ft_print_table(t_table	*table);
void		ft_print_action(t_philo *ph, char *str);
void		ft_free_all(t_table *table);
void		ft_usleep(int ms);
void		*controller(void *args);
int			ft_check_is_died(t_table *t);
void		ft_init_joins(t_table *t);
int			ft_foodie(t_table *t);
int			ft_stop_all(t_table *t);
int			ft_food(t_table *t);
#endif