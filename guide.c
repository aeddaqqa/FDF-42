/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guide.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 02:16:39 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/07/29 09:27:32 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			stayerf(t_var f)
{
	t_point p1;
	t_point p2;

	f.step.a = 0;
	f.step.b = 0;
	p1.x = 1500;
	p1.y = 1350;
	p2.x = (1500 + 2030) / 2;
	p2.y = 1350;
	p1.color = 14701865;
	p2.color = 14014423;
	draw_line(p1, p2, f);
	p1.x = (1500 + 2030) / 2;
	p1.y = 1350;
	p2.x = 2100;
	p2.y = 1350;
	p1.color = 14014423;
	p2.color = 14701865;
	draw_line(p1, p2, f);
}

static void			stayer(t_var f, int x, int y)
{
	t_point p1;
	t_point p2;

	f.step.a = 0;
	f.step.b = 0;
	p1.x = x;
	p1.y = y;
	p2.x = (x + 2040) / 2;
	p2.y = y;
	p1.color = 14701865;
	p2.color = 14014423;
	draw_line(p1, p2, f);
	p1.x = (x + 2040) / 2;
	p1.y = y;
	p2.x = 2040;
	p2.y = y;
	p1.color = 14014423;
	p2.color = 14701865;
	draw_line(p1, p2, f);
}

void				ft_ft(t_var f, int i)
{
	t_point p1;
	t_point p2;

	f.step.a = 0;
	f.step.b = 0;
	p1.x = 1500;
	p1.y = 0;
	p2.x = 1500;
	p2.y = 1500;
	p1.color = 14701865;
	p2.color = 14014423;
	while (i++ < 20)
		draw_line(p1, p2, f);
	p1.x = 1780;
	p1.y = 130;
	p2.x = 1850;
	p2.y = 130;
	p1.color = 14701865;
	p2.color = 14014423;
	draw_line(p1, p2, f);
}

static void			hp(t_var f)
{
	mlx_string_put(f.mlx_ptr, f.win_ptr, 1560, 700, 16777126,
	"changement de couleur                : [space]");
	mlx_string_put(f.mlx_ptr, f.win_ptr, 1560, 800, 16777126,
	"roration sur l'axe de x              : [w]");
	mlx_string_put(f.mlx_ptr, f.win_ptr, 1560, 900, 16777126,
	"roration sur l'axe de y              : [e]");
	mlx_string_put(f.mlx_ptr, f.win_ptr, 1560, 1000, 16777126,
	"roration sur l'axe de z              : [q]");
	mlx_string_put(f.mlx_ptr, f.win_ptr, 1560, 1100, 16777126,
	"translation                          : [->...]");
	mlx_string_put(f.mlx_ptr, f.win_ptr, 1560, 1200, 16777126,
	"centralisation                       : [c]");
	mlx_string_put(f.mlx_ptr, f.win_ptr, 1560, 1300, 16777126,
	"iso and hold h ;)                    : [h]");
}

void				menu(t_var f)
{
	int i;
	int x;

	i = 0;
	x = 250;
	while (i++ < 11)
	{
		stayer(f, 1550, x);
		x += 100;
	}
	ft_ft(f, 0);
	mlx_string_put(f.mlx_ptr, f.win_ptr, 1780, 100, 0xff9978,
	"Menu :");
	mlx_string_put(f.mlx_ptr, f.win_ptr, 1560, 200, 16777126,
	"zoom                                 : [+ / -]");
	mlx_string_put(f.mlx_ptr, f.win_ptr, 1560, 300, 16777126,
	"parallel                             : [p]");
	mlx_string_put(f.mlx_ptr, f.win_ptr, 1560, 400, 16777126,
	"iso                                  : [d]");
	mlx_string_put(f.mlx_ptr, f.win_ptr, 1560, 500, 16777126,
	"hauteur                              : [o / i]");
	mlx_string_put(f.mlx_ptr, f.win_ptr, 1560, 600, 16777126,
	"changement de l'angle de vue         : [s]");
	hp(f);
	stayerf(f);
}
