/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:45:59 by oezzaou           #+#    #+#             */
/*   Updated: 2023/03/12 11:59:11 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "philo.h"

void	*live_cycle(void *args)
{
	t_philo			*p;
	int				i;

	p = (t_philo *) args;
	if (p->id == 1)
		p->time->reference_time = get_current_time(0);
	i = p->id - 1;
	pthread_mutex_init(p->mutex, 0);
	while(++i)
	{
		pthread_mutex_lock(p->mutex);
		(p->actions)[((i % 3) == 2) + 2 * ((i % 3) == 0)](args);
		pthread_mutex_unlock(p->mutex);
	}
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
	t_philo 		*p;

	p = (t_philo *) philo;
	printf("philo => %d\nfork -> %d\nnext fork -> %d\n", p->id, p->forks, p->next->forks);
	if (p->next->forks == 1 && p->forks == 1)
	{
		p->forks += (p->next->forks)--;
		printf("%llums %d has taken a fork\n", get_current_time(p->time->reference_time), p->id);
	}
	if (p->forks == 2)
	{
		p->begin = get_current_time(p->time->reference_time);
		printf("%llums %d is eating\n", p->begin, p->id);
		usleep(p->time->time_to_eat * 1000);
		p->forks -= ++(p->next->forks);
		return (0);
	}
	printf("philo => %d => did not find a fork\n", p->id);
	return (0);
}

void	*start_thinking(void *philo)
{
	t_philo			*p;

	p = (t_philo *) philo;
	printf("%llums %d is thinking\n", get_current_time(p->time->reference_time), p->id);
	while (!(p->forks == 1 && p->next->forks == 1))
	{
		if (get_current_time(p->time->reference_time) - p->begin > p->time->time_to_die + 10)
			exit(printf("%lld ms %d dead\n", get_current_time(p->time->reference_time), p->id));
	}
	return (0);
}

void	*start_sleeping(void *philo)
{
	t_philo	*p;

	p = (t_philo *) philo;
	printf("%llums %d is sleeping\n", get_current_time(p->time->reference_time), p->id);
	usleep(p->time->time_to_sleep * 1000);
	return (0);
}

t_philo	*get_philosofers(int ac, char **av)
{
	t_philo	*phs;
	int		phs_nb;
	t_time	*time;
	int		i;

	if (ac != 5)
		return (0);
	phs_nb = ft_atoi(av[1]);
	if (phs_nb < 3 || ft_atoi(av[2]) <= 0
		|| ft_atoi(av[3]) <= 0 || ft_atoi(av[4]) <= 0)
		return (0);
	phs = (t_philo *) malloc(sizeof(t_philo) * ft_atoi(av[1]));
	time = (t_time *) malloc(sizeof(t_time));
	if (!phs || !time)
		return (0);
	time->time_to_die = ft_atoi(av[2]);
	time->time_to_eat = ft_atoi(av[3]);
	time->time_to_sleep = ft_atoi(av[4]);
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

