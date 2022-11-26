/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil < rnabil@student.1337.ma >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:35:05 by rnabil            #+#    #+#             */
/*   Updated: 2022/11/26 11:38:16 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	
	(void)argv;
	if (argc != 5 && argc != 6)
		fatal_error ("Invalid arguments: invalid number of arguments\n");
	if (!initialize_data(argc, argv, &data) == EXIT_SUCCESS)
		fatal_error("Program failed to initialize data!\n");
	monitoring(&data);
	destroy_data(&data);
	return (0);
}