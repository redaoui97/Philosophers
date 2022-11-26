/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:21:05 by rnabil            #+#    #+#             */
/*   Updated: 2022/11/26 18:22:51 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*life_cycle(void *philosopher)
{
	t_philo	*philo;
	
	philo = (t_philo*)philosopher;
	while (1)
	{
		pickup_fork(philo->data);
		eat(philo->data);
		think(philo->data);
		sleep(philo->data);
	}
	return (NULL);
}

void	print_action(t_philo *philo, char *action)
{

}

static void	pickup_fork(t_data *data)
{
	pthread_mutex_lock()
}