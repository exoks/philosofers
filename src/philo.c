/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:13:34 by oezzaou           #+#    #+#             */
/*   Updated: 2023/03/06 15:54:40 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "philo.h"

int	main(int ac, char **av)
{
	t_philo		*phs;
	t_time		t;
	int			i;
	struct timeval		t;

	gettimeofday(&t, 0);
	phs = get_philosofers(ac, av, &t);
	if (!phs)
		return (display_usage_menu(), EXIT_FAILURE);
	i = -1;	
	while(++i < 3)
		pthread_create(&phs[i].thread, 0, live_cycle, &phs[i]);
	i = -1;
	while (++i < 3)
		pthread_join(phs[i].thread, 0);
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
