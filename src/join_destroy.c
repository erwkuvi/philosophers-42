/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:24:42 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/26 16:31:18 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_pthread_join(pthread_t *tid, t_data *data)
{
	if (pthread_join(*tid, NULL))
		return (error("Error, pthread_join failure\n", data));
	return (0);
}

int	join_threads(t_data *data)
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	while (++i < data->philos_n && !res)
		res = ft_pthread_join(&(data->tid[i]), data);
	ft_destroy(data);
	return (res);
}

int	one_philo(t_data *data)
{
	if (pthread_create(&(data->tid[0]), NULL, one_routine, &data->philo[0]))
		return (error("Error, pthread_create failure\n", data));
	if (pthread_join(data->tid[0], NULL))
		return (error("Error, pthread_join failure\n", data));
	if (pthread_mutex_destroy(&(data->fork[0])))
		return (error("Error, mutex_destroy fork failure\n", data));
	if (pthread_mutex_destroy(&(data->philo[0].lock)))
		return (error("Error, mutex_destroy philo->lock failure\n", data));
	if (pthread_mutex_destroy(&(data->lock)))
		return (error("Error, mutex_destroy lock failure\n", data));
	if (pthread_mutex_destroy(&(data->write)))
		return (error("Error, mutex_destroy write failure\n", data));
	free_data(data);
	return (0);
}
	/*
	1. philo threads join
	2. Destroy mutexes
	3. clear allocated memory: data & philo structs arrays
	*/
