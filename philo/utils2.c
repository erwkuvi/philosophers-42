/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:01:06 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/17 17:28:53 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	gettime_in_mms(void)
{
	struct timeval	start_time;

	if (gettimeofday(&start_time, NULL))
		return (error(RED"Error, gettime failed"RESET, NULL));
	return ((start_time.tv_sec * (uint64_t)1000) + (start_time.tv_usec / 1000));
}

int	ft_usleep(useconds_t time)
{
	long	start;

	start = gettime_in_mms();
	while ((gettime_in_mms() - start) < time)
		usleep(time / 10);
	return (0);
}
