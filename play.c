/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 03:09:04 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/07/29 23:54:08 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		centralisation(t_var *f)
{
	if (f->etat == 0)
	{
		f->step = steps(f->tab, f->l, f->c);
		mlx_clear_window(f->mlx_ptr, f->win_ptr);
		draw(*f, 0);
	}
	else
	{
		f->step = steps(f->cp, f->l, f->c);
		mlx_clear_window(f->mlx_ptr, f->win_ptr);
		draw(*f, 1);
	}
}

void		iso_a(t_var *f)
{
	int i;
	int j;

	i = -1;
	if (f->etat == 0)
	{
		f->etat = 1;
		while (++i < f->l)
		{
			j = 0;
			while (j < f->c)
			{
				f->cp[i][j].x = f->tab[i][j].x;
				f->cp[i][j].y = f->tab[i][j].y;
				f->cp[i][j].z = f->tab[i][j].z;
				iso(&f->cp[i][j].x, &f->cp[i][j].y,
				&f->cp[i][j].z, f->k);
				f->cp[i][j].y += (f->tab[i][j].z * f->h);
				j++;
			}
		}
	}
	mlx_clear_window(f->mlx_ptr, f->win_ptr);
	f->step = steps(f->cp, f->l, f->c);
	draw(*f, 1);
}

void		more_iso(t_var *f)
{
	int i;
	int j;

	if (f->etat == 1)
	{
		i = 0;
		f->k += 0.2;
		while (i < f->l)
		{
			j = 0;
			while (j < f->c)
			{
				f->cp[i][j].x = f->tab[i][j].x;
				f->cp[i][j].y = f->tab[i][j].y;
				iso(&f->cp[i][j].x, &f->cp[i][j].y,
				&f->tab[i][j].z, f->k);
				f->cp[i][j].y += (f->tab[i][j].z * f->h);
				j++;
			}
			i++;
		}
		f->step = steps(f->cp, f->l, f->c);
		mlx_clear_window(f->mlx_ptr, f->win_ptr);
		draw(*f, 1);
	}
}

void		para(t_var *f)
{
	mlx_clear_window(f->mlx_ptr, f->win_ptr);
	f->etat = 0;
	f->step = steps(f->tab, f->l, f->c);
	draw(*f, 0);
}

void		event(t_var *f)
{
	int i;
	int j;

	i = 0;
	while (i < f->l)
	{
		j = 0;
		while (j < f->c)
		{
			f->cp[i][j].x = f->tab[i][j].x;
			f->cp[i][j].y = f->tab[i][j].y;
			iso(&f->cp[i][j].x, &f->cp[i][j].y, &f->tab[i][j].z, f->k);
			f->cp[i][j].y += (f->tab[i][j].z * f->h);
			f->cp[i][j].color += 100000;
			if (f->t[i][j])
				f->cp[i][j].color += 500000;
			j++;
		}
		i++;
	}
	f->k += 0.2;
	centralisation(f);
}
