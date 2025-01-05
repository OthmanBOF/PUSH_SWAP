/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplic_check_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:21:52 by obouftou          #+#    #+#             */
/*   Updated: 2025/01/05 10:40:12 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	duplic_check(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
