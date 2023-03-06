/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:00:48 by oezzaou           #+#    #+#             */
/*   Updated: 2023/03/06 11:38:55 by oezzaou          ###   ########.fr       */
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

void	display_usage_menu()
{
	printf("NAME : \n%50s\n", DEFINITION);
	printf("SYNOPSIS : \n%50s\n\n\n", USAGE);
}
