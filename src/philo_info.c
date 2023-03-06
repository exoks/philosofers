/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:45:59 by oezzaou           #+#    #+#             */
/*   Updated: 2023/03/06 15:51:54 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "philo.h"

void	*live_cycle(void *args)
{
	t_philo	*p = (t_philo *) args;
	int		i;
	pthread_mutex_t	mutex;

	i = p->id - 1;
	pthread_mutex_lock(&mutex);
	while(++i)
		(p->actions)[2 * ((i % 3) == 0) + ((i % 3) == 2)](args);
	pthread_mutex_unlock(&mutex);
	return (0);
}

void	get_actions(void *(*actions[3])(void *))
{
	actions[0] = &start_eating;
	actions[1] = &start_sleeping;
	actions[2] = &start_thinking;
}

void	*start_eating(void *philo)
{
	t_philo *p;

	p = (t_philo *) philo;
	if (p->next->forks == 1 && p->forks == 1)
	{
		p->forks += (p->next->forks)--;
		printf("%dms %d has taken a fork\n", 10, p->id);
	}
	if (p->forks == 2)
		printf("%dms %d is eating\n", 10, p->id);
	else
		exit(printf("Philo %d ===> is dead\n", p->id));
	usleep(p->time->time_to_eat * 1000);
	p->forks -= ++(p->next->forks);
	return (0);
}

void	*start_thinking(void *philo)
{
	t_philo	*p;

	p = (t_philo *) philo;
	printf("%dms %d is thinking\n", 10, p->id);
	sleep(3);
	return (0);
}

void	*start_sleeping(void *philo)
{
	t_philo	*p;

	p = (t_philo *) philo;
	printf("%dms %d is sleeping\n", 10, p->id);
	usleep(p->time->time_to_sleep * 1000);
	return (0);
}

t_philo	*get_philosofers(int ac, char **av, t_time *t)
{
	t_philo	*phs;
	int		phs_nb;
	int		i;

	if (ac != 5)
		return (0);
	phs_nb = ft_atoi(av[1]);
	if (phs_nb < 3 || ft_atoi(av[2]) <= 0
		|| ft_atoi(av[3]) <= 0 || ft_atoi(av[4]) <= 0)
		return (0);
	phs = (t_philo *) malloc(sizeof(t_philo) * ft_atoi(av[1]));
	if (!phs)
		return (0);
	t->time_to_die = ft_atoi(av[2]);
	t->time_to_eat = ft_atoi(av[3]);
	t->time_to_sleep = ft_atoi(av[4]);
	i = -1;
	while (++i < phs_nb)
	{
		phs[i].id = i + 1;
		phs[i].forks = 1;
		phs[i].time = t;
		get_actions(phs[i].actions);
		if (i != phs_nb - 1)
			phs[i].next = &phs[i + 1];
	}
	phs[i - 1].next = &phs[0];
	return (phs);
}
