/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:06:18 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/17 15:41:29 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	data_init(t_data *data, t_philo *philos, char **argv)
{
	t_data	*data;
	int		i;

	data = malloc(sizeof(t_data));
	data->philos_n = ft_atoi(argv[1]);
	data->thread_id[data->philos_n];
	data->dead_flag = 0;
	data->finished = 0;
	data->time2die = ft_atoi(argv[2]);
	data->time2eat = ft_atoi(argv[3]);
	data->time2sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->meals_n = ft_atoi(argv[5]);
	else
		data->meals_n = -1;
	data->start_time = gettime_in_mms();
	i = -1;
	while (++i < data->philos_n)
		pthread_mutex_init(&(data->fork[i]), NULL);
	pthread_mutex_init(&(data->lock), NULL);
	pthread_mutex_init(&(data->write), NULL);
	data->philos = philos;
	return (data);
}
