/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:50:51 by cleguina          #+#    #+#             */
/*   Updated: 2024/02/27 20:47:22 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_error_inputs(char *str)
{
	printf(BOLD RED "%s\n" RESET, str);
	printf(GREEN "Use: \n");
	printf("../philo <number_philo> <time_die> <time_eat> <time_sleep> ");
	printf("[opt] <each_time_must_eat_until_finish_the_program>\n\n" RESET);
	exit(1);
}

void	ft_error(char *str)
{
	printf(BOLD RED "%s\n" RESET, str);
	exit(1);
}

void	ft_l(void)
{
	system("leaks philo");
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long int	ft_atoi(char *str)
{
	long int	num;
	long int	sign;

	sign = 1;
	num = 0;
	while (((*str >= 9) && (*str <= 13)) || (*str == 32))
		str++;
	if ((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - 48;
		str++;
	}
	if ((num * sign) > INT_MAX || (num * sign) < INT_MIN)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (sign * num);
}
