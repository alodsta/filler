/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiklaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 23:49:12 by bmiklaz           #+#    #+#             */
/*   Updated: 2019/02/26 23:49:12 by bmiklaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *str)
{
	char	c;
	size_t	i;
	size_t	len;

	if (!str)
		return (0);
	i = 0;
	len = ft_strlen(str);
	while (i < --len)
	{
		c = str[len];
		str[len] = str[i];
		str[i++] = c;
	}
	return (str);
}
