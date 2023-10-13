/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:21:17 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/13 18:42:49 by ekuchel          ###   ########.fr       */
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
/* ./philo #of_philos time2die time2eat time2sleep [#of_times_each_philo_must_eat]*/

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

t_data	*data_init()
{
	t_data	*data;
	data = malloc(sizeof(data));

	return (data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

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
