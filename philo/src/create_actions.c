/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:27:03 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/24 17:59:53 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_action(int action, t_philo *philo)
{
	long	time;

	time = gettime_in_mms() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->lock);
	if (action == DEATH)
	{
		printf(RED"%ld Philo %d died\n"RESET, time, philo->id);
		philo->data->dead_flag = 1;
	}
	if (philo->data->dead_flag == 0)
	{
		if (action == EATING)
			printf(GREEN"%ld Philo %d is eating\n"RESET, time, philo->id);
		if (action == SLEEPING)
			printf(BLUE"%ld Philo %d is sleeping\n"RESET, time, philo->id);
		if (action == THINKING)
			printf(YELLOW"%ld Philo %d is thinking\n"RESET, time, philo->id);
	}
	pthread_mutex_unlock(&philo->data->lock);
}

// void	philo_thinks(t_philo *philo)
// {
// 	printf(BLUE"%ld "RESET, gettime_in_mms);
// 	printf(GREEN"%d is thinking\n"RESET, philo->id);
// }

// void	philo_sleeps(t_philo *philo)
// {
// 	printf(BLUE"%ld "RESET, gettime_in_mms);
// 	printf(GREEN"%d is sleeping\n"RESET, philo->id);
// }

void	picking_forks(t_philo *philo)
{
	long	time;

	time = gettime_in_mms() - philo->data->start_time;
	pthread_mutex_lock(&philo->l_fork);
	printf("%ld Philo %d has taken a fork\n", time, philo->id);
	pthread_mutex_lock(&philo->r_fork);
	printf("%ld Philo %d has taken a fork\n", time, philo->id);
}

void	philo_eats(t_philo *philo)
{
	picking_forks(philo);
	philo->eating = 1;
	print_action(EATING, philo);
	ft_usleep_mms(philo->data->time2eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	ft_usleep(philo->data->time2sleep);
}

int	create_threads(t_data *data)
{
	pthread_t	meals_check;
	int			i;

	if (data->meals_n != -1)
		pthread_create(&meals_check, NULL, meal_routine, (void *) data);
	i = -1;
	while (++i < data->philos_n)
	{
		if (pthread_create(&(data->tid[i]), NULL, p_routine, &data->philo[i]))
			return (error("Error, pthread_create failure", data));
	}
	if (data->meals_n != -1)
		pthread_join(meals_check, NULL);
	return (0);
}
