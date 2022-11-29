/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:21:05 by rnabil            #+#    #+#             */
/*   Updated: 2022/11/29 16:31:36 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_action(t_philo *philo, char *action, int finish)
{
	pthread_mutex_lock(philo->print_lock);
	if (action)
		printf("%lld    %d      %s\n", get_current_time(philo->data),
			philo->id + 1, action);
	else
		printf("%lld    all philosophers have eaten",
			get_current_time(philo->data));
	if (!finish)
		pthread_mutex_unlock(philo->print_lock);
}

void	putdown_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork_lock);
	pthread_mutex_unlock(philo->next_philo->fork_lock);
}

void	pickup_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_lock);
	print_action(philo, "has taken a fork", 0);
	pthread_mutex_lock(philo->next_philo->fork_lock);
	print_action(philo, "has taken a fork", 0);
}

void	eat(t_philo *philo)
{
	pickup_fork(philo);
	philo->last_time_ate = get_current_time(philo->data);
	philo->meals_eaten += 1;
	print_action(philo, "is eating", 0);
	usleep(philo->data->time_to_eat * 1000);
	putdown_fork(philo);
}

void	*life_cycle(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	while (1)
	{
		eat(philo);
		print_action(philo, "is sleeping", 0);
		usleep(philo->data->time_to_sleep * 1000);
		print_action(philo, "is thinking", 0);
	}
	return (NULL);
}
