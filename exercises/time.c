/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:31:16 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/13 18:25:00 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo/philo.h"

/*
 int usleep(useconds_t microseconds);

struct timeval {
	time t tv_sec; // seconds from January 1, 1970
	suseconds_t tv_usec; // microseconds
};
// 1 second = 1 000 000 microseconds.
// 1 second = 1 000 milliseconds.
*/

long	gettime_in_mms(struct timeval curr);

long	gettime_in_mms(struct timeval curr)
{
	gettimeofday(&curr, 0);
	return ((curr.tv_sec * (uint64_t)1000) + (curr.tv_usec / 1000));
}

void	example1(struct timeval current)
{
	gettimeofday(&current, 0);
	printf("%ld\tseconds since Jan 1, 1970\n", current.tv_sec);
	printf("%ld\t\tyears since 1970\n", current.tv_sec / 60 / 60 / 24 / 365);
}

void	example2(struct timeval current)
{
	long	og_time;
	long	curr_time;

	og_time = gettime_in_mms(current);
	usleep(10000);
	curr_time = gettime_in_mms(current);
	printf("Transcurred time: %u miliseconds\n", curr_time - og_time);
}

void	example3(struct timeval current)
{
	struct timeval	start_time;
	long			requested_sleep_time;

	requested_sleep_time = 200 * 1000;
	gettimeofday(&start_time, 0);
	usleep(requested_sleep_time);
	gettimeofday(&current, 0);
	printf("Requested time to sleep: %ld\n", requested_sleep_time);
	printf("Actual slept time: %ld\n", (current.tv_sec - start_time.tv_sec)
		* 1000 + (current.tv_usec - start_time.tv_usec));
}

void	print_time(struct timeval startime, struct timeval curr_time)
{
	int	time_stamp;

	gettimeofday(&curr_time, 0);
	time_stamp = ((curr_time.tv_sec - startime.tv_sec) * 1000)
		+ ((curr_time.tv_usec - startime.tv_usec) / 1000);
	printf("%d ms\n", time_stamp);
}

void	example4(struct timeval start_time, int sleep, int i)
{
	struct timeval			curr_time;
	int						j;
	__darwin_useconds_t		microsec;

	microsec = sleep * 1000;
	gettimeofday(&start_time, 0);
	j = 0;
	while (j < i)
	{
		print_time(start_time, curr_time);
		usleep(microsec);
		j++;
	}
}


int	main(void)
{
	struct timeval	current;

	example4(current, 100, 15);
	return (0);
}
