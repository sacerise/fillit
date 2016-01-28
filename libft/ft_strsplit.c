/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacerise <sacerise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:30:57 by sacerise          #+#    #+#             */
/*   Updated: 2015/12/03 18:37:09 by sacerise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_sizew(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		ft_strlen(&s[i]);
		i++;
	}
	return (i);
}

static int			ft_nbw(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	int		size;

	i = 0;
	k = 0;
	j = 0;
	while (s[k])
		k++;
	size = k - 1;
	while (i < size - 1)
	{
		if (s[i] != c && s[i + 1] == c)
			j++;
		i++;
	}
	if (s[i] != c)
		j++;
	return (j);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**n;
	int		i;
	int		size;

	if (!(n = (char **)malloc(sizeof(char *) * ft_nbw(s, c) + 1)))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			size = ft_sizew(s, c);
			n[i++] = ft_strsub(s, 0, size);
			s = s + size;
		}
	}
	n[i] = NULL;
	return (n);
}
