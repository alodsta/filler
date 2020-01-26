/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_vectors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiklaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 12:47:49 by bmiklaz           #+#    #+#             */
/*   Updated: 2019/03/03 12:47:49 by bmiklaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			push_back_v(t_vcoord *v, int x, int y)
{
	int	*rx;
	int	*ry;

	if (v->cap - v->len * 4 - (v->x - v->free_p_x) * 4 >= 4)
	{
		v->x[v->len] = x;
		v->y[v->len++] = y;
	}
	else
	{
		v->cap *= 2;
		if (!(rx = (int*)malloc(v->cap)) || !ft_memcpy(rx, v->x, v->len * 4))
			return (0);
		if (!(ry = (int*)malloc(v->cap)) || !ft_memcpy(ry, v->y, v->len * 4))
			return (0);
		rx[v->len] = x;
		ry[v->len++] = y;
		free(v->free_p_x);
		free(v->free_p_y);
		v->x = rx;
		v->y = ry;
		v->free_p_x = rx;
		v->free_p_y = ry;
	}
	return (1);
}

t_vcoord	*make_vcoord(void)
{
	t_vcoord	*v;

	if (!(v = (t_vcoord*)ft_memalloc(sizeof(t_vcoord))))
		return (0);
	v->cap = 8;
	v->len = 1;
	v->x = 0;
	v->y = 0;
	if (!(v->x = (int*)malloc(8)))
		return (0);
	v->free_p_x = v->x;
	v->x[0] = 0;
	if (!(v->y = (int*)malloc(8)))
		return (0);
	v->free_p_y = v->y;
	v->y[0] = 0;
	return (v);
}

void		pop_front_v(t_vcoord *v)
{
	--(v->len);
	(v->x)++;
	(v->y)++;
}

int			del_vcoord(t_vcoord **v)
{
	if (*v)
	{
		if ((*v)->free_p_x)
			free((*v)->free_p_x);
		(*v)->free_p_x = 0;
		if ((*v)->free_p_y)
			free((*v)->free_p_y);
		(*v)->free_p_y = 0;
		free(*v);
		*v = 0;
	}
	return (1);
}

t_vcoord	*cpy_rep_vec(t_vcoord v, int x, int y, int *err, int m, int n)
{
	t_vcoord	*new_v;
	unsigned int			i;

	i = 0;
	if (!(new_v = make_vcoord()))
	{
		*err = 1;
		return (0);
	}
	new_v->x[0] = v.x[0];
	new_v->y[0] = v.y[0];
	while (++i < v.len)
		if (!(push_back_v(new_v, v.x[i] + x >= 0 ? (v.x[i] + x) % m : v.x[i] + x + m,
						         v.y[i] + y >= 0 ? (v.y[i] + y) % n : v.y[i] + y + n)))
		{
			*err = 1;
			return (0);
		}
	return (new_v);
}
