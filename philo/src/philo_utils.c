/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil < rnabil@student.1337.ma >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:37:14 by rnabil            #+#    #+#             */
/*   Updated: 2022/11/26 11:11:04 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

long long	get_current_time(t_data *data)
{
	return ((get_time() - data->program_start_time));
}

void	destroy_data(t_data *data)
{
	t_philo	*philo;
	t_philo	*next;
	int		i;

	philo = data->philos;
	i = 0;
	while (i < data->nbr_philos)
	{
		if (philo->next_philo)
			next = philo->next_philo;
		else
			break ;
		free_philo(philo);
		philo = next;
		i++;
	}
}