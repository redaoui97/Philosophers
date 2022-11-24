/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil < rnabil@student.1337.ma >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:35:05 by rnabil            #+#    #+#             */
/*   Updated: 2022/11/24 16:36:28 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
    time_t	magana;
	t_data	data;
    
	(void)argv;
	if (argc != 5 && argc != 6)
		fatal_error ("Invalid arguments: invalid number of arguments\n");
	//handle 0 philos
    //function that initializes data args
	initialize_data(argc, argv, &data);
	return (0);
}