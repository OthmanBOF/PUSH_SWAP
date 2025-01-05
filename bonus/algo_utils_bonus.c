/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:47:24 by obouftou          #+#    #+#             */
/*   Updated: 2025/01/05 16:11:18 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

t_stack	*get_biggest_node(t_stack *node)
{
	int		max_val;
	t_stack	*big_node;

	if (!node)
		return (NULL);
	max_val = INT_MIN;
	while (node)
	{
		if (node->value > max_val)
		{
			max_val = node->value;
			big_node = node;
		}
		node = node->next;
	}
	return (big_node);
}

int	max_val_indx(t_stack *a)
{
	int	max;

	max = a->value;
	while (a)
	{
		if (a->value > max)
			max = a->value;
		a = a->next;
	}
	return (max);
}

int	min_val_indx(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (a)
	{
		if (a->value < tmp->value)
			tmp = a;
		a = a->next;
	}
	return (tmp->i);
}

void	sort_arr(int *res, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len -1)
	{
		j = i + 1;
		while (j < len)
		{
			if (res[i] < res[j])
			{
				tmp = res[i];
				res[i] = res[j];
				res[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	get_median(t_stack **a)
{
	int		len;
	int		mid;
	int		i;
	t_stack	*tmp;
	int		*res;

	i = 0;
	len = ft_stacklen(*a);
	tmp = *a;
	res = malloc(sizeof(int) * len);
	if (!res)
		return (exit(1), 0);
	while (tmp)
	{
		res[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	sort_arr(res, len);
	mid = res[len / 2];
	free(res);
	return (mid);
}
