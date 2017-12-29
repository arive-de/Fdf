/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 09:59:28 by arive-de          #+#    #+#             */
/*   Updated: 2017/01/11 13:26:42 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_fdf *env, t_point a, t_point b)
{
	int dx;
	int dy;
	int s[2];
	int err[2];

	dx = abs(b.x2 - a.x2);
	dy = abs(b.y2 - a.y2);
	s[0] = (a.x2 < b.x2 ? 1 : -1);
	s[1] = (a.y2 < b.y2 ? 1 : -1);
	err[0] = (dx > dy ? dx : -dy) / 2;
	while (a.x2 != b.x2 || a.y2 != b.y2)
	{
		mlx_pixel_put(env->mlx, env->win, a.x2, a.y2, env->color);
		err[1] = err[0];
		if (err[1] > -dx)
		{
			err[0] -= dy;
			a.x2 += s[0];
		}
		if (err[1] < dy)
		{
			err[0] += dx;
			a.y2 += s[1];
		}
	}
}

void	draw_lines(t_fdf *env, size_t i, size_t j)
{
	t_point p[2];

	p[0].z = env->tab[i][j].z;
	p[0].x2 = env->moove + env->tab[i][j].x2;
	p[0].y2 = env->up_down - env->tab[i][j].y2;
	if (i < env->nb_line - 1)
	{
		p[1].z = env->tab[i + 1][j].z;
		p[1].x2 = env->moove + env->tab[i + 1][j].x2;
		p[1].y2 = env->up_down - env->tab[i + 1][j].y2;
		draw_line(env, p[0], p[1]);
	}
	if (j < env->len - 1)
	{
		p[1].z = env->tab[i][j + 1].z;
		p[1].x2 = env->moove + env->tab[i][j + 1].x2;
		p[1].y2 = env->up_down - env->tab[i][j + 1].y2;
		draw_line(env, p[0], p[1]);
	}
}
