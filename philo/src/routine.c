/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:20:58 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/19 21:40:32 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_routine(t_philo	*philo)
{
	while (!philo->data->dead_flag
		|| philo->meals_eaten != philo->data->meals_n)
	{
		philo_thinks(philo);
		philo_eats(philo);
	}

	//while alive
	//eat
	//sleep

	//supervisor_routine();
}


void	*monitor_routine()
{
	/*This thread starts before all philos, just if we
	have the optional parameter*/
	/*Check if philo status is marked as finished
	in that case stop all the threads*/
}

void	*supervisor_routine()
{
	/*check wheter the time passed by the last
	time a philo have eaten is greater or equal to teh time it takes to a philo
	to die from starvation*/

	/*check is a philo should die, but he is eating, he is gonna survive*/

	/*check when the philo reaches the times he must eat
	and mark him as finished*/
}
