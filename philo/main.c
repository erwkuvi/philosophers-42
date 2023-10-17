/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:21:17 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/17 17:20:27 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
◦ timestamp_in_ms X has taken a fork ◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died
Replace timestamp_in_ms with the current timestamp in milliseconds
and X with the philosopher number.
*/

/*
even:
time_to_die = time to eat + time to sleep + 10

odd:
time to die = time to eat * 2 + time to sleep + 10

odd sleep(time to eat / 2)
odd start taking fork from right
even start taking frok from left
all philosophers take fork from rightm except for the last one.

valgrind --tool=helgrind ./philo   checks for data races
*/

/*One or more philosophers sit at a round table*/

/* ./philo #of_philos time2die time2eat time2sleep
[#of_times_each_philo_must_eat]*/

/*For 200ms of usleep this machine adds 2.890ms of delay on average
Peak delay: 5.041ms*/

/*Time of last meal = Time of start eating.

if (time since start of last meal > time of death)
	Philosopher dies.*/

/*1. Proposal - Semaphores

*/
// void	*ft_print(t_philo *philo)
// {
// 	// printf("%d %s has taken a fork", philo->philo_n);
// 	return (NULL);
// }

void	philo_init(t_philo *philo, t_data *data)
{
	philo = malloc(sizeof(t_philo));
	philo->data = data;
	philo->id = 0;
	philo->meals_eaten = 0;
	philo->status = THINKING;
	philo->eating = 0;
	philo->last_meal = 0;
	pthread_mutex_init(&(philo->lock), NULL);
	// pthread_mutex_init(&(philo->r_fork), NULL);
	// pthread_mutex_init(&(philo->l_fork), NULL);
}

int	main(int argc, char **argv)
{
	t_data		*data;
	t_philo		*philo;
	pthread_t	tid;

	if (error_handling(argc, argv))
		return (1);
	data_init(data, philo, argv);
	philo_init(philo, data);
	create_threads(philo, data);
	// pthread_create(&tid, NULL, &routine, NULL);
	return (0);
}
