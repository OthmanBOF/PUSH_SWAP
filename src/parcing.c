/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:24:56 by obouftou          #+#    #+#             */
/*   Updated: 2025/01/04 21:47:11 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_digit(int x)
{
	if (x >= '0' && x <= '9')
		return (1);
	else
		return (0);
}

int	ft_is_valid_digit(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (!is_digit(args[i][j]))
			{
				if (args[i][j] == '-' || args[i][j] == '+')
				{
					if (is_digit(args[i][j - 1]) || !is_digit(args[i][j + 1]))
						return (0);
				}
				else
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	f_isspace(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if ((args[i][j] >= 9 && args[i][j] <= 13) || args[i][j] == 32)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	parcing(char **av)
{
	int		i;
	char	*tmp;
	int		num;

	num = 0;
	i = 0;
	if (!ft_is_valid_digit(av))
		return (ft_putstr("Error\n"), ft_free(av), exit(1));
	if (!f_isspace(av))
		return (ft_putstr("Error\n"), ft_free(av), exit(1));
	if (duplic_check(av))
		return (ft_putstr("Error\n"), ft_free(av), exit(1));
	while (av[i])
	{
		num = ft_atoi(av[i]);
		tmp = ft_itoa(num);
		if (!tmp)
			return (ft_putstr("Error\n"), ft_free(av), exit(1));
		free(av[i]);
		av[i] = tmp;
		i++;
	}
}
