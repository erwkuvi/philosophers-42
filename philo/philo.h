/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:44:05 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/14 23:27:00 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define DEAD		0
# define EATING		1
# define SLEEPING	2


typedef struct s_philo
{
	int				state;
	pthread_mutex_t	mutex;
	pthread_t		philo_thread;

}	t_philo;

typedef struct s_data
{
	int	philo_n;
	int	time2die;
	int	time2eat;
	int	time2sleep;
	int	meals;
	int	odd;
}	t_data;

// ANSI color codes
# define RESET   "\x1B[0m"
# define RED     "\x1B[31m" // starving
# define GREEN   "\x1B[32m"
# define YELLOW  "\x1B[33m" // eating
# define BLUE    "\x1B[34m" // sleeping
# define MAGENTA "\x1B[35m"
# define CYAN    "\x1B[36m"
# define WHITE   "\x1B[37m" // thinking

/*------ utils.c ------*/
int	ft_atoi(const char *str);
int	ft_isdigit(int c);
/*------ error.c ------*/
int	error_handling(int argc, char **argv);




#endif
