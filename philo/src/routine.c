/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:20:58 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/25 13:33:08 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*sup_routine(void *arg)
{
	t_philo	*philo;
	long	time;

	philo = (t_philo *) arg;
	time = gettime_in_mms();

	/*Time of last meal = Time of start eating.
	if (time since start of last meal > time of death)
	Philosopher dies.*/
	if (philo->time_to_die > time + philo->data->time2die)
	{
		print_action(DYING, philo);
		philo->data->dead_flag;
	}

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

	philo = (t_philo *) arg;
	philo->time_to_die = gettime_in_mms() + philo->data->time2die;
	if (pthread_create(&(philo->supervisor), NULL, sup_routine, (void *) philo))
		return ((void *) 0);
	int	i = -1;
	while (++i < 3 && !philo->data->dead_flag)
	{
		philo_eats(philo);
		philo_sleeps(philo);
		philo_thinks(philo);
	}
	// pthread_mutex_lock(&philo->data->lock);
	// philo->data->finished++;
	// pthread_mutex_unlock(&philo->data->lock);
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

int	create_threads(t_data *data)
{
	pthread_t	meals_check;
	int			i;

	if (data->meals_n != -1)
		pthread_create(&meals_check, NULL, meal_routine, (void *) data);
	i = -1;
	while (++i < data->philos_n)
	{
		if (pthread_create(&(data->tid[i]), NULL, p_routine, &data->philo[i]))
			return (error("Error, pthread_create failure", data));
	}
	if (data->meals_n != -1)
		pthread_join(meals_check, NULL);
	return (0);
}
