/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil < rnabil@student.1337.ma >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:31:55 by rnabil            #+#    #+#             */
/*   Updated: 2022/11/28 02:36:26 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	finish(t_philo *philo, char *action)
{
		print_action(philo, action);
		exit(EXIT_SUCCESS);
}

void	monitoring(t_data *data)
{
	t_philo			*philo;

	philo = data->philos;
	while(1)
	{
		/*if (data->max_meals != -1 && philo->meals_eaten >= data->max_meals)
			finish(philo, "has eaten all", data);*/
		if (((get_current_time(data) - philo->last_time_ate)) >= data->time_to_die)
		{
			finish(philo, "has died");
		}
		philo = philo->next_philo;
	}
}