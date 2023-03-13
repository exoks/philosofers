/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:45:59 by oezzaou           #+#    #+#             */
/*   Updated: 2023/03/13 21:21:53 by oezzaou          ###   ########.fr       */
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
//	pthread_mutex_init(p->mutex, 0);
	while(++i)
	{
//		pthread_mutex_lock(p->mutex);
		(p->actions)[((i % 3) == 2) + 2 * ((i % 3) == 0)](args);
//		pthread_mutex_unlock(p->mutex);
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
/*	pthread_mutex_init(p->mutex, 0);
//	printf("philo => %d\nfork -> %d\nnext fork -> %d\n", p->id, p->forks, p->next->forks);
	if (p->next->forks == 1 && p->forks == 1)
	{
		pthread_mutex_lock(p->mutex);
		p->forks += (p->next->forks)--;
		printf("%llu %d has taken a fork\n", get_current_time(p->time->reference_time), p->id);
		pthread_mutex_unlock(p->mutex);
	}
	if (p->forks == 2)
	{
		p->time_of_last_meal = get_current_time(p->time->reference_time);
		printf("%llu %d is eating\n", get_current_time(p->time->reference_time), p->id);
		usleep(p->time->time_to_eat * 1000);
		p->forks -= ++(p->next->forks);
		return (0);
	}*/
//	printf("philo => %d => did not find a fork\n", p->id);
	return (0);
}

void	*start_thinking(void *philo)
{
	t_philo			*p;

	p = (t_philo *) philo;
	printf("%llu %d is thinking\n", get_current_time(p->time->reference_time), p->id);
	while (!(p->forks == 1 && p->next->forks == 1))
	{
		if (get_current_time(p->time->reference_time) - p->time_of_last_meal > p->time->time_to_die + 10)
			exit (printf("%lld  %d dead\n", get_current_time(p->time->reference_time), p->id));
	}
	return (0);
}

void	*start_sleeping(void *philo)
{
	t_philo	*p;

	p = (t_philo *) philo;
	printf("%llu %d is sleeping\n", get_current_time(p->time->reference_time), p->id);
	usleep(p->time->time_to_sleep * 1000);
	return (0);
}

int	start_dinning_philos_simulation(t_philo *phs)
{
	ullint	i;

	i = -1;
	while (++i < phs->time->philos_nbr)
			pthread_create(&phs[i].thread, 0, live_cycle, &phs[i]);
	i = -1;
	while (++i < phs->time->philos_nbr)
		pthread_join(phs[i].thread, 0);
	return (0);
}
