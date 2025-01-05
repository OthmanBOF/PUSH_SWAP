/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 02:13:23 by obouftou          #+#    #+#             */
/*   Updated: 2025/01/05 16:10:59 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	push_procc(t_stack **a, t_stack **b, int mid, int max)
{
	int	len;

	len = ft_stacklen(*a);
	while (*a && len > 3)
	{
		if ((*a)->value != max)
		{
			push_b(a, b, 0);
			if ((*b)->value >= mid)
				rb_rotate(b, 0);
		}
		else
			ra_rotate(a, 0);
		len = ft_stacklen(*a);
	}
}

void	get_price(t_stack **a)
{
	int		len;
	t_stack	*tmp;

	tmp = *a;
	len = ft_stacklen(tmp);
	while (tmp)
	{
		tmp->price = tmp->i;
		if (tmp->i < len / 2)
			tmp->price = tmp->i;
		else
			tmp->price = len - tmp->i;
		tmp = tmp->next;
	}
}

void	get_target(t_stack *a, t_stack *b)
{
	int		current_max;
	t_stack	*tmp;
	t_stack	*res;

	while (b)
	{
		res = NULL;
		current_max = INT_MAX;
		tmp = a;
		while (tmp)
		{
			if (tmp->value > b->value && tmp->value < current_max)
			{
				current_max = tmp->value;
				res = tmp;
			}
			tmp = tmp->next;
		}
		b->targ = res;
		b->budget = b->price + b->targ->price;
		b = b->next;
	}
}

void	initialized(t_stack **a, t_stack **b)
{
	get_price(b);
	get_price(a);
	get_target(*a, *b);
	best_case(a, b);
}

t_stack	*prices_sales(t_stack **stack)
{	
	int		res;
	t_stack	*tempo;
	t_stack	*tmp;

	tmp = *stack;
	res = INT_MAX;
	tempo = *stack;
	while (tempo)
	{
		if (tempo->budget < res)
		{
			res = tempo->budget;
			tmp = tempo;
		}
		tempo = tempo->next;
	}
	return (tmp);
}
