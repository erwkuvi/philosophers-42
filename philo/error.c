/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:58:04 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/16 13:54:58 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_philo_range(char **argv)
{
	int	n_philo;

	n_philo = ft_atoi(argv[1]);
	if (n_philo > 200)
	{
		ft_putstr_fd(RED"Error, no more than 200 philos\n"RESET, 2);
		return (1);
	}
	else if (n_philo < 1)
	{
		ft_putstr_fd(RED"Error, more than 1 philo is required\n"RESET, 2);
		return (1);
	}
	return (0);
}

static int	check_is_arg_digit(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				ft_putstr_fd(RED"Error, not numerical arguments\n"RESET, 2);
				return (1);
			}
		}
	}
	return (0);
}

int static	check_integer_max_value(char **argv)
{
	int	max_int;
	int	i;

	i = 1;
	max_int = (1 << 31) - 1;
	while (argv[i] && i < 5)
	{
		if ((long *)ft_atoi(argv[i]) > max_int || ft_atoi(argv[i]) < 0)
		{
			ft_putstr_fd(RED"Error, values are outside the range\n"RESET, 2);
			return (1);
		}
		else if (ft_atoi(argv[i]) == 0 || ft_atoi(argv[i]) < 0)
		{
			ft_putstr_fd(RED"Error, values should be bigger than 0\n"RESET, 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int static	check_number_arguments(int argc, char *argv)
{
	if (argc < 5 || argc > 6)
	{
		ft_putstr_fd(RED"Error, wrong number of arguments\n"RESET, 2);
		return (1);
	}
	return (0);
}

int	error_handling(int argc, char **argv)
{
	int	res;

	res = 0;
	res += check_number_arguments(argc, argv);
	res += check_is_arg_digit(argv);
	res += check_philo_range(argv);
	res += check_integer_max_value(argv);
	return (res);
}
