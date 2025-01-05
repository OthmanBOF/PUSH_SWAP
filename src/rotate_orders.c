/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_orders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:52:29 by obouftou          #+#    #+#             */
/*   Updated: 2025/01/04 21:48:57 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra_rotate(t_stack **a, int flag)
{
	t_stack	*tmp;
	t_stack	*bottom;

	if (ft_stacklen(*a) >= 2)
	{
		tmp = *a;
		*a = (*a)->next;
		bottom = last_node(*a);
		tmp->next = NULL;
		bottom->next = tmp;
		node_index(a);
		if (!flag)
			return (ft_putstr("ra\n"));
	}
	else
		return ;
}

void	rb_rotate(t_stack **b, int flag)
{
	t_stack	*tmp;
	t_stack	*bottom;

	if (ft_stacklen(*b) >= 2)
	{
		tmp = *b;
		*b = (*b)->next;
		bottom = last_node(*b);
		tmp->next = NULL;
		bottom->next = tmp;
		node_index(b);
		if (!flag)
			return (ft_putstr("rb\n"));
	}
	else
		return ;
}

void	rr_rotate(t_stack **a, t_stack **b)
{
	ra_rotate(a, 1);
	rb_rotate(b, 1);
	ft_putstr("rr\n");
}
