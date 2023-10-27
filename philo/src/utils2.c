/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:01:06 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/27 11:57:44 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
/*
 int usleep(useconds_t microseconds);

struct timeval {
	time t tv_sec; // seconds from January 1, 1970
	suseconds_t tv_usec; // microseconds
};
// 1 second = 1 000 000 microseconds.
// 1 second = 1 000 milliseconds.
*/
long	gettime_in_mms(void)
{
	struct timeval	start_time;

	if (gettimeofday(&start_time, NULL))
		return (error(RED"Error, gettime failed"RESET, NULL));
	return ((start_time.tv_sec * (uint64_t)1000) + (start_time.tv_usec / 1000));
}

int	ft_usleep_3(size_t milliseconds)
{
	size_t	start;

	start = gettime_in_mms();
	while ((gettime_in_mms() - start) < milliseconds)
		usleep(500);
	return (0);
}
