/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:24:42 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/23 13:15:05 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_pthread_join(pthread_t *tid, t_data *data)
{
	if (pthread_join(*tid, NULL))
		return (error("Error, pthread_join failure", data));
	return (0);
}

int	join_threads(t_data *data)
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	while (++i < data->philos_n && !res)
		res = ft_pthread_join(&(data->philo[i].supervisor), data);
	ft_destroy(data);
	return (res);
}
	/*
	1. philo threads join
	2. Destroy mutexes
	3. clear allocated memory: data & philo structs arrays
	*/
