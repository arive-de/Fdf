/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:38:11 by arive-de          #+#    #+#             */
/*   Updated: 2017/01/13 15:04:37 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_high(t_fdf *env)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < env->nb_line)
	{
		j = 0;
		while (j < env->len)
		{
			env->tab[i][j].z = env->tab[i][j].z0 * env->high;
			j++;
		}
		i++;
	}
}

void	set_color(int keycode, t_fdf *env)
{
	if (keycode == 15)
	{
		env->color = 0x00FF0000;
		ft_draw(env);
	}
	if (keycode == 5)
	{
		env->color = 0x0000FF00;
		ft_draw(env);
	}
	if (keycode == 11)
	{
		env->color = 0x000000FF;
		ft_draw(env);
	}
	if (keycode == 13)
	{
		env->color = 0x00FFFFFF;
		ft_draw(env);
	}
}

void	set_moove(int keycode, t_fdf *env)
{
	if (keycode == 123)
	{
		env->moove -= 50;
		mlx_clear_window(env->mlx, env->win);
		ft_draw(env);
	}
	if (keycode == 124)
	{
		env->moove += 50;
		mlx_clear_window(env->mlx, env->win);
		ft_draw(env);
	}
}

void	set_up_down(int keycode, t_fdf *env)
{
	if (keycode == 126)
	{
		env->up_down -= 50;
		mlx_clear_window(env->mlx, env->win);
		ft_draw(env);
	}
	if (keycode == 125)
	{
		env->up_down += 50;
		mlx_clear_window(env->mlx, env->win);
		ft_draw(env);
	}
}
