/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:41:59 by obouftou          #+#    #+#             */
/*   Updated: 2025/01/04 21:47:44 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	stack_sorted(t_stack **a)
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

void	first_node(t_stack **a, char **res, int data)
{
	*a = ft_lstnew(data);
	if (!(*a))
		return (ft_free(res), exit(1));
}

void	ft_fill(t_stack **a, char **res)
{
	long	r;
	int		size;
	int		i;
	t_stack	*tmp;

	i = 0;
	size = ft_strlen1(res);
	while (i < size)
	{
		if (ft_atoi(res[i]) > INT_MAX || ft_atoi(res[i]) < INT_MIN)
			return (ft_putstr("Error\n"), ft_free(res), exit(1));
		r = (int)ft_atoi(res[i]);
		if (i == 0)
			first_node(a, res, r);
		else
		{
			tmp = ft_lstnew(r);
			if (!tmp)
				return (free(a), ft_free(res), exit(1));
			ft_lstadd_back(a, tmp);
		}
		i++;
	}
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*p1;
	unsigned const char	*p2;

	if (!dst && !src)
		return (0);
	if (src == dst)
		return (dst);
	p1 = (unsigned char *) dst;
	p2 = (unsigned const char *) src;
	while (n > 0)
	{
		*p1 = *p2;
		p1++;
		p2++;
		n--;
	}
	return (dst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (dstsize > srclen + 1)
		ft_memcpy(dst, src, srclen + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = 0;
	}
	return (srclen);
}
