/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:40:24 by arive-de          #+#    #+#             */
/*   Updated: 2017/01/11 15:39:59 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		**ft_put_2d(t_fdf *env)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < env->nb_line)
	{
		j = 0;
		while (j < env->len)
		{
			env->tab[i][j].x2 = (sqrt(2) / 2) *
				(env->tab[i][j].x - env->tab[i][j].y);
			env->tab[i][j].y2 = ((sqrt(2) / sqrt(3)) * env->tab[i][j].z) -
				((env->tab[i][j].x + env->tab[i][j].y) / sqrt(6));
			j++;
		}
		i++;
	}
	return (env->tab);
}

void		ft_draw(t_fdf *env)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < env->nb_line)
	{
		j = 0;
		while (j < env->len)
		{
			draw_lines(env, i, j);
			j++;
		}
		i++;
	}
}

int			key_funct(int keycode, t_fdf *env)
{
	if (keycode == 53)
	{
		free(env);
		exit(0);
	}
	if (keycode == 69)
	{
		env->high += 5;
		set_high(env);
		mlx_clear_window(env->mlx, env->win);
		ft_put_2d(env);
		ft_draw(env);
	}
	if (keycode == 78)
	{
		env->high -= 5;
		set_high(env);
		mlx_clear_window(env->mlx, env->win);
		ft_put_2d(env);
		ft_draw(env);
	}
	set_color(keycode, env);
	set_moove(keycode, env);
	set_up_down(keycode, env);
	return (0);
}

int			mouse_funct(int keycode, void *param)
{
	char *str;

	(void)param;
	str = ft_strdup("\nTUTO\n\nR : red\nG : green\nB : blue\n\
W : white\narrows : moove\n+ : higher\n- : lower\n");
	if (keycode == 1)
		ft_putendl(str);
	free(str);
	return (0);
}

void		ft_init_window(t_fdf *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->resol, env->resol, "fdf");
	ft_put_2d(env);
	ft_draw(env);
	mlx_key_hook(env->win, key_funct, env);
	mlx_mouse_hook(env->win, mouse_funct, 0);
	mlx_loop(env->mlx);
}
