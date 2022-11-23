/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:05:50 by ajeannin          #+#    #+#             */
/*   Updated: 2022/11/21 17:21:42 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack, char target)
{
	t_stack	*element;
	t_stack	*current;

	if (stack_len(stack) < 1)
		return ;
	current = *stack;
	while (current->next->next != NULL)
		current = current->next;
	element = current->next;
	element->next = *stack;
	*stack = element;
	current->next = NULL;
	if (target == 'a')
		write(1, "rra\n", 4);
	else if (target == 'b')
		write(1, "rrb\n", 4);
}

void	rev_rotate_both(t_stack **a, t_stack **b)
{
	if (a == NULL || b == NULL)
		return ;
	reverse_rotate(a, 'c');
	reverse_rotate(b, 'c');
	write(1, "rrr\n", 4);
}
