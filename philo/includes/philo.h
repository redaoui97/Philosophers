/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:21:13 by rnabil            #+#    #+#             */
/*   Updated: 2022/11/23 20:38:44 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/time.h>

enum state
{
	eating,
	thinking,
	sleeping
};

typedef struct s_data
{
	int		nbr_philos;
	int     time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		max_meals;
	t_philo	*philos;
} t_data;

typedef struct s_philo
{
    int			id;
	enum state	state;
	int			meals_eaten;
	long long	last_time_ate;
	pthread_t	thread_id;
} t_philo;
/*Error functions*/
void    fatal_error (char *msg);

/*Philosophers utils functions*/

/*Utils functions*/
int     ft_strlen(char *str);
char	*ft_strcat(char *str1, char *str2);
int     ft_atoi(const char *str);
#endif