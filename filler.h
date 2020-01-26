/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiklaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 03:17:03 by bmiklaz           #+#    #+#             */
/*   Updated: 2019/02/26 03:17:03 by bmiklaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "Libft/libft.h"

# define SINTV struct s_vcoord
# define SMAP struct s_map
# define MINR struct s_minrait

# define C 9223372036854775807

# define PICX map->piece->x
# define PICY map->piece->y
# define LM(i, j) map->lee_m[i][j]
# define VXYINMAP map.tabl[rep.x[i]][rep.y[i]]
# define ANSX m.n == C ? 0 : (m.v->x[1] + m.v->x[0] > map->m ? m.v->x[1] - map->m  : m.v->x[1])
# define ANSY m.n == C ? 0 : (m.v->y[1] + m.v->y[0] > map->n ? m.v->y[1] - map->n  : m.v->y[1])
# define ME p == 'O' ? 1 : 2
# define HE p == 'O' ? 2 : 1

typedef SINTV	t_vcoord;
typedef SMAP	t_map;
typedef MINR	t_minrait;

extern int	g_score;

struct		s_vcoord
{
	unsigned	cap;
	unsigned	len;
	int			*x;
	int			*free_p_x;
	int			*y;
	int			*free_p_y;
};

struct		s_map
{
	int			m;
	int			n;
	char		**tabl;
	int			**lee_m;
	t_vcoord	*piece;
};

struct		s_minrait
{
	long		n;
	t_vcoord	*v;
};

int			create_map(t_map **map, char *buf);
void		change_lee_map(t_map copy, char p_num, t_vcoord *lee_vec);
int			change_map(t_map map, t_vcoord rep, char p_num);
void		map_backup(t_map map, t_vcoord rep, char p_num);
void		free_map(t_map **map);
void		upd_map(t_map **map, int *err);
void		upd_piece(t_map *map, char *buf, int *err);

int			push_back_v(t_vcoord *v, int x, int y);
void		pop_front_v(t_vcoord *v);
t_vcoord	*make_vcoord();
int			del_vcoord(t_vcoord **vec);
t_vcoord	*cpy_rep_vec(t_vcoord v, int x, int y, int *err, int m, int n);

void		easy_choice(t_map *map, char p_num, int *err);
void		do_magic(t_map *map, int *err, char p);

long		reit_rep(t_map map, t_vcoord rep, char p_num, int f);

int			check_error(t_map *map, int *err, char p_num);
char		read_p_num(void);

#endif
