/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:39:20 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/13 16:12:18 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo/philo.h"

typedef struct s_data
{
	int				num;
	pthread_mutex_t	mutex;
}	t_data;


void	*routine(void *arg)
{
	int		i;
	t_data	*data;

	data = (t_data *) arg;
	i = 0;
	while (i < 1000)
	{
		pthread_mutex_lock(&data->mutex);
		(data->num)++;
		pthread_mutex_unlock(&data->mutex);
		i++;
	}


	return (0);
}

t_data	*data_init(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	pthread_mutex_init(&data->mutex, 0);
	data->num = 0;

	return (data);
}

int	main(void)
{
	pthread_t	thread[2];
	int			i;
	t_data		*data;

	data = data_init();
	i = 0;
	while (i < 2)
	{
		pthread_create(&thread[i], 0, routine, data);
		i++;
	}
	i = 0;
	while (i < 2)
	{
		pthread_join(thread[i], 0);
		i++;
	}
	pthread_mutex_destroy(&data->mutex);
	printf("Value of num: %d\n", data->num);
	free(data);
	return (0);
}
