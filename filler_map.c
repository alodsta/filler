/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiklaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 12:45:23 by bmiklaz           #+#    #+#             */
/*   Updated: 2019/03/03 12:45:23 by bmiklaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zconf.h>
#include "filler.h"

int			create_map(t_map **map, char *buf)
{
	int	i;

	i = 0;
	if (!(*map = (t_map*)ft_memalloc(sizeof(t_map))))
		return (0);
	(*map)->m = ft_atoi((const char *)ft_strchr(buf, ' '));
	(*map)->n = ft_atoi((const char*)ft_strchr(ft_strchr(buf, ' ') + 1, ' '));
	if (!((*map)->tabl = (char**)ft_memalloc((size_t)(*map)->m * 8)))
		return (0);
	while (i < (*map)->m)
		if (!(((*map)->tabl)[i++] = (char*)ft_memalloc((size_t)(*map)->n + 1)))
			return (0);
	i = 0;
	if (!((*map)->lee_m = (int**)malloc((size_t)(*map)->m * 8)))
		return (0);
	while (i < (*map)->m)
	{
		if (!(((*map)->lee_m)[i++] = (int *)malloc((size_t)(*map)->n * 4)))
			return (0);
		ft_memset((*map)->lee_m[i - 1], -1, (size_t)(*map)->n * 4);
	}
	(*map)->piece = 0;
	return (1);
}

void		upd_piece(t_map *map, char *buf, int *err)
{
	int	x;
	int	y;

	x = -1;
	del_vcoord(&(map->piece));
	if (!(map->piece = make_vcoord())
		&& (*err = 1))
		return ;
	push_back_v(map->piece, 0, 0);
	PICX[0] = ft_atoi((const char*)ft_strchr(buf, ' '));
	PICY[0] = ft_atoi((const char*)ft_strchr(ft_strchr(buf, ' ') + 1, ' '));
	while (++x < map->piece->x[0] && (y = -1))
	{
		ft_memdel((void**)&buf);
		if (ft_gnl(0, &buf, 1) == -1)
			return ;
		while (++y < map->piece->y[0])
			if (buf[y] != '.')
				if (!(push_back_v(map->piece, x, y)))
				{
					*err = 1;
					return ;
				}
	}
	ft_memdel((void**)&buf);
}

void		map_backup(t_map map, t_vcoord rep, char p_num)
{
	int	i;

	i = 1;
	while (++i < (int)rep.len)
		if (VXYINMAP == p_num)
			VXYINMAP = '.';
		else
			VXYINMAP = p_num;
}

int			change_map(t_map map, t_vcoord rep, char p_num)
{
	int		i;
	int		f;

	i = 1;
	f = 0;
//	if (rep.x[0] + rep.x[1] > map.m || rep.y[0] + rep.y[1] > map.n ||
//		rep.x[0] + rep.x[1] < 0 || rep.y[0] + rep.y[1] < 0)
//		return (0);
	while (++i < (int)rep.len)
	{
		if (VXYINMAP == p_num)
			++f;
		else if (VXYINMAP != '.')
			return (0);
	}
	if ((i = 1) && f != 1)
		return (0);
	while (++i < (int)rep.len)
		if (VXYINMAP == p_num)
			VXYINMAP = p_num + 32;
		else
			VXYINMAP = p_num;
	return (1);
}

void		change_lee_map(t_map copy, char p_num, t_vcoord *lee_vec)
{
	int			i;
	int			j;

	i = -1;
	while (++i < copy.m && (j = -1))
		while (++j < copy.n)
		{
			if (copy.tabl[i][j] == p_num && !(copy.lee_m[i][j] = 0))
				push_back_v(lee_vec, i, j);
			else if (copy.tabl[i][j] == '.')
				copy.lee_m[i][j] = -1;
			else
				copy.lee_m[i][j] = -2;
		}
}
