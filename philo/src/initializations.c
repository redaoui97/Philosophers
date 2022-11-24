/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil < rnabil@student.1337.ma >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:49:14 by rnabil            #+#    #+#             */
/*   Updated: 2022/11/24 18:27:51 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int initialize_data(int argc, char **argv, t_data *data)
{
    data->nbr_philos = ft_atoi(argv[1]);
    data->time_to_die = ft_atoi(argv[2]);
    data->time_to_eat = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        data->max_meals = ft_atoi(argv[5]);
    else
        data->max_meals = -1;
    data->philos = initialize_philos(data->nbr_philos);
    return (EXIT_SUCCESS);
}
