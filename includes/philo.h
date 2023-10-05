/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:44:05 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/05 18:09:30 by ekuchel          ###   ########.fr       */
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

// ANSI color codes
# define RESET   "\x1B[0m"
# define RED     "\x1B[31m" // starving
# define GREEN   "\x1B[32m"
# define YELLOW  "\x1B[33m" // eating
# define BLUE    "\x1B[34m" // sleeping
# define MAGENTA "\x1B[35m"
# define CYAN    "\x1B[36m"
# define WHITE   "\x1B[37m" // thinking

#endif
