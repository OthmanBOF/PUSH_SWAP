/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_moves_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:33:47 by obouftou          #+#    #+#             */
/*   Updated: 2025/01/05 10:46:33 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	rev_rot_a(t_stack **a, int flag)
{
	t_stack	*pre_last;
	t_stack	*tmp;

	if (ft_stacklen(*a) >= 2)
	{
		tmp = last_node((*a));
		pre_last = pre_last_node((*a));
		pre_last->next = NULL;
		tmp->next = *a;
		*a = tmp;
		node_index(a);
		if (!flag)
			return (ft_putstr("rra\n"));
	}
	else
		return ;
}

void	rev_rot_b(t_stack **b, int flag)
{
	t_stack	*pre_last;
	t_stack	*tmp;

	if (ft_stacklen(*b) >= 2)
	{
		tmp = last_node((*b));
		pre_last = pre_last_node((*b));
		pre_last->next = NULL;
		tmp->next = *b;
		*b = tmp;
		node_index(b);
		if (!flag)
			return (ft_putstr("rrb\n"));
	}
	else
		return ;
}

void	rev_rotate_a_b(t_stack **a, t_stack **b, int flag)
{
	rev_rot_a(a, 1);
	rev_rot_b(b, 1);
	if (!flag)
		ft_putstr("rrr\n");
}
