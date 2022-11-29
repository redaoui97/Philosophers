/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil < rnabil@student.1337.ma >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:31:55 by rnabil            #+#    #+#             */
/*   Updated: 2022/11/29 04:32:56 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	finish(t_philo *philo, char *action)
{
		print_action(philo, action, 1);
		exit(EXIT_SUCCESS);
}

static int all_have_eaten(t_data *data)
{
	t_philo *philo;
	int		i;

	i = 0;
	philo = data->philos;
	while (i < data->nbr_philos)
	{
		if (philo->meals_eaten < data->max_meals)
			return (0);
		philo = philo->next_philo;
		i++;
	}
	return (1);
}

void	monitoring(t_data *data)
{
	t_philo			*philo;

	philo = data->philos;
	while(1)
	{
		if (((get_current_time(data) - philo->last_time_ate)) >= data->time_to_die)
		{
			finish(philo, "has died");
			break ;
		}
		if (data->max_meals >= 0)
		{
			if (all_have_eaten(data))
			{
				finish(data->philos, NULL);
				break ;
			}
		}
		philo = philo->next_philo;
	}
}