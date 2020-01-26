/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vstrpb_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiklaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 23:35:06 by bmiklaz           #+#    #+#             */
/*   Updated: 2019/02/26 23:35:06 by bmiklaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_string		*ft_vstrpb_char(t_string *str, char c, size_t n)
{
	char		*news;

	if (!str)
		return (0);
	if (str->len + n >= str->cap)
	{
		while (str->len + n >= str->cap)
			str->cap *= 2;
		if (!(news = ft_memalloc(str->cap)))
			return (0);
		ft_memcpy(news, str->s, str->len);
		while (n--)
			news[str->len++] = c;
		free(str->s);
		str->s = news;
	}
	else
	{
		while (n--)
			str->s[str->len++] = c;
		str->s[str->len] = 0;
	}
	return (str);
}
