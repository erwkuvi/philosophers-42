/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:20:58 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/23 16:39:47 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*sup_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;

	pthread_mutex_lock(&philo->lock);
	printf("Printing from sup_routine philo[%d]\n", philo->id);
	pthread_mutex_unlock(&philo->lock);
	/*check wheter the time passed by the last
	time a philo have eaten is greater or equal to the time it takes to a philo
	to die from starvation*/

	/*check is a philo should die, but he is eating, he is gonna survive*/

	/*check when the philo reaches the times he must eat
	and mark him as finished*/
	return ((void *) 0);
}

void	*p_routine(void *arg)
{
	t_philo	*philo;
	long	current;

	philo = (t_philo *) arg;
	current = gettime_in_mms();
	pthread_create(&(philo->supervisor), NULL, sup_routine, (void *) philo);

	while (1)
	{
		pthread_mutex_lock(&philo->lock);
		printf("Get Time: %ld in philo[%d]\n", current - philo->data->start_time, philo->id);
		printf("Printing from  p_routine in philo[%d]\n", philo->id);
		pthread_mutex_unlock(&philo->lock);
		if (philo->data->dead_flag
			|| philo->meals_eaten == philo->data->meals_n)
			break ;
	}

	// while (!philo->data->dead_flag
	// 	|| philo->meals_eaten < philo->data->meals_n)
	// }
	// {
	//while alive
	//eat
	//sleep

	pthread_join(philo->supervisor, NULL);
	return ((void *) 0);
}


void	*meal_routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (!data->dead_flag)
	{
		pthread_mutex_lock(&data->lock);
		if (data->finished >= data->philos_n)
			data->dead_flag = 1;
		pthread_mutex_unlock(&data->lock);
	}
	return ((void *) 0);
}

