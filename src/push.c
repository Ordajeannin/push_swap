/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:05:28 by ajeannin          #+#    #+#             */
/*   Updated: 2022/11/21 17:44:30 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **a, t_stack **b, char target)
{
	t_stack	*element;

	if ((target == 'a' && *b == NULL) || (target == 'b' && *a == NULL))
		return ;
	if (target == 'a')
	{
		element = *b;
		*b = (*b)->next;
		element->next = *a;
		*a = element;
		write(1, "pa\n", 3);
	}
	else if (target == 'b')
	{
		element = *a;
		*a = (*a)->next;
		element->next = *b;
		*b = element;
		write(1, "pb\n", 3);
	}
}
