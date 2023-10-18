/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:24:42 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/18 18:00:10 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_pthread_join(pthread_t *tid, t_data *data)
{
	if (pthread_join(tid, NULL))
	{
		error("Error, pthread_join failure", data);
		return ;
	}
}

void	join_threads(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philos_n)
		ft_pthread_join(&(data->philo[i].philo_thread), data);
	ft_exit(data);
	if (data)
		free(data);
	//philo threads
	//Thread_id

	//Destroy mutexes
	/*clear allocated memory:
	data & philo structs*/

}
