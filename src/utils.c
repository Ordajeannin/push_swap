/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:17:28 by ajeannin          #+#    #+#             */
/*   Updated: 2022/11/21 20:30:32 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_index(t_stack **a)
{
	t_stack	*current;
	t_stack	*tmp;

	if (a == NULL)
		return (1);
	current = *a;
	while (current != NULL)
	{
		tmp = *a;
		while (tmp != NULL)
		{
			if (current->value > tmp->value)
				current->index++;
			tmp = tmp->next;
		}
		current = current->next;
	}
	return (0);
}

void	print_stack(t_stack **stack, char target)
{
	t_stack	*tmp;

	if (stack == NULL)
		return ;
	tmp = *stack;
	if (target == 'a')
		write(1, "Stack a :\n", 10);
	else if (target == 'b')
		write(1, "Stack b :\n", 10);
	write(1, "----------\n", 11);
	while (tmp != NULL)
	{
		ft_printf("---> %d    index = %d\n", tmp->value, tmp->index);
		tmp = tmp->next;
	}
	write(1, "----------\n\n", 12);
}

int	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	if (stack == NULL)
		return (0);
	current = *stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = 0;
	return (0);
}

int	already_sort(t_stack **stack)
{
	t_stack	*c;
	t_stack	*d;

	if (stack_len(stack) == 0)
		return (0);
	c = *stack;
	d = c->next;
	while (d != NULL)
	{
		if (c->value > d->value)
			return (0);
		c = c->next;
		d = d->next;
	}
	return (1);
}

int	stack_len(t_stack **stack)
{
	int		i;
	t_stack	*current;

	i = 0;
	if (stack == NULL)
		return (0);
	current = *stack;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}
