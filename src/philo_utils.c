/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:00:48 by oezzaou           #+#    #+#             */
/*   Updated: 2023/03/13 17:47:19 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	ft_atoi(char *s)
{
	int		nb;
	int		i;

	nb = 0;
	i = -!(*s == '-' || *s == '+');
	while (s[++i] && s[i] >= '0' && s[i] <= '9')
		nb = nb * 10 + s[i] - '0';
	return (nb * ((*s != '-') - (*s == '-')));
}

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	while(*s)
		len += write(1, s++, 1);
	return (len);
}

ullint	get_current_time(ullint ref_time)
{
	struct timeval	time;

	if (gettimeofday(&time, 0) == 0)
		return (TO_MS(time.tv_sec, time.tv_usec) - ref_time);
	return (FAILURE);
}

void	display_usage_menu()
{
	printf("NAME : \n%50s\n", DEFINITION);
	printf("SYNOPSIS : \n%50s\n\n\n", USAGE);
}
