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

#include "filler.h"
#include <fcntl.h>
#include <stdio.h>
#include <pthread.h>

int		g_score = 0;

char	read_p_num(void)
{
	char	*buf;
	char	r;

	ft_gnl(0, &buf, 1);
	r = *(ft_strchr(buf, 'p') + 1) == '1' ? 'O' : 'X';
	ft_memdel((void**)&buf);
	return (r);
}

int		main(void)
{
	char	p_num;
	t_map	*map;
	int		err;

	err = 0;
	map = 0;
	p_num = read_p_num();
	while (err != 1)
	{
		upd_map(&map, &err);
		if (err != 1 && check_error(map, &err, p_num))
			easy_choice(map, p_num, &err);
		else if (!err)
		{
			do_magic(map, &err, p_num);
		}
	}
	free_map(&map);
}
