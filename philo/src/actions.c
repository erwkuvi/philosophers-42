/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:27:03 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/25 18:00:20 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_action(int action, t_philo *philo)
{
	long	time;

	time = gettime_in_mms() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->write);
	if (action == DYING && philo->eating == 0)
	{
		printf(RED"%ld\t[%d] died\n"RESET, time, philo->id + 1);
		philo->data->dead_flag = 1;
	}
	if (philo->data->dead_flag == 0)
	{
		if (action == EATING)
			printf(GREEN"%ld\t[%d] is eating\n"RESET, time, philo->id + 1);
		if (action == SLEEPING)
			printf(BLUE"%ld\t[%d] is sleeping\n"RESET, time, philo->id + 1);
		if (action == THINKING)
			printf(YELLOW"%ld\t[%d] is thinking\n"RESET, time, philo->id + 1);
	}
	pthread_mutex_unlock(&philo->data->write);
}

void	philo_thinks(t_philo *philo)
{
	print_action(THINKING, philo);
}

void	philo_sleeps(t_philo *philo)
{
	print_action(SLEEPING, philo);
	ft_usleep_3(philo->data->time2sleep);
}

void	picking_forks(t_philo *philo)
{
	long	time;

	time = gettime_in_mms() - philo->data->start_time;
	pthread_mutex_lock(philo->l_fork);
	printf("%ld\t[%d] has taken a fork\n", time, philo->id + 1);
	pthread_mutex_lock(philo->r_fork);
	printf("%ld\t[%d] has taken a fork\n", time, philo->id + 1);
}

void	philo_eats(t_philo *philo)
{
	picking_forks(philo);
	pthread_mutex_lock(&philo->lock);
	philo->eating = 1;
	philo->time_to_die = gettime_in_mms() + philo->data->time2die;
	print_action(EATING, philo);
	philo->meals_eaten++;
	ft_usleep_3(philo->data->time2eat);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->lock);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}
