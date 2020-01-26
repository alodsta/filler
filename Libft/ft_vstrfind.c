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

int	ft_vstrfind(t_string *str, char c)
{
	int		r;
	char	*sstr;

	r = 0;
	if (!str)
		return (-1);
	sstr = str->s;
	while (r < (int)str->len && sstr[r] != c)
		++r;
	return (r < (int)str->len ? r : -1);
}
