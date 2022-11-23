/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:01:48 by ajeannin          #+#    #+#             */
/*   Updated: 2022/11/21 20:02:52 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nptr)
{
	long	res;
	long	neg;
	int		i;

	res = 0;
	neg = 1;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (!ft_isdigit(nptr[i]) && nptr[i] != '-' && nptr[i] != '+')
		return (0);
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		res = (res * 10) + (nptr[i] - 48);
		i++;
	}
	return (res * neg);
}
