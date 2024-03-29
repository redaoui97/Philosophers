/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil < rnabil@student.1337.ma >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:21:13 by rnabil            #+#    #+#             */
/*   Updated: 2022/11/28 22:56:41 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/time.h>

/*----------------------------------------*/
/*------------Type definition-------------*/
/*----------------------------------------*/

enum state
{
	idle,
	eating,
	thinking,
	sleeping,
	dead
};

typedef struct s_data
{
	int				nbr_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_meals;
	int				all_alive;
	long long		program_start_time;
	struct s_philo	*philos;
} t_data;

typedef struct s_philo
{
    int				id;
	int				meals_eaten;
	enum state		state;
	long long		birth_time;
	long long		last_time_ate;
	pthread_t		thread_id;
	pthread_mutex_t	*fork_lock;
	pthread_mutex_t	*print_lock;
	struct s_data	*data;
	struct s_philo	*first_philo;
	struct s_philo	*next_philo;
	struct s_philo	*previous_philo;
} t_philo;

/*----------------------------------------*/
/*----------Functions prototypes----------*/
/*----------------------------------------*/

/*Initializations functions*/
t_philo		*initialize_philos(int nbr_philos, t_data *data);
void		test_initialized_data(t_philo *philos, int nbr_philos);
int			initialize_data(int argc, char **argv, t_data *data);
int			pthread_initialization(t_data *data);
int			detach_threads(t_data *data);

/*Free data*/
void		free_philo(t_philo *philo);
void		destroy_data(t_data *data);

/*Philosophers action functions*/
void		*life_cycle(void *data);
void		print_action(t_philo *philo, char *action, int finish);

/*Philosophers utils functions*/
long long	get_time(void);
long long	get_current_time(t_data *data);
void		putdown_fork(t_philo *philo);
void		pickup_fork(t_philo *philo);
void		eat(t_philo *philo);

/*Monitoring functions*/
void		monitoring(t_data *data);
void		finish(t_philo *philo, char *action);

/*Error functions*/
void		fatal_error (char *msg);

/*Utils functions*/
int			ft_strlen(char *str);
char		*ft_strcat(char *str1, char *str2);
int			ft_atoi(const char *str);

#endif