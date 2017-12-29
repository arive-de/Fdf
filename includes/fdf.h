/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:10:16 by arive-de          #+#    #+#             */
/*   Updated: 2017/01/16 15:34:59 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "math.h"
# include <stdio.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "libft.h"

typedef struct	s_point
{
	int x;
	int x2;
	int y;
	int y2;
	int z;
	int z0;
}				t_point;

typedef struct	s_fdf
{
	int			fd;
	int			ret;
	char		*line;
	void		*mlx;
	void		*win;
	size_t		len;
	size_t		nb_line;
	int			moove;
	int			up_down;
	int			size;
	int			high;
	int			resol;
	int			color;
	int			x;
	int			y;
	int			z;
	t_point		**tab;
}				t_fdf;

t_point			**ft_put_intab(t_fdf *env);
void			ft_init_window(t_fdf *env);
void			ft_draw(t_fdf *env);
void			draw_line(t_fdf *env, t_point a, t_point b);
void			draw_lines(t_fdf *env, size_t i, size_t y);
int				key_funct(int keycode, t_fdf *env);
void			set_high(t_fdf *env);
void			set_color(int keycode, t_fdf *env);
void			set_moove(int keycode, t_fdf *env);
void			set_up_down(int keycode, t_fdf *env);
#endif
