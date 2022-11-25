/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil < rnabil@student.1337.ma >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:49:14 by rnabil            #+#    #+#             */
/*   Updated: 2022/11/25 10:46:33 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	initialize_data_attributs(int argc, char **argv, t_data *data)
{
	data->nbr_philos = ft_atoi(argv[1]);
	if (!data->nbr_philos)
		fatal_error("");
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->max_meals = ft_atoi(argv[5]);
	else
		data->max_meals = -1;
}

void	pthread_initialization(t_data *data)
{
	int		i;
	t_philo	*philo;
	
	i = 0;
	data->program_start_time = get_time();
	philo = data->philos;
	while (i < data->nbr_philos)
	{
		if (pthread_create(&(philo->thread_id), NULL, life_cycle, data))
			fatal_error("Thread creation error!\n");
		usleep(100);
		philo = philo->next_philo;
		i++;
	}
}

int initialize_data(int argc, char **argv, t_data *data)
{
	initialize_data_attributs(argc, argv, data);
	data->philos = initialize_philos(data->nbr_philos);
	pthread_initialization(data);
    return (EXIT_SUCCESS);
}

