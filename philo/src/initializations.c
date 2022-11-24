/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil < rnabil@student.1337.ma >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:49:14 by rnabil            #+#    #+#             */
/*   Updated: 2022/11/24 16:56:23 by rnabil           ###   ########.fr       */
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
}

t_philo *initialize_philos(int nbr_philos)
{
    int     i;
    t_philo *philo;
    t_philo *first_philo;

    i = 0;
    first_philo = allocate_philo(NULL);
    if (!first_philo)
        fatal_error("Allocation error!\n");
    philo = first_philo;
    while (i < nbr_philos)
    {
        philo->next_philo = allocate_philo(philo);
        philo->id = i;
        philo->meals_eaten = 0;
        i++;
    }
    philo->next_philo = first_philo;
    first_philo->previous_philo = philo;
    return (first_philo);
}

t_philo *allocate_philo(t_philo *previous_philo)
{
    t_philo *new;

    new = (t_philo*)malloc(sizeof(t_philo));
    if (!new)
        fatal_error("Allocation error!\n");
    new->previous_philo = previous_philo;
    return (new);
}