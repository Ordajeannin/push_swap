/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:02:16 by ajeannin          #+#    #+#             */
/*   Updated: 2022/11/21 17:29:30 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **a)
{
	if (already_sort(a) == 1)
		return ;
	if ((*a)->index < (*a)->next->index)
	{
		reverse_rotate(a, 'a');
		if (already_sort(a) == 0)
			swap(a, 'a');
	}
	else if ((*a)->index - (*a)->next->index == 1)
	{
		swap(a, 'a');
		if (already_sort(a) == 0)
			reverse_rotate(a, 'a');
	}
	else
		rotate(a, 'a');
}

void	sort_5(t_stack **a, t_stack **b)
{
	int	i;
	int	size;

	i = 0;
	size = stack_len(a);
	while (i < size)
	{
		if ((*a)->index == 0 || (*a)->index == 1)
			push(a, b, 'b');
		else
			rotate(a, 'a');
		i++;
	}
	sort_3(a);
	if (already_sort(b) == 1)
		swap(b, 'b');
	push(a, b, 'a');
	push(a, b, 'a');
}

void	radix_sort(t_stack **a, t_stack **b)
{
	unsigned int	i;
	int				j;
	int				size;

	i = 0;
	size = stack_len(a);
	while (already_sort(a) == 0 || stack_len(b) != 0)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1u) == 1u)
				rotate(a, 'a');
			else
				push(a, b, 'b');
			j++;
		}
		while (stack_len(b) != 0)
			push(a, b, 'a');
		i++;
	}
}
