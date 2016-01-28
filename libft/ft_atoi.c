/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacerise <sacerise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:07:40 by sacerise          #+#    #+#             */
/*   Updated: 2015/12/03 18:19:55 by sacerise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t nb;
	size_t s;

	nb = 0;
	s = 0;
	while (*str == ' ' || *str == '\n' || *str == '\v' \
		|| *str == '\r' || *str == '\t' || *str == '\f')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		s = 1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		nb = ((nb * 10) - (*str - 48));
		str++;
	}
	if (!s)
		nb = -nb;
	return (nb);
}
