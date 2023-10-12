/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:31:16 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/12 19:59:51 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo/philo.h"

/*
struct timeval {
	time t tv_sec; // seconds from January 1, 1970
	suseconds_t tv_usec; // microseconds
};
// 1 second = 1 000 000 microseconds.
// 1 second = 1 000 milliseconds.
*/
void	exam1(struct timeval current)
{
	printf("%ld seconds since 1 Jan, 1970\n", current.tv_sec);
	printf("%ld years since 1970\n", current.tv_sec / 60 / 60 / 24 / 365);
}

unsigned int	gettime(struct timeval curr)
{
	gettimeofday(&curr, 0);
	return ((curr.tv_sec * 1000) + (curr.tv_usec / 1000));
}

int	main(void)
{
	struct timeval	current;
	unsigned int	og_time;
	unsigned int	curr_time;

	og_time = gettime(current);
	usleep(10000);
	curr_time = gettime(current);
	printf("time: %u\n", og_time);
	printf("time: %u\n", curr_time);

	return (0);
}
