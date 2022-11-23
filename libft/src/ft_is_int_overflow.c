/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int_overflow.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:04:57 by ajeannin          #+#    #+#             */
/*   Updated: 2022/11/21 20:05:10 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_int_overflow(char *str)
{
	long	nb;

	nb = ft_atol(str);
	if (nb < -2147483648l)
		return (1);
	if (nb > 2147483647l)
		return (1);
	if (ft_strlen(str) > 12)
		return (1);
	return (0);
}
