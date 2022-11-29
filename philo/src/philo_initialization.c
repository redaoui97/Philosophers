/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_initialization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:27:29 by rnabil            #+#    #+#             */
/*   Updated: 2022/11/29 18:51:59 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	test_initialized_data(t_philo *philos, int nbr_philos)
{
	int	i;

	printf(" id :     adress     :  next_adress   : previous_adress :  \
		first_adress  | has eaten:\n-----------------------------------\
		----------------------------------------------------\n");
	i = 0;
	while (i < nbr_philos)
	{
		printf(" %d  : %p : %p : %p  : %p | has eaten:%d\n", philos->id,
			philos, philos->next_philo, philos->previous_philo,
			philos->first_philo, philos->meals_eaten);
		philos = philos->next_philo;
		i++;
	}
}

static t_philo	*allocate_philo(t_philo *previous_philo)
{
	t_philo	*new;

	new = (t_philo *)malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	new->previous_philo = previous_philo;
	new->id = -1;
	new->next_philo = NULL;
	new->first_philo = NULL;
	new->meals_eaten = -1;
	return (new);
}

static int	initialize_single_philo(t_philo *philo, int id,
	t_philo *first_philo, t_data *data)
{
	philo->id = id;
	philo->meals_eaten = 0;
	philo->first_philo = first_philo;
	philo->state = idle;
	philo->data = data;
	philo->last_time_ate = 0;
	philo->fork_lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (pthread_mutex_init(philo->fork_lock, NULL))
		return (0);
	philo->print_lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (pthread_mutex_init(philo->print_lock, NULL))
		return (0);
	return (1);
}

void	free_philo(t_philo *philo)
{
	if (philo)
	{
		if (philo->fork_lock)
		{
			pthread_mutex_destroy(philo->fork_lock);
			pthread_mutex_destroy(philo->print_lock);
			free (philo->fork_lock);
			free (philo->print_lock);
		}
		free (philo);
	}
}

t_philo	*initialize_philos(int nbr_philos, t_data *data)
{
	int		i;
	t_philo	*philo;
	t_philo	*first_philo;

	i = 0;
	first_philo = allocate_philo(NULL);
	if (!first_philo)
		return (NULL);
	philo = first_philo;
	while (i < nbr_philos - 1)
	{
		philo->next_philo = allocate_philo(philo);
		if (!initialize_single_philo(philo, i, first_philo, data))
			return (NULL);
		if (philo->next_philo)
			philo = philo->next_philo;
		i++;
	}
	if (!initialize_single_philo(philo, i, first_philo, data))
		return (NULL);
	philo->next_philo = first_philo;
	first_philo->previous_philo = philo;
	return (first_philo);
}
