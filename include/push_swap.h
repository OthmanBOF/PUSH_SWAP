/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 22:06:56 by obouftou          #+#    #+#             */
/*   Updated: 2025/01/03 20:41:40 by obouftou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				price;
	int				budget;
	int				i;
	int				value;
	struct s_stack	*next;
	struct s_stack	*targ;
}	t_stack;

void	sa_swap(t_stack **a, int flag);
void	sb_swap(t_stack **b, int flag);
void	ss_swap(t_stack **a, t_stack **b);
void	ra_rotate(t_stack **a, int flag);
void	rb_rotate(t_stack **b, int flag);
void	rr_rotate(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);
void	push_a(t_stack **a, t_stack **b);
void	rev_rot_a(t_stack **a, int flag);
void	rev_rot_b(t_stack **b, int flag);
void	rev_rotate_a_b(t_stack **a, t_stack **b);
void	three_case(t_stack **a);
char	**get_input(char **av);
char	*ft_join_args(char **av, char *str);
void	check(char *av, char *str);
int		ft_is_valid_digit(char **args);
int		f_isspace(char **args);
void	parcing(char **av);
int		duplic_check(char **av);
int		nums_sorted(t_stack	**a);
void	sort(t_stack **a, t_stack **b);
void	ft_fill(t_stack **a, char **res);
void	first_node(t_stack **a, char **res, int data);
int		stack_sorted(t_stack **a);
long	ft_atoi(const char *str);
void	ft_putstr(char *s);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlen(const char *str);
void	ft_free(char **av);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen1(char **str);
t_stack	*ft_lstnew(int value);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
int		ft_stacklen(t_stack *stack);
void	*last_node(t_stack *a);
void	node_index(t_stack **a);
void	*pre_last_node(t_stack *a);
void	ft_lstclear(t_stack **stack);
t_stack	*get_biggest_node(t_stack *node);
int		min_val_indx(t_stack *a);
t_stack	*get_biggest_node(t_stack *node);
int		max_val_indx(t_stack *a);
int		min_val_indx(t_stack *a);
int		get_median(t_stack **a);
void	get_price(t_stack **a);
void	initialized(t_stack **a, t_stack **b);
t_stack	*prices_sales(t_stack **stack);
t_stack	*min_node(t_stack *a);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	mid_sort(t_stack **a, t_stack **b);
void	sort_arr(int *res, int len);
void	push_procc(t_stack **a, t_stack **b, int mid, int max);
void	best_case(t_stack **a, t_stack **b);
void	rot_case(t_stack **a, t_stack **b, t_stack *tp);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	sort(t_stack **a, t_stack **b);
char	*ft_itoa(int c);
#endif