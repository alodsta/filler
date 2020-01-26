/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapka                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiklaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:39:20 by bmiklaz           #+#    #+#             */
/*   Updated: 2018/12/25 22:22:40 by bmiklaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_vstrpb(t_string *str, char *s, size_t len)
{
	char		*news;

	if (!str || !s)
		return (0);
	if (str->len + len + 1 < str->cap)
	{
		ft_memmove(str->s + str->len, s, len);
		str->len += len;
		*(str->s + str->len) = 0;
	}
	else
	{
		while (str->len + len + 1 > str->cap)
			str->cap *= 2;
		if (!(news = (char*)ft_memalloc(str->cap)))
			return (57);
		ft_memmove(news, str->s, str->len);
		ft_memmove(news + str->len, s, len);
		str->len += len;
		free(str->s);
		str->s = news;
	}
	return (1);
}
