/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:40:29 by oezzaou           #+#    #+#             */
/*   Updated: 2023/03/13 15:09:23 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

t_time	*get_actions_time(char **av)
{
	t_time	*time;

	time = malloc(sizeof(t_time));
	if (!time)
		return (0);
	time->philos_nbr = ft_atoi(av[1]);
	time->time_to_eat = ft_atoi(av[2]);
	time->time_to_sleep = ft_atoi(av[3]);
	time->time_to_die = ft_atoi(av[4]);
	if (av[5])
		time->nbr_time_each_philo_eat = ft_atoi(av[5]);
	return (time);
}

t_philo	*get_philosofers(int ac, char **av)
{
	t_philo	*phs;
	int		phs_nb;
	int		i;
	t_time	*time;

	if (!(ac == 5 || ac == 6))
		return (0);
	phs_nb = ft_atoi(av[1]);
	if (phs_nb < 3 || ft_atoi(av[2]) <= 0
		|| ft_atoi(av[3]) <= 0 || ft_atoi(av[4]) <= 0)
		return (0);
	phs = (t_philo *) malloc(sizeof(t_philo) * ft_atoi(av[1]));
	time = get_actions_time(av);
	if (!phs || !time)
		return (0);
	i = -1;
	while (++i < phs_nb)
	{
		phs[i].mutex = malloc(sizeof(pthread_mutex_t));
		if (!phs[i].mutex)
			return (0);
		phs[i].id = i + 1;
		phs[i].forks = 1;
		phs[i].time = time;
		get_actions(phs[i].actions);
		if (i != phs_nb - 1)
			phs[i].next = &phs[i + 1];
	}
	phs[i - 1].next = &phs[0];
	return (phs);
}
