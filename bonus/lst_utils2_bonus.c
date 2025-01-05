/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:36:29 by obouftou          #+#    #+#             */
/*   Updated: 2025/01/05 10:41:00 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	*last_node(t_stack *a)
{
	if (!a)
		return (NULL);
	while (a->next)
	{
		a = a->next;
	}
	return (a);
}

void	*pre_last_node(t_stack *a)
{
	if (!a)
		return (NULL);
	while (a->next && a->next->next)
		a = a->next;
	return (a);
}

void	ft_lstclear(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*node;

	if (!stack)
		return ;
	node = *stack;
	while (node != NULL)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	*stack = NULL;
}

int	nums_sorted(t_stack	**a)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
