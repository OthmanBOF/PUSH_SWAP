/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:34:15 by obouftou          #+#    #+#             */
/*   Updated: 2025/01/05 16:12:01 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	checker(char *line, t_stack **a, t_stack **b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa_swap(a, 1);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb_swap(b, 1);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss_swap(a, b, 1);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra_rotate(a, 1);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb_rotate(b, 1);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr_rotate(a, b, 1);
	else if (ft_strcmp(line, "rra\n") == 0)
		rev_rot_a(a, 1);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rev_rot_b(b, 1);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rev_rotate_a_b(a, b, 1);
	else if (ft_strcmp(line, "pa\n") == 0)
		push_a(a, b, 1);
	else if (ft_strcmp(line, "pb\n") == 0)
		push_b(a, b, 1);
}

void	statement(t_stack **a)
{
	if (nums_sorted(a) == 0)
		ft_putstr("ok\n");
	else
		ft_putstr("ko\n");
	ft_lstclear(a);
}

void	gnl_loop(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!line)
			break ;
		checker(line, a, b);
		free(line);
		line = get_next_line(0);
	}
	free(line);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**str;

	a = NULL;
	b = NULL;
	if (ac >= 2)
	{
		str = get_input(av);
		ft_fill(&a, str);
		ft_free(str);
		if (a != NULL && a->next == NULL)
			return (ft_lstclear(&a), 0);
		if (!nums_sorted(&a))
			return (ft_lstclear(&a), 0);
		gnl_loop(&a, &b);
		statement(&a);
	}
	else
		return (0);
}
