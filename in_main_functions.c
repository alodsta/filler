/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_main_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiklaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 12:54:34 by bmiklaz           #+#    #+#             */
/*   Updated: 2019/03/03 12:54:34 by bmiklaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		free_map(t_map **map)
{
	int	i;

	i = -1;
	if (!*map)
		return ;
	while (++i < (*map)->m)
	{
		if ((*map)->tabl && (*map)->tabl[i])
			free((*map)->tabl[i]);
		if ((*map)->lee_m && (*map)->lee_m[i])
			free((*map)->lee_m[i]);
	}
	if ((*map)->tabl)
		free((*map)->tabl);
	if ((*map)->lee_m)
		free((*map)->lee_m);
	if ((*map)->piece)
		del_vcoord(&((*map)->piece));
	ft_memdel((void**)map);
}

void		upd_map(t_map **map, int *err)
{
	int		i;
	char	*buf;

	i = -1;
	if (ft_gnl(0, &buf, 1) <= 0)
		return ;
	if (!*map && !create_map(map, buf) && (*err = 1))
		return ;
	ft_memdel((void**)&buf);
	while (1)
	{
		if (ft_gnl(0, &buf, 1) <= 0)
			return ;
		if (ft_strstr(buf, "000"))
			break ;
		ft_memdel((void**)&buf);
	}
	while (++i < (*map)->m)
	{
		ft_memcpy((*map)->tabl[i], ft_strchr(buf, ' ') + 1, (size_t)(*map)->n);
		ft_memdel((void **)&buf);
		if (!ft_gnl(0, &buf, 1))
			break ;
	}
	upd_piece(*map, buf, err);
}

void		easy_choice(t_map *map, char p_num, int *err)
{
	int			i;
	int			j;
	t_vcoord	*replacement;

	i = -1;
	while (++i < map->m)
	{
		j = 0;
		while (j < map->n && i < map->m)
		{
			replacement = cpy_rep_vec(*(map->piece), i, j++, err, map->m, map->n);
			if (change_map(*map, *replacement, p_num))
			{
				ft_printf("%d %d\n", replacement->x[1], replacement->y[1]);
				del_vcoord(&replacement);
				return ;
			}
			del_vcoord(&replacement);
		}
	}
	*err = 1;
	ft_printf("57 57\n");
}

void		do_magic(t_map *map, int *err, char p)
{
	register int	i;
	register int	j;
	t_vcoord		*rep;
	long			rait;
	t_minrait		m;

	m.n = C;
	m.v = 0;
	i = -1;
	while (++i < map->m && !(j = 0))
		while (j < map->n && (i < map->m))
		{
			if (!(rep = cpy_rep_vec(*(map->piece), i, j++, err, map->m, map->n)))
				return ;
			if ((rait = reit_rep(*map, *rep, p, ME)) == C && del_vcoord(&rep))
				continue ;
			rait -= 2 * reit_rep(*map, *rep, p, HE);
			if (rait < m.n && (m.n = rait))
				del_vcoord(&m.v) && (m.v = rep) &&
						(rep = 0);
			else
				del_vcoord(&rep);
		}
	*err = (m.n == C ? 1 : *err);
	ft_printf("%d %d\n", ANSX, ANSY) && del_vcoord(&m.v);
}

int			check_error(t_map *map, int *err, char p_num)
{
	int		i;
	int		j;
	int		n;

	n = 0;
	p_num = (p_num == 'O' ? 'X' : 'O');
	if (*err == 2)
		return (1);
	i = -1;
	while (++i < map->m && (j = -1))
		while (++j < map->n)
			n += (map->tabl[i][j] == p_num ? 1 : 0);
	*err = (g_score == n ? 2 : *err);
	g_score = n;
	return (*err == 2);
}
