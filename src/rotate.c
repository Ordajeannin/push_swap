/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:05:40 by ajeannin          #+#    #+#             */
/*   Updated: 2022/11/21 17:44:06 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack, char target)
{
	t_stack	*element;
	t_stack	*current;

	if (stack_len(stack) <= 1)
		return ;
	element = *stack;
	current = *stack;
	*stack = (*stack)->next;
	while (current->next)
		current = current->next;
	current->next = element;
	element->next = NULL;
	if (target == 'a')
		write(1, "ra\n", 3);
	else if (target == 'b')
		write(1, "rb\n", 3);
}

void	rotate_both(t_stack **a, t_stack **b)
{
	if (a == NULL || b == NULL)
		return ;
	rotate(a, 'c');
	rotate(b, 'c');
	write(1, "rr\n", 3);
}
