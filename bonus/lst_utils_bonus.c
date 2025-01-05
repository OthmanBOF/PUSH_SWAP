/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:35:09 by obouftou          #+#    #+#             */
/*   Updated: 2025/01/05 16:10:15 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

t_stack	*ft_lstnew(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!lst || !new)
		return ;
	tmp = *lst;
	if (*lst)
	{
		while (tmp ->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*lst = new;
}

int	ft_stacklen(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	rot_case(t_stack **a, t_stack **b, t_stack *tp)
{
	if (tp->i < ft_stacklen(*b) / 2 && tp->targ->i < ft_stacklen(*a) / 2)
	{
		while (*a != tp->targ && *b != tp)
			rr_rotate(a, b, 0);
	}
	else if (tp->i >= ft_stacklen(*b) / 2 && tp->targ->i >= ft_stacklen(*a) / 2)
	{
		while (*a != tp->targ && *b != tp)
			rev_rotate_a_b(a, b, 0);
	}
	if (*b != tp)
	{
		while (*b != tp)
		{
			if (tp->i < ft_stacklen(*b) / 2)
				rb_rotate(b, 0);
			else
				rev_rot_b(b, 0);
		}
	}
}
