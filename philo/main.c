/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:21:17 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/14 00:46:52 by ekuchel          ###   ########.fr       */
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
int	error_handling(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc < 5 || argc > 6)
	{
		printf(RED"Error, wrong number of arguments\n"RESET);
		return (1);
	}
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf(RED"Error, not numerical arguments\n"RESET);
				return (1);
			}
		}
	}
	return (0);
}

t_data	*data_init()
{
	t_data	*data;
	data = malloc(sizeof(data));

	return (data);
}

int	main(int argc, char **argv)
{
	// t_data	*data;

	if (error_handling(argc, argv))
		return (1);

	// philo_n = ft_atoi(argv[1]);
	// if (argc < 5 || argc > 6)
	// {
	// 	perror(RED"Try: .philo arg1 arg2 arg3 arg4");
	// 	exit (1);
	// }
	// if (argc <= 6)
	// {
	// 	// ft_pthread();
	// }
	return (0);
}