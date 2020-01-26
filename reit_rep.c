/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reit_rep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiklaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 20:43:29 by bmiklaz           #+#    #+#             */
/*   Updated: 2019/03/14 23:11:35 by bmiklaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	lee_pars4(t_map *map, t_vcoord *lee_vec)
{
	register int		n[9];
	register int		i;
	register int		j;

	n[0] = -1;
	n[1] = 0;
	n[2] = 1;
	n[5] = map->m;
	n[6] = map->n;
	while (lee_vec->len && (i = -1))
	{
		n[3] = lee_vec->x[0];
		n[4] = lee_vec->y[0];
		while (++i < 3 && (j = -1))
			while (++j < 3)
			{
                n[7] = n[3] + n[i];
                n[8] = n[4] + n[j];
                n[7] = n[7] == -1 ? n[5] - 1 : n[7] % n[5];
			    n[8] = n[8] == -1 ? n[6] - 1 : n[8] % n[6];
				if (LM(n[7], n[8]) == -1 && (LM(n[7], n[8]) = LM(n[3], n[4]) + 1))
					push_back_v(lee_vec, (n[7]), (n[8]));
			}
		pop_front_v(lee_vec);
	}
	del_vcoord(&lee_vec);
}

long	find_max2(t_map map)
{
	long	r;
	int		i;
	int		j;

	r = 0;
	i = -1;
	while (++i < map.m && (j = -1))
		while (++j < map.n)
			if (map.lee_m[i][j] != -2)
				r += (map.lee_m[i][j] == -1 ? map.m + map.n * 2 :
						map.lee_m[i][j]);
	return (r);
}

long	psevdo_lee(t_map copy, char p_num)
{
	t_vcoord	*lee_vec;
	long		r;

	pop_front_v(lee_vec = make_vcoord());
	change_lee_map(copy, p_num, lee_vec);
	lee_pars4(&copy, lee_vec);
	r = find_max2(copy);
	return (r);
}

long	reit_rep(t_map map, t_vcoord rep, char p_num, int f)
{
	long	r;

	if (!change_map(map, rep, p_num))
		return (C);
	if ((r = psevdo_lee(map, f == 2 ? 'X' : 'O')) == -1)
	{
		map_backup(map, rep, p_num);
		return (C);
	}
	map_backup(map, rep, p_num);
	return (r);
}
