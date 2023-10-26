/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:21:17 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/26 16:28:20 by ekuchel          ###   ########.fr       */
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

// void	printforks(t_data data)
// {
// 	int	i;

// 	i = -1;
// 	while (data.fork[i])
// 		printf("FORKS [%d] here \n", i);
// }

// void	*only_one(void *arg)
// {
// 	long	time;
// 	t_philo	*philo;

// 	philo = (t_philo *) arg;
// 	time = gettime_in_mms() - philo->data->start_time;
// 	printf(CYAN"%ld\t 1 has taken a fork\n"RESET, time);
// 	ft_usleep_3(philo->data->time2die);
// 	printf(RED"%ld\t 1 died\n"RESET, time + philo->data->time2die);
// }

// int	one_philo(t_data *data, char **argv)
// {
// 	data->time2die = ft_atoil(argv[2]);
// 	data->start_time = gettime_in_mms();
// 	data->tid = malloc (sizeof(pthread_t));
// 	if (!data->tid)
// 		return (error("Error, malloc tid array failure", data));
// 	data->philo = malloc(sizeof(t_philo));
// 	if (!data->philo)
// 		return (error("Error, malloc philos array failure", data));
// 	if (pthread_create(&(data->tid[0]), NULL, p_routine, &data->philo[0]))
// 		return (error("Error, pthread_create failure\n", data));
// 	if (pthread_join(data->tid[0], NULL))
// 		return (error("Error, pthread_join failure\n", data));

// 	return (0);
// }



int	main(int argc, char **argv)
{
	t_data	data;

	if (error_handling(argc, argv))
		return (1);
	if (data_init(&data, argv))
		return (1);
	if (data.philos_n == 1)
		return (one_philo(&data));
	if (create_threads(&data))
		return (1);
	if (join_threads(&data))
		return (1);
	return (0);
}
