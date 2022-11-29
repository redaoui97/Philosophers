/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:49:32 by rnabil            #+#    #+#             */
/*   Updated: 2022/11/29 16:33:59 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*res;

	res = (char *)malloc(sizeof(char) * (ft_strlen(str1)
				+ ft_strlen(str2) + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (str1[j])
		res[i++] = str1[j++];
	j = 0;
	while (str2[j])
		res[i++] = str2[j++];
	res[i] = '\0';
	return (res);
}

static int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\f' || c == '\v'
		|| c == '\r' || c == ' ');
}

int	ft_atoi(const char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			return (-1);
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		res = res * 10 + (str[i++] - 48);
	}
	return (res);
}
