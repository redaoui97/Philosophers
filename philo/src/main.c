/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil < rnabil@student.1337.ma >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:35:05 by rnabil            #+#    #+#             */
/*   Updated: 2022/11/24 18:35:50 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	
	(void)argv;
	if (argc != 5 && argc != 6)
		fatal_error ("Invalid arguments: invalid number of arguments\n");
	//handle 0 philos
    //function that initializes data args
	if (!initialize_data(argc, argv, &data) == EXIT_SUCCESS)
		fatal_error("Program failed to initialize data!\n");
	test_initialized_data(data.philos, data.nbr_philos);
	return (0);
}