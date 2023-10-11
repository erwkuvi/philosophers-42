/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:21:17 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/11 15:49:03 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
◦ timestamp_in_ms X has taken a fork ◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died
Replace timestamp_in_ms with the current timestamp in milliseconds
and X with the philosopher number.
*/

/* ./philo #of_philos time2die time2eat time2sleep
[#of_times_each_philo_must_eat]*/

/*Time of last meal = Time of start eating.

if (time since start of last meal > time of death)
	Philosopher dies.*/

/*1. Proposal - Semaphores

*/

void	*ft_print(void *arg)
{
	(void) arg;
	printf("Test\n");
	return (NULL);
}

void	ft_philo(void *arg)
{
	printf("Value passed is :%d\n", (int *)arg);
}

int	main(int argc, char **argv)
{
	int				val;
	pthread_mutex_t	mutex;
	pthread_t		t1;

	(void)argv;
	val = 1;
	pthread_create(&t1, NULL, ft_print, (void *) &val);
	pthread_mutex_init(&mutex, NULL);
	pthread_join(t1, NULL);

	// if (argc < 5 || argc > 6)
	// {
	// 	perror(RED"Try: .philo arg1 arg2 arg3 arg4");
	// 	exit (1);
	// }
	if (argc <= 6)
		ft_philo();
	pthread_mutex_destroy(&mutex);
	return (0);
}
