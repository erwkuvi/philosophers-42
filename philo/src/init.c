/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:06:18 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/23 15:44:12 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int static	philo_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philos_n)
	{
		data->philo[i].data = data;
		data->philo[i].id = i;
		data->philo[i].meals_eaten = 0;
		data->philo[i].status = 0;
		data->philo[i].eating = 0;
		data->philo[i].death_time = data->time2die;
		if (pthread_mutex_init(&(data->philo[i].lock), NULL))
			return (error("Error, mutex init lock", data));
		i++;
	}
	data->philo[0].r_fork = &data->fork[0];
	data->philo[0].l_fork = &data->fork[data->philos_n - 1];
	i = 1;
	while (i < data->philos_n)
	{
		data->philo[i].r_fork = &data->fork[i];
		data->philo[i].l_fork = &data->fork[i - 1];
		i++;
	}
	return (0);
}

int static	init_mutex_forks(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philos_n)
	{
		if (pthread_mutex_init(&(data->fork[i]), NULL))
			return (error("Error, pthread_mutex_init fork failure", data));
	}
	if (pthread_mutex_init(&(data->lock), NULL))
		return (error("Error, pthread_mutex_init lock failure", data));
	if (pthread_mutex_init(&(data->write), NULL))
		return (error("Error, pthread_mutex_init write failure", data));
	return (0);
}

int	alloc_stuff(t_data *data)
{
	data->fork = malloc(sizeof(pthread_mutex_t) * data->philos_n);
	if (!data->fork)
		return (error("Error, malloc fork failure", data));
	data->philo = malloc(sizeof(t_philo) * data->philos_n);
	if (!data->philo)
		return (error("Error, malloc philos array failure", data));
	return (0);
}

int	data_init(t_data *data, char **argv)
{
	data->tid = malloc (sizeof(pthread_t) * data->philos_n);
	if (!data->tid)
		return (error("Error, malloc tid failure", data));
	data->philos_n = ft_atoi(argv[1]);
	if (argv[5])
		data->meals_n = ft_atoi(argv[5]);
	else
		data->meals_n = -1;
	data->dead_flag = 0;
	data->finished = 0;
	data->time2die = ft_atoil(argv[2]);
	data->time2eat = ft_atoil(argv[3]);
	data->time2sleep = ft_atoil(argv[4]);
	data->start_time = gettime_in_mms();
	if (alloc_stuff(data))
		return (1);
	if (init_mutex_forks(data))
		return (1);
	if (philo_init(data))
		return (1);
	return (0);
}
