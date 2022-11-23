/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:06:05 by ajeannin          #+#    #+#             */
/*   Updated: 2022/11/21 18:31:21 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		len;

	a = NULL;
	b = NULL;
	if (parsing(ac, av, &a) || already_sort(&a) || set_index(&a))
		return (free_stack(&a));
	len = stack_len(&a);
	if (len <= 3)
		sort_3(&a);
	else if (len <= 5)
		sort_5(&a, &b);
	else if (len > 5)
		radix_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
