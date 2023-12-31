/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:05:32 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/27 13:50:24 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_data(t_data	*data)
{
	int	i;

	i = -1;
	if (data->tid)
		free(data->tid);
	if (data->fork)
		free(data->fork);
	if (data->philo)
		free(data->philo);
}

void	ft_destroy(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philos_n)
	{
		if (pthread_mutex_destroy(&(data->fork[i])))
			ft_putstr_fd("Error, mutex_destroy fork failure\n", 2);
		if (pthread_mutex_destroy(&(data->philo[i].lock)))
			ft_putstr_fd("Error, mutex_destroy philo->lock failure\n", 2);
	}
	if (pthread_mutex_destroy(&(data->lock)))
		ft_putstr_fd("Error, mutex_destroy lock failure\n", 2);
	if (pthread_mutex_destroy(&(data->write)))
		ft_putstr_fd("Error, mutex_destroy write failure\n", 2);
	free_data(data);
}

int	error(char *str, t_data *data)
{
	ft_putstr_fd(str, 2);
	if (data)
		ft_destroy(data);
	return (1);
}
