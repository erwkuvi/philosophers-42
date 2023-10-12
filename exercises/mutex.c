/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:39:20 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/12 20:48:26 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo/philo.h"



void	*routine(void *arg)
{
	pthread_mutex_lock(arg);

	pthread_mutex_unlock(arg);
	return (0);
}

int	main(void)
{
	pthread_t		t1;
	pthread_mutex_t	mtx1;

	pthread_mutex_init(&mtx1, 0);
	pthread_create(&t1, 0, routine, &mtx1);
	pthread_mutex_destroy(&mtx1);

	return (0);
}
