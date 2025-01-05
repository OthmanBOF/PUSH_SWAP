/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:07:58 by obouftou          #+#    #+#             */
/*   Updated: 2025/01/05 10:41:09 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	main(int ac, char *av[])
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
		sort(&a, &b);
		ft_lstclear(&a);
	}
	else
		return (1);
}
