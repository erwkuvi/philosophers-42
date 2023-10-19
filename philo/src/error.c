/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:05:32 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/19 22:23:36 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	clear_data(t_data	*data)
{
	if (data->thread_id)
		free(data->thread_id);
	if (data->fork)
		free(data->fork);
	if (data->philo)
		free(data->philo);
}

void	ft_exit(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philos_n)
	{
		if (pthread_mutex_destroy(&(data->fork[i])))
			ft_putstr_fd("Error, mutex_destroy fork failure", 2);
		if (pthread_mutex_destroy(&(data->philo[i].lock)))
			ft_putstr_fd("Error, mutex_destroy philo.lock failure", 2);
	}
	if (pthread_mutex_destroy(&(data->lock)))
		ft_putstr_fd("Error, mutex_destroy lock failure", 2);
	if (pthread_mutex_destroy(&(data->write)))
		ft_putstr_fd("Error, mutex_destroy write failure", 2);
	clear_data(data);
}

int	error(char *str, t_data *data)
{
	ft_putstr_fd(str, 2);
	if (data)
		ft_exit(data);
	return (1);
}
