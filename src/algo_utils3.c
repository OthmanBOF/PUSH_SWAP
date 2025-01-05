/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 23:16:41 by obouftou          #+#    #+#             */
/*   Updated: 2025/01/04 21:47:32 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	node_index(t_stack **a)
{
	int		j;
	t_stack	*tmp;

	j = 0;
	tmp = *a;
	while (tmp)
	{
		tmp->i = j;
		j++;
		tmp = tmp->next;
	}
}

t_stack	*min_node(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (a)
	{
		if (a->value < tmp->value)
			tmp = a;
		a = a->next;
	}
	return (tmp);
}
