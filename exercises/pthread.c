/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:10:06 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/12 20:38:34 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo/philo.h"

void	*ft_print(void *arg)
{
	int	*value;

	value = (int *)arg;
	printf("Value passed: %d\n", *value);
	return (0);
}

int	main(void)
{
	pthread_t	threads[3];
	int			i;

	i = 0;
	while (i < 3)
	{
		if (pthread_create(&threads[i], 0, ft_print, (void *)&threads[i]))
			return (1);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (pthread_join(threads[i], 0))
			return (1);
		i++;
	}
	return (0);
}
