/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:06:05 by ajeannin          #+#    #+#             */
/*   Updated: 2022/11/19 19:00:10 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, char target)
{
	t_stack	*element1;
	t_stack	*element2;

	if (stack_len(stack) <= 1)
		return ;
	element1 = *stack;
	element2 = (*stack)->next;
	element1->next = element2->next;
	element2->next = element1;
	*stack = element2;
	if (target == 'a')
		write(1, "sa\n", 3);
	else if (target == 'b')
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	if (a == NULL || b == NULL)
		return ;
	swap(a, 'c');
	swap(b, 'c');
	write(1, "ss\n", 3);
}
