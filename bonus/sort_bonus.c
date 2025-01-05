/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:30:26 by obouftou          #+#    #+#             */
/*   Updated: 2025/01/05 15:25:59 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	three_case(t_stack **a)
{
	t_stack	*big_node;

	big_node = get_biggest_node(*a);
	if (*a == big_node)
		ra_rotate(a, 0);
	else if ((*a)->next == big_node)
		rev_rot_a(a, 0);
	if ((*a)->value > (*a)->next->value)
		sa_swap(a, 0);
}

void	mid_sort(t_stack **a, t_stack **b)
{
	int	i;
	int	len;
	int	min_indx;

	len = ft_stacklen(*a);
	node_index(a);
	i = len;
	while (i-- > 3)
	{
		min_indx = min_val_indx(*a);
		while (min_indx != 0)
		{
			if (min_indx < len / 2)
				ra_rotate(a, 0);
			else
				rev_rot_a(a, 0);
			min_indx = min_val_indx(*a);
		}
		push_b(a, b, 0);
	}
	if (stack_sorted(a) > 0)
		three_case(a);
	push_a(a, b, 0);
	push_a(a, b, 0);
}

void	best_case(t_stack **a, t_stack **b)
{
	t_stack	*tp;

	tp = prices_sales(b);
	rot_case(a, b, tp);
	if (*a != tp->targ)
	{
		while (*a != tp->targ)
		{
			if (tp->targ->i < ft_stacklen(*a) / 2)
				ra_rotate(a, 0);
			else
				rev_rot_a(a, 0);
		}
	}
	push_a(a, b, 0);
}

void	large_sort(t_stack **a, t_stack **b)
{
	int		mid;
	int		max;
	t_stack	*least;

	mid = get_median(a);
	max = max_val_indx(*a);
	push_procc(a, b, mid, max);
	three_case(a);
	node_index(a);
	node_index(b);
	while (ft_stacklen(*b) != 0)
		initialized(a, b);
	least = min_node(*a);
	while (least->i != 0)
	{
		if (least->i < ft_stacklen(*a) / 2)
			ra_rotate(a, 0);
		else
			rev_rot_a(a, 0);
	}
}

void	sort(t_stack **a, t_stack **b)
{
	int	len;

	len = ft_stacklen(*a);
	if (len == 2)
		sa_swap(a, 0);
	if (len == 3)
		three_case(a);
	if (len == 5 || len == 4)
		mid_sort(a, b);
	if (len >= 6)
		large_sort(a, b);
}
