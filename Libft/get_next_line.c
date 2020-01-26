/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapka                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiklaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:39:20 by bmiklaz           #+#    #+#             */
/*   Updated: 2018/12/25 23:37:44 by bmiklaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	gnl_del(int ret, t_string **str, char **hl)
{
	if (hl)
		free(*hl);
	if (str)
		ft_vstrdel(str);
	return (ret);
}

int			ft_gnl(const int fd, char **line, int buff_size)
{
	static t_string	*str = 0;
	static int		ind = -1;
	int				f;
	char			*hl;

	if (!(hl = (char*)malloc(buff_size)) || !line)
		return (-1);
	if (!str && !(str = ft_makestr(0, 0, 1)))
		return (gnl_del(-1, &str, &hl));
	f = 0;
	if (ind == -1 && ((!(f = (int)read(fd, hl, buff_size)) &&
					!(str->len)) || (f < 0)))
		return (gnl_del(f < 0 ? -1 : 0, &str, &hl));
	f && ft_vstrpb(str, hl, f);
	free(hl);
	ind = ft_vstrfind(str, '\n');
	if (ind == -1 && f == buff_size)
		return (ft_gnl(fd, line, buff_size));
	*line = ft_vstrpopfront(str, ind == -1 ? str->len : (size_t)ind + 1);
	if (!*line)
		gnl_del(-1, &str, &hl);
	ind == -1 ? 1 : !((*(*line + ind)) = 0) &&
	(ind = ft_vstrfind(str, '\n'));
	return (1);
}
