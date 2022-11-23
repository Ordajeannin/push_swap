/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:14:31 by ajeannin          #+#    #+#             */
/*   Updated: 2022/11/21 20:17:54 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*fill_stack(int ac, char **av)
{
	int		i;
	t_stack	*begin;
	t_stack	*new;
	t_stack	*tmp;

	i = 1;
	begin = malloc(sizeof(t_stack));
	if (!begin)
		return (NULL);
	begin->value = ft_atoi(av[i]);
	begin->index = 0;
	begin->next = NULL;
	tmp = begin;
	while (++i < ac)
	{
		new = malloc(sizeof(t_stack));
		if (!new)
			return (begin);
		new->value = ft_atoi(av[i]);
		new->index = 0;
		new->next = NULL;
		tmp->next = new;
		tmp = new;
	}
	return (begin);
}

static int	check_duplicate(t_stack **stack)
{
	t_stack	*c;
	t_stack	*d;

	c = *stack;
	while (c != NULL)
	{
		d = c->next;
		while (d != NULL)
		{
			if (c->value == d->value)
				return (write(2, "Error\n", 6));
			d = d->next;
		}
		c = c->next;
	}
	return (0);
}

static int	check_arg(int ac, char **av)
{
	int	i;
	int	y;

	y = 1;
	i = 0;
	if (ac == 1)
		return (1);
	while (y < ac)
	{
		i = 0;
		if (av[y][i] == '-')
			i++;
		if (ft_is_int_overflow(av[y]) || !av[y][i] ||
			(av[y][i] == '0' && av[y][i + 1]))
			return (write(2, "Error\n", 6));
		while (av[y][i])
		{
			if (!ft_isdigit(av[y][i]))
				return (write(2, "Error\n", 6));
			i++;
		}
		y++;
	}
	return (0);
}

int	parsing(int ac, char **av, t_stack **a)
{
	t_stack	*first;

	if (check_arg(ac, av))
		return (1);
	first = fill_stack(ac, av);
	if (first == NULL || stack_len(&first) != ac - 1)
	{
		free_stack(&first);
		return (1);
	}
	*a = first;
	if (check_duplicate(a))
	{
		free_stack(a);
		return (1);
	}
	return (0);
}
