/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacerise <sacerise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:08:46 by sacerise          #+#    #+#             */
/*   Updated: 2015/11/24 17:23:09 by sacerise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int i;

	if (n < 0)
	{
		i = n * -1;
		ft_putchar('-');
	}
	else
		i = n;
	if (i < 10)
	{
		ft_putchar(i + 48);
		return ;
	}
	ft_putnbr(i / 10);
	ft_putchar(i % 10 + 48);
}
