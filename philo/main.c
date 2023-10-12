/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:21:17 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/12 20:10:00 by ekuchel          ###   ########.fr       */
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
/*One or more philosophers sit at a round table*/
/* ./philo #of_philos time2die time2eat time2sleep
[#of_times_each_philo_must_eat]*/

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

int	main(int argc, char **argv)
{
	struct timeval	current;
	time_t			seconds;
	suseconds_t		microseconds;

	(void)argv;
	gettimeofday(&current, 0);
	seconds = current.tv_sec;
	microseconds = current.tv_usec;

	// unsigned int	philo_n;

	// philo_n = ft_atoi(argv[1]);
	// if (argc < 5 || argc > 6)
	// {
	// 	perror(RED"Try: .philo arg1 arg2 arg3 arg4");
	// 	exit (1);
	// }
	if (argc <= 6)
	{
		// ft_pthread();
		printf("Current seconds: %ld\n", seconds);
		printf("Current microseconds: %d\n", microseconds);
	}
	return (0);
}
