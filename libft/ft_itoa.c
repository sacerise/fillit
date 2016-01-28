/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacerise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:15:02 by sacerise          #+#    #+#             */
/*   Updated: 2015/11/26 12:44:41 by sacerise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nblen(int n)
{
	int len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static int		ft_sign(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static int		ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		s;

	len = ft_nblen(n);
	s = ft_sign(n);
	if (!(str = (char *)malloc(sizeof(char) * (len + s + 1))))
		return (NULL);
	else
	{
		str = str + len + s;
		*str = '\0';
		if (n == 0)
			*--str = 48;
		while (n)
		{
			*--str = ft_abs(n % 10) + 48;
			n = n / 10;
		}
		if (s)
			*--str = '-';
	}
	return (str);
}
