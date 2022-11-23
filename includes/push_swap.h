/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:02:51 by ajeannin          #+#    #+#             */
/*   Updated: 2022/11/23 18:13:33 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft.h"

typedef struct s_stack
{
	int				value;
	unsigned int	index;
	struct s_stack	*next;
}			t_stack;

int			already_sort(t_stack **stack);
//static int	check_arg(int ac, char **av);
//static int	check_duplicate(t_stack **stack);
//static t_stack		*fill_stack(int ac, char **av);
int			free_stack(t_stack **stack);
int			main(int ac, char **av);
int			parsing(int ac, char **av, t_stack **a);
void		print_stack(t_stack **stack, char target);
void		push(t_stack **a, t_stack **b, char target);
void		radix_sort(t_stack **a, t_stack **b);
void		reverse_rotate(t_stack **stack, char target);
void		rev_rotate_both(t_stack **a, t_stack **b);
void		rotate(t_stack **stack, char target);
void		rotate_both(t_stack **a, t_stack **b);
int			set_index(t_stack **a);
void		sort_3(t_stack **a);
void		sort_5(t_stack **a, t_stack **b);
int			stack_len(t_stack **stack);
void		swap(t_stack **stack, char target);
void		ss(t_stack **a, t_stack **b);

#endif
