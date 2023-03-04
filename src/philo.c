/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:13:34 by oezzaou           #+#    #+#             */
/*   Updated: 2023/03/03 20:23:58 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "philo.h"

int	main(int ac, char **av)
{
	t_philo		*phs;
	int			i;

	phs = get_philosofers(ac, av);
	if (!phs)
		return (printf("%s\n", USAGE), 1);
	i = -1;	
	while(++i < 4)
		pthread_create(&phs[i].thread, 0, live_cycle, &phs[i]);
	i = -1;
	while (++i < 4)
		pthread_join(phs[i].thread, 0);
	//	i = 0;
//	while (phs->id)
//	{
		//pthread_create(&phs->thread, 0, actions[phs->id - 1], phs);
//		printf("id => %d\n", phs->id);
//		phs = phs->next;
//		sleep(1);
//	}
	return (0);
}
