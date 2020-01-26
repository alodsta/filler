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

t_string	*ft_vstrpf_char(t_string *v, char c, size_t n)
{
	t_string	*rv;

	if (!(rv = (t_string *)malloc(sizeof(t_string))))
		return (0);
	rv->cap = v->cap + n;
	rv->len = 0;
	if (!(rv->s = ft_memalloc(rv->cap)))
	{
		return_free(rv, 0);
		return (0);
	}
	if (!(ft_vstrpb_char(rv, c, n)))
		return (0);
	ft_memcpy(rv->s + n, v->s, v->len);
	rv->len += v->len;
	ft_vstrdel(&v);
	return (rv);
}
