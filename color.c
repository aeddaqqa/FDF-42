/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:37:25 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/07/30 01:08:07 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double			percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

static int				get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int						get_color(t_vect current, t_point start, t_point end)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (abs((int)(start.x - end.x)) > abs((int)(start.y - end.y)))
		percentage = percent(start.x, end.x, current.a);
	else
		percentage = percent(start.y, end.y, current.b);
	red = get_light((start.color >> 16) &
			0xFF, (end.color >> 16) & 0xFF, percentage);
	green = get_light((start.color >> 8) &
			0xFF, (end.color >> 8) & 0xFF, percentage);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

void					color_change(t_var *f)
{
	int i;
	int j;

	i = 0;
	while (i < f->l)
	{
		j = 0;
		while (j < f->c)
		{
			f->tab[i][j].color += 100000;
			f->cp[i][j].color += 100000;
			if (f->t[i][j])
				f->cp[i][j].color += 500000;
			if (f->t[i][j])
				f->tab[i][j].color += 500000;
			j++;
		}
		i++;
	}
	mlx_clear_window(f->mlx_ptr, f->win_ptr);
	if (f->etat == 1)
		draw(*f, 1);
	else
		draw(*f, 0);
}
