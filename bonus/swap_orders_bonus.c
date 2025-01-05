/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_oders _bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 22:13:49 by obouftou          #+#    #+#             */
/*   Updated: 2025/01/05 11:41:24 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	sa_swap(t_stack **a, int flag)
{
	int	tmp;

	if (ft_stacklen(*a) <= 1)
		return ;
	tmp = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = tmp;
	tmp = (*a)->i;
	(*a)->i = (*a)->next->i;
	(*a)->next->i = tmp;
	node_index(a);
	if (!flag)
		ft_putstr("sa\n");
}

void	sb_swap(t_stack **b, int flag)
{
	int	tmp;

	if (ft_stacklen(*b) <= 1)
		return ;
	tmp = (*b)->value;
	(*b)->value = (*b)->next->value;
	(*b)->next->value = tmp;
	tmp = (*b)->i;
	(*b)->i = (*b)->next->i;
	(*b)->next->i = tmp;
	node_index(b);
	if (!flag)
		ft_putstr("sb\n");
}

void	ss_swap(t_stack **a, t_stack **b, int flag)
{
	sa_swap(a, 1);
	sb_swap(b, 1);
	if (!flag)
		ft_putstr("ss\n");
}
