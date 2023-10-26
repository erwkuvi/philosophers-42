/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:20:58 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/26 14:15:36 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*sup_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	while (!philo->data->dead_flag)
	{
		pthread_mutex_lock(&philo->lock);
		if (gettime_in_mms() >= philo->time_to_die && !philo->eating)
			print_action(DYING, philo);
		if (philo->data->meals_n != -1)
		{
			if (philo->meals_eaten == philo->data->meals_n)
			{
				pthread_mutex_lock(&philo->data->lock);
				philo->data->finished++;
				philo->meals_eaten++;
				philo->status = 1;
				pthread_mutex_unlock(&philo->data->lock);
			}
		}
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *) 0);
}

void	*p_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	philo->time_to_die = gettime_in_mms() + philo->data->time2die;
	if (pthread_create(&(philo->supervisor), NULL, sup_routine, (void *) philo))
		return ((void *) 0);
	while (!philo->data->dead_flag && !philo->status)
	{
		philo_eats(philo);
		philo_sleeps(philo);
		philo_thinks(philo);
	}
	pthread_join(philo->supervisor, 0);
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
		pthread_create(&meals_check, NULL, meal_routine, data);
	i = -1;
	while (++i < data->philos_n)
	{
		if (pthread_create(&(data->tid[i]), NULL, p_routine, &data->philo[i]))
			return (error("Error, pthread_create failure\n", data));
	}
	if (data->meals_n != -1)
		pthread_join(meals_check, 0);
	return (0);
}
