/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:44:05 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/17 17:57:48 by ekuchel          ###   ########.fr       */
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
# define THINKING	3
# define MAX_PHILOS	200

typedef struct s_philo
{
	t_data			*data;
	pthread_t		philo_thread;
	int				id;
	int				meals_eaten;
	int				status;
	int				eating;
	size_t			last_meal;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;

typedef struct s_data
{
	pthread_t		*thread_id;
	int				philos_n;
	int				meals_n;
	int				dead_flag;
	int				finished;
	size_t			time2die;
	size_t			time2eat;
	size_t			time2sleep;
	size_t			start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
	t_philo			*philos;
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
int		ft_atoi(const char *str);
long	ft_atoil(const char *str);
int		ft_isdigit(int c);
void	ft_putstr_fd(char *s, int fd);
long	gettime_in_mms(void);
int		ft_usleep(useconds_t time);

/*------ actions.c ------*/
void	philo_thinks(t_philo *philo);
void	philo_sleeps(t_philo *philo);
void	philo_eats(t_philo *philo);

/*------ error_handle.c ------*/
int		error_handling(int argc, char **argv);

/*------ error.c ------*/
int		error(char *str, t_data *data);
void	clear_data(t_data	*data);
void	ft_exit(t_data *data);

/*------ init.c ------*/
void	data_init(t_data *data, t_philo *philos, char **argv);
void	philo_init(t_philo *philo, t_data *data);

/*------ routine.c ------*/
void	*philo_routine(t_philo	*philo);

#endif
