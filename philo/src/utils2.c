/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:01:06 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/24 16:43:21 by ekuchel          ###   ########.fr       */
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

void	ft_usleep_mms(long time)
{
	long	mms;

	mms = time * 1000;
	usleep(mms);
}

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	if (s == 0)
// 		return (0);
// 	if (!s[i])
// 		return (0);
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t				i;
// 	unsigned char		*str1;
// 	unsigned char		*str2;

// 	i = 0;
// 	if ((!s1 && !s2) || n == 0)
// 		return (0);
// 	if (!s1 || !s2)
// 		return (1);
// 	str1 = (unsigned char *)s1;
// 	str2 = (unsigned char *)s2;
// 	while ((str1[i] || str2[i]) && i < n)
// 	{
// 		if (str1[i] != str2[i])
// 			return (str1[i] - str2[i]);
// 		i++;
// 	}
// 	return (0);
// }
