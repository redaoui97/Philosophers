/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:35:05 by rnabil            #+#    #+#             */
/*   Updated: 2022/11/29 17:28:29 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argv;
	if (argc == 5 || argc == 6)
	{
		if (initialize_data(argc, argv, &data))
		{
			monitoring(&data);
		}
		else
			return (printf("Error allocating/initializing data\n"), 0);
	}
	destroy_data(&data);
	return (0);
}
