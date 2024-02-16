/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:11:46 by cova              #+#    #+#             */
/*   Updated: 2024/02/16 19:26:10 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else if (s1[i] > s2[i])
			return (1);
		else
			return (-1);
	}
	return (0);
}

void ft_print_action(long id, char *str)
{
    if (ft_strcmp(str, "dead") == 0)
        printf( RED "%ld %s" RESET,id, str);
    else if (ft_strcmp(str, "is eating\n") == 0)
        printf( WHITE "%ld %s" RESET,id, str);
    else if (ft_strcmp(str, "is sleeping\n") == 0)
        printf( YELLOW "%ld %s" RESET,id, str);
    else if (ft_strcmp(str, "is thinking\n") == 0)
        printf( CYAN "%ld %s" RESET,id, str);
    else if (ft_strcmp(str, "take left fork\n") == 0)
        printf( GREEN "%ld %s" RESET,id, str);
    else if (ft_strcmp(str, "take right fork\n") == 0)
        printf( BLUE "%ld %s" RESET,id, str);
    else
        printf("%ld %s",id, str);
}
