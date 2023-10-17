/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:05:32 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/17 16:11:35 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(char *str, t_data *data)
{
	ft_putstr_fd(str, 2);
	if (data)
		ft_exit(data);
	return (1);
}

void	ft_exit(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philos_n)
	{
		pthread_mutex_destroy(&data->fork[i]);
		pthread_mutex_destroy(&data->philos[i].lock);
	}
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->lock);
	clear_data(data);
}

void	clear_data(t_data	*data)
{
	if (data->thread_id)
		free(data->thread_id);
	if (data->fork)
		free(data->fork);
	if (data->philos)
		free(data->philos);
}

void	destroy_mutexes(t_philo *philo, t_data *data)
{
	pthread_mutex_destroy(&(philo->lock));
}
