/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:21:14 by arive-de          #+#    #+#             */
/*   Updated: 2017/01/16 17:48:19 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		read_file(t_fdf *env)
{
	if (env->fd == -1)
		return (-1);
	env->tab = (t_point**)ft_memalloc(sizeof(t_point) * env->nb_line);
	if (!env->tab)
		return (0);
	while ((env->ret = get_next_line(env->fd, &env->line)) > 0)
	{
		ft_put_intab(env);
		ft_putchar('\n');
	}
	if (close(env->fd) == -1)
	{
		free(env);
		return (-1);
	}
	ft_init_window(env);
	return (0);
}

size_t	ft_len_tab(char *line)
{
	t_fdf		tmp;
	char		**split_line;

	split_line = ft_strsplit(line, ' ');
	tmp.len = ft_sstrlen(split_line);
	return (tmp.len);
}

int		is_empty(t_fdf *env)
{
	int		ret;
	char	buf[1];

	ret = read(env->fd, buf, 1);
	if (ret == 0)
	{
		ft_putstr("Empty file\n");
		free(env);
		exit(0);
	}
	if (close(env->fd) == -1)
	{
		free(env);
		exit(0);
	}
	return (0);
}

t_fdf	*get_line(t_fdf *env)
{
	static size_t tmp;

	while ((env->ret = get_next_line(env->fd, &env->line)) > 0)
	{
		env->len = ft_len_tab(env->line);
		if (tmp != env->len && tmp != 0)
		{
			ft_putendl("Bad Format");
			free(env);
			exit(0);
		}
		tmp = env->len;
		env->nb_line++;
	}
	if (env->ret == -1)
	{
		ft_putendl("Usage : ./fdf file");
		free(env);
		exit(0);
	}
	return (env);
}

int		main(int argc, char **argv)
{
	t_fdf	*env;

	if (argc != 2)
		ft_putendl("Usage : ./fdf File");
	if (!(env = (t_fdf*)ft_memalloc(sizeof(t_fdf))))
		return (0);
	env->fd = open(argv[1], O_RDONLY);
	if (env->fd == -1)
	{
		ft_putendl("Bad usage or file does not exist");
		free(env);
		return (0);
	}
	is_empty(env);
	env->moove = 600;
	env->up_down = 500;
	env->resol = 1500;
	env->color = 0x00FFFFFF;
	env->high = 2;
	env->fd = open(argv[1], O_RDONLY);
	get_line(env);
	env->fd = open(argv[1], O_RDONLY);
	read_file(env);
	return (0);
}
