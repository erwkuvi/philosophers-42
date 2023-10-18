/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:27:03 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/18 17:35:48 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	ft_usleep();
	philo->status = SLEEPING;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	ft_usleep();
}

void	create_threads(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->philos_n)
		pthread_create(&(data->thread_id[i]), NULL, philo_routine, NULL);
}


