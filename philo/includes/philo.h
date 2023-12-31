/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:44:05 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/27 12:08:40 by ekuchel          ###   ########.fr       */
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

# define EATING		1
# define SLEEPING	2
# define THINKING	3
# define DYING		4
# define FORKING	5
# define MAX_PHILOS	200

typedef struct s_philo
{
	struct s_data	*data;
	pthread_t		supervisor;
	int				id;
	int				meals_eaten;
	int				status;
	int				eating;
	long			time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;

typedef struct s_data
{
	pthread_t		*tid;
	int				philos_n;
	int				meals_n;
	int				dead_flag;
	int				finished;
	long			time2die;
	long			time2eat;
	long			time2sleep;
	long			start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
	t_philo			*philo;
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
int		ft_usleep_3(size_t milliseconds);

/*------ actions.c ------*/
void	print_action(int action, t_philo *philo);
void	philo_thinks(t_philo *philo);
void	philo_sleeps(t_philo *philo);
void	philo_eats(t_philo *philo);
int		create_threads(t_data *data);

/*------ error_handle.c ------*/
int		error_handling(int argc, char **argv);

/*------ error.c ------*/
int		error(char *str, t_data *data);
void	free_data(t_data	*data);
void	ft_destroy(t_data *data);

/*------ init.c ------*/
int		data_init(t_data *data, char **argv);

/*------ join_destroy.c ------*/
int		join_threads(t_data *data);
int		one_philo(t_data *data);

/*------ routine_threads.c ------*/
void	*p_routine(void	*arg);
void	*meal_routine(void *arg);
void	*one_routine(void *arg);

#endif
