/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil < rnabil@student.1337.ma >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:21:05 by rnabil            #+#    #+#             */
/*   Updated: 2022/11/27 21:24:10 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_action(t_philo *philo, char *action)
{
	pthread_mutex_lock(philo->print_lock);
	printf("%lld    %d      %s\n",get_current_time(philo->data), philo->id + 1, action);
	pthread_mutex_unlock(philo->print_lock);
}


void	putdown_fork(t_philo *philo)
{
	if (pthread_mutex_unlock(philo->fork_lock) != 0)
		fatal_error("Failed to unlock mutex!\n");
	if (pthread_mutex_unlock(philo->next_philo->fork_lock) != 0)
		fatal_error("Failed to unlock mutex!\n");
}

void	pickup_fork(t_philo *philo)
{
	if (pthread_mutex_lock(philo->fork_lock) != 0)
		fatal_error("Failed to lock mutex!\n");
	print_action(philo, "has taken a fork");
	if (pthread_mutex_lock(philo->next_philo->fork_lock) != 0)
        fatal_error("Failed to lock mutex!\n");
	print_action(philo, "has taken a fork");
}

void	eat(t_philo *philo)
{
	pickup_fork(philo);
	philo->last_time_ate = get_current_time(philo->data);
	philo->meals_eaten += 1;
	print_action(philo, "is eating");
	usleep(philo->data->time_to_eat * 1000);
	putdown_fork(philo);
}

void	*life_cycle(void *philosopher)
{
	t_philo	*philo;
	
	philo = (t_philo*)philosopher;
	while (1)
	{
		eat(philo);
		print_action(philo, "is sleeping");
		usleep(philo->data->time_to_sleep * 1000);
		print_action(philo, "is thinking");
	}
	return (NULL);
}