/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:27:03 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/23 12:37:32 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_thinks(t_philo *philo)
{
	printf(BLUE"%ld "RESET, gettime_in_mms);
	printf(GREEN"%d is thinking\n"RESET, philo->id);
}

void	philo_sleeps(t_philo *philo)
{
	printf(BLUE"%ld "RESET, gettime_in_mms);
	printf(GREEN"%d is sleeping\n"RESET, philo->id);
}

void	philo_eats(t_philo *philo)
{
	//picking up the two forks
	//eating
	//dropping the forks
	//philo_sleeps()
	pthread_mutex_lock(philo->r_fork);
	printf(BLUE"%ld "RESET, gettime_in_mms);
	printf(GREEN"%d has taken a fork\n"RESET, philo->id);
/*--------------------*/
	pthread_mutex_lock(philo->l_fork);
	printf(BLUE"%ld "RESET, gettime_in_mms);
	printf(GREEN"%d has taken a fork\n"RESET, philo->id);
/*--------------------*/
	printf(BLUE"%ld "RESET, gettime_in_mms);
	printf(GREEN"%d is eating\n"RESET, philo->id);
	philo->status = EATING;
	ft_usleep(1);
	philo->status = SLEEPING;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	ft_usleep(1);
}

void	*meal_routine(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	i = -1;
	while (!data->dead_flag)
	{
		pthread_mutex_lock(&data->lock);
		if (data->finished >= data->philos_n)
			data->dead_flag = 1;
		pthread_mutex_unlock(&data->lock);
	}
	return ((void *) 0);
}

int	create_threads(t_data *data)
{
	pthread_t	meals_check;
	int			i;

	if (data->meals_n != -1)
		pthread_create(&meals_check, NULL, meal_routine, (void *) data);
	i = -1;
	while (++i < data->philos_n)
		pthread_create(&(data->thread_id[i]), NULL, philo_routine, NULL);
}


