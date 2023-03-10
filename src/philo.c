/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:13:34 by oezzaou           #+#    #+#             */
/*   Updated: 2023/03/10 16:27:31 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "philo.h"

pthread_mutex_t		mutex;

int	main(int ac, char **av)
{
	t_philo			*phs;
//	pthread_mutex_t	mutex;
//	int				i;
	
	phs = get_philosofers(ac, av);
	if (!phs)
		return (display_usage_menu(), EXIT_FAILURE);
	pthread_mutex_init(&mutex, 0);
	phs->time->mutex = &mutex;
	printf("PHILO ID => %d\n", phs[1].id);
	pthread_create(&(phs[1].thread), 0, live_cycle, &phs[1]);
	pthread_join(phs[1].thread, 0);
	pthread_mutex_destroy(&mutex);
		//	i = 0;
//	while (phs->id)
//	{
		//pthread_create(&phs->thread, 0, actions[phs->id - 1], phs);
//		printf("id => %d\n", phs->id);
//		phs = phs->next;
//		sleep(1);
//	}
	return (EXIT_SUCCESS);
}
