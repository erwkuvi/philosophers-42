/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekuchel <ekuchel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:58:04 by ekuchel           #+#    #+#             */
/*   Updated: 2023/10/18 18:08:01 by ekuchel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int static	check_max_min_new(long value)
{
	int	size;
	int	max;
	int	min;

	size = sizeof(int) * 8;
	min = -((unsigned int)1 << (size - 1));
	max = (1 << (size - 1)) - 1;
	if (value > max || value < min)
		return (error(RED"Error, values are outside the range\n"RESET, NULL));
	return (0);
}

static int	check_philo_range(char **argv)
{
	int	n_philo;

	n_philo = ft_atoi(argv[1]);
	if (n_philo > MAX_PHILOS)
		return (error(RED"Error, no more than 200 philos\n"RESET, NULL));
	if (argv[5])
	{
		if (ft_atoi(argv[5]) < 0)
			return (error(RED"Error, meals cannot be negative\n"RESET, NULL));
	}
	return (0);
}

static int	check_str_is_digit(char *str)
{
	int	j;

	j = -1;
	while (str[++j])
	{
		if (!ft_isdigit(str[j]))
			return (error(RED"Error, not numerical arguments\n"RESET, NULL));
	}
	return (0);
}

int static	check_integer_value(char **argv)
{
	int		i;
	long	value;

	i = 0;
	while (argv[++i])
	{
		value = ft_atoil(argv[i]);
		if (check_str_is_digit(argv[i]))
			return (1);
		if (check_max_min_new(value))
			return (1);
	}
	i = 0;
	while ((argv[++i]) && i < 5)
	{
		if (ft_atoi(argv[i]) < 1)
		{
			if (!check_str_is_digit(argv[i]))
				return (error(RED"Error, values should be > 0\n"RESET, NULL));
		}
	}
	return (0);
}

int	error_handling(int argc, char **argv)
{
	int	res;
	int	flag;

	res = 0;
	flag = 0;
	if (argc < 5 || argc > 6)
		res = error(RED"Error, wrong number of arguments\n"RESET, NULL);
	if (argv[1])
	{
		res += check_philo_range(argv);
		res += check_integer_value(argv);
	}
	return (res);
}
