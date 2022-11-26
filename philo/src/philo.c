/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil < rnabil@student.1337.ma >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:21:05 by rnabil            #+#    #+#             */
/*   Updated: 2022/11/26 11:37:55 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    *life_cycle(void *data)
{
    usleep(1000000);
    printf("%lld\n",get_current_time((t_data*) data));
    (void)data;
    return (NULL);
}