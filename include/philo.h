/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:29:30 by oezzaou           #+#    #+#             */
/*   Updated: 2023/03/13 15:23:02 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

//###############################
//#            MENU             #
//###############################
# define USAGE "./philo [number_of_philosofers] [time_to_die] [time_to_eat] [time_to_sleep]"
# define DEFINITION "Start simulation of dinning philosofer problem\n"

//###############################
//#            STATUS           #
//###############################
# define EAT "eating"
# define THINK "THINKING"
# define SLEEP "SLEEPING"
# define DIE "DIYING"
# define FAILURE 1
# define SUCCESS 0
# define TO_MS(A, B) (A * 1000) + (B / 1000)

typedef unsigned long long int ullint;

typedef struct t_time
{
	ullint			philos_nbr;
	ullint			time_to_eat;
	ullint			time_to_die;
	ullint			time_to_sleep;
	ullint			nbr_time_each_philo_eat;
	ullint			reference_time;
}					t_time;

typedef struct s_philo
{
	int				id;
	int				forks;
	t_time			*time;
	void 			*(*actions[3])(void *);
	ullint			time_of_last_meal;
	pthread_t		thread;
	pthread_mutex_t	*mutex;
	struct s_philo	*next;
}					t_philo;

	/******** PHILO_INFO *********/
t_philo	*get_philosofers(int ac, char **av);

	/********** ACTIONS **********/
int		start_dinning_philos_simulation(t_philo *phs);
void	*live_cycle(void *args);
void	get_actions(void *(*actions[3])(void *));
void	*start_eating(void *philo);
void	*start_thinking(void *philo);
void	*start_sleeping(void *philo);

	/*********** Utils ***********/
int		ft_atoi(char *s);
ullint	get_current_time(ullint	ref_time);
void	display_usage_menu(void);

#endif
