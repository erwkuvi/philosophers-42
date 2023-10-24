/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:27:03 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/24 17:03:03 by ekuchel          ###   ########.fr       */
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
		printf("%ld Philo %d died\n", time, philo->id);
		philo->data->dead_flag = 1;
	}
	if (philo->data->dead_flag == 0)
	{
		if (action == EATING)
			printf("%ld Philo %d is eating\n", time, philo->id);
		if (action == SLEEPING)
			printf("%ld Philo %d is sleeping\n", time, philo->id);
		if (action == THINKING)
			printf("%ld Philo %d is thinking\n", time, philo->id);
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
void	take_forks(t_philo *philo_ptr)
{

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
