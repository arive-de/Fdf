/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_display_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:39:39 by arive-de          #+#    #+#             */
/*   Updated: 2017/01/11 15:37:55 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_display_tab(t_point **tab, size_t len, int nb_line)
{
	size_t j;

	j = 0;
	while (j < len)
	{
		ft_putnbr(tab[nb_line][j].z);
		if (tab[nb_line][j].z < 10)
			ft_putstr("  ");
		else
			ft_putchar(' ');
		j++;
	}
}

t_point		**ft_put_intab(t_fdf *env)
{
	static int	i = 0;
	int			j;
	char		**split_line;

	split_line = ft_strsplit(env->line, ' ');
	j = 0;
	env->len = ft_sstrlen(split_line);
	env->size = env->resol / (env->len + env->nb_line);
	env->tab[i] = (t_point*)ft_memalloc(sizeof(t_point) * env->len);
	while (split_line[j])
	{
		if (!env->tab)
			return (NULL);
		env->tab[i][j].z = ft_atoi(split_line[j]) * env->high;
		env->tab[i][j].z0 = ft_atoi(split_line[j]);
		env->tab[i][j].x = j * env->size;
		env->tab[i][j].y = i * env->size;
		j++;
	}
	ft_display_tab(env->tab, env->len, i);
	i++;
	return (env->tab);
}
