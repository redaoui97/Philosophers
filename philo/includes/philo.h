/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil < rnabil@student.1337.ma >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:21:13 by rnabil            #+#    #+#             */
/*   Updated: 2022/11/24 13:29:13 by rnabil           ###   ########.fr       */
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
	t_philo		*first_philo;
	t_philo		*next_philo;
	t_philo		*previous_philo;
} t_philo;

/*Initializations functions*/
int initialize_data(int argc, char **argv, t_data *data);

/*Philosophers utils functions*/

/*Error functions*/
void    fatal_error (char *msg);

/*Utils functions*/
int     ft_strlen(char *str);
char	*ft_strcat(char *str1, char *str2);
int     ft_atoi(const char *str);
#endif