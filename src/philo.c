/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:13:34 by oezzaou           #+#    #+#             */
/*   Updated: 2023/03/13 15:31:35 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "philo.h"

int	main(int ac, char **av)
{
	t_philo			*phs;
	
	phs = get_philosofers(ac, av);
	if (!phs)
		return (display_usage_menu(), EXIT_FAILURE);
	if (!start_dinning_philos_simulation(phs))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
