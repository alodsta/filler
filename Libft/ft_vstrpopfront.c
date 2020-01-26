/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapka                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiklaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:39:20 by bmiklaz           #+#    #+#             */
/*   Updated: 2018/11/21 22:40:18 by bmiklaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_vstrpopfront(t_string *str, size_t ind)
{
	char *r;
	char *news;

	str->len -= ind;
	r = ft_strnew(ind);
	ft_memmove(r, str->s, ind);
	if (!(news = (char*)malloc(str->cap)))
		return (0);
	ft_memmove(news, str->s + ind, str->len);
	free(str->s);
	str->s = news;
	return (r);
}
