/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 05:15:34 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/07/28 15:42:41 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		trans(t_var *f, int keycode)
{
	if (keycode == 124)
		f->step.a += 100;
	if (keycode == 123)
		f->step.a -= 100;
	if (keycode == 125)
		f->step.b += 100;
	if (keycode == 126)
		f->step.b -= 100;
	mlx_clear_window(f->mlx_ptr, f->win_ptr);
	if (f->etat == 0)
		draw(*f, 0);
	else
		draw(*f, 1);
}

int				key_press(int keycode, t_var *t)
{
	(keycode == 53) ? exit(1) : 1 == 1;
	(keycode == 78) ? zoom_moins(t) : 1 == 1;
	(keycode == 69) ? zoom_plus(t) : 1 == 1;
	(keycode == 124 || keycode == 123 || keycode == 125 || keycode == 126) ?
	trans(t, keycode) : 1 == 1;
	(keycode == 8) ? centralisation(t) : 1 == 1;
	(keycode == 31) ? haut_incri(t) : 1 == 1;
	(keycode == 34) ? haut_decri(t) : 1 == 1;
	(keycode == 2) ? iso_a(t) : 1 == 1;
	(keycode == 35) ? para(t) : 1 == 1;
	(keycode == 1) ? more_iso(t) : 1 == 1;
	(keycode == 12) ? rot_z(t, 0, 0) : 1 == 1;
	(keycode == 13) ? rot_x(t, 0, 0) : 1 == 1;
	(keycode == 14) ? rot_y(t, 0, 0) : 1 == 1;
	(keycode == 49) ? color_change(t) : 1 == 1;
	(keycode == 4) ? event(t) : 1 == 1;
	return (0);
}
