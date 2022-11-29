/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil < rnabil@student.1337.ma >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:49:14 by rnabil            #+#    #+#             */
/*   Updated: 2022/11/28 21:18:43 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	initialize_data_attributs(int argc, char **argv, t_data *data)
{
	data->nbr_philos = ft_atoi(argv[1]);
	if (!data->nbr_philos)
		return (0);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->max_meals = ft_atoi(argv[5]);
	else
		data->max_meals = -1;
	data->all_alive = 1;
	return(1);
}

int	pthread_initialization(t_data *data)
{
	int		i;
	t_philo	*philo;
	
	i = 0;
	data->program_start_time = get_time();
	philo = data->philos;
	while (i < data->nbr_philos)
	{
		if (pthread_create(&(philo->thread_id), NULL, life_cycle, philo))
			return (0);
		usleep(100);
		philo = philo->next_philo;
		i++;
	}
	return (1);
}

int	detach_threads(t_data *data)
{
	int		i;
	t_philo	*philo;

	philo = data->philos;
	while (i < data->nbr_philos)
	{
		if (pthread_detach(philo->thread_id))
			return (0);
		philo = philo->next_philo;
		i++;
	}
	return (1);
}

int	initialize_data(int argc, char **argv, t_data *data)
{
	if (!initialize_data_attributs(argc, argv, data))
		return (0);
	data->philos = initialize_philos(data->nbr_philos, data);
	if (!data->philos)
		return (0);
	if (!pthread_initialization(data))
		return (0);
	if (!detach_threads(data))
		return (0);
	return (1);
}

