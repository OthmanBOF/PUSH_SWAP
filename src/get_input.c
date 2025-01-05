/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:51:37 by obouftou          #+#    #+#             */
/*   Updated: 2025/01/05 16:37:12 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check(char *av, char *str)
{
	int	x;
	int	checker;

	x = 0;
	checker = 0;
	while (av[x])
	{
		if (av[x] >= '0' && av[x] <= '9')
			checker = 1;
		x++;
	}
	if (checker == 0)
		return (write(2, "Error\n", 6), free(str), exit(1));
}

char	*ft_join_args(char **av, char *str)
{
	int		i;
	char	*tmp;

	i = 1;
	str = ft_strdup("");
	if (str == NULL)
		return (NULL);
	while (av[i])
	{
		check(av[i], str);
		tmp = str;
		str = ft_strjoin(tmp, av[i]);
		free(tmp);
		if (av[i + 1])
		{
			tmp = str;
			str = ft_strjoin(tmp, " ");
			free(tmp);
		}
		if (str == NULL)
			break ;
		i++;
	}
	return (str);
}

char	**get_input(char **av)
{
	char	*str;
	char	**res;

	str = NULL;
	str = ft_join_args(av, str);
	res = ft_split(str, ' ');
	free(str);
	parcing(res);
	return (res);
}

int	ft_strlen1(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
