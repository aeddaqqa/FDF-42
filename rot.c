/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 01:13:09 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/07/29 23:47:54 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rot_z(t_var *f, int i, int j)
{
	if (f->etat == 1)
	{
		while (i < f->l)
		{
			j = 0;
			while (j < f->c)
			{
				f->cp[i][j].z = f->tab[i][j].z;
				f->cp[i][j].x = f->tab[i][j].x * cos(0.2 + f->rot) -
				f->tab[i][j].y * sin(0.2 + f->rot);
				f->cp[i][j].y = f->tab[i][j].x * sin(0.2 + f->rot) +
				f->tab[i][j].y * cos(0.2 + f->rot);
				iso(&f->cp[i][j].x, &f->cp[i][j].y, &f->cp[i][j].z, f->k);
				f->cp[i][j].y += (f->tab[i][j].z * f->h);
				j++;
			}
			i++;
		}
		f->rot += 0.2;
		f->step = steps(f->cp, f->l, f->c);
		mlx_clear_window(f->mlx_ptr, f->win_ptr);
		draw(*f, 1);
	}
}

void		rot_x(t_var *f, int i, int j)
{
	if (f->etat == 1)
	{
		while (i < f->l)
		{
			j = 0;
			while (j < f->c)
			{
				f->cp[i][j].x = f->tab[i][j].x;
				f->cp[i][j].y = f->tab[i][j].y * cos(0.2 + f->rot) +
				f->tab[i][j].z * sin(0.2 + f->rot);
				f->cp[i][j].z = -1 * f->tab[i][j].y * sin(0.2 + f->rot) +
				f->tab[i][j].z * cos(0.2 + f->rot);
				iso(&f->cp[i][j].x, &f->cp[i][j].y, &f->cp[i][j].z, f->k);
				f->cp[i][j].y += (f->tab[i][j].z * f->h);
				j++;
			}
			i++;
		}
		f->rot += 0.2;
		f->step = steps(f->cp, f->l, f->c);
		mlx_clear_window(f->mlx_ptr, f->win_ptr);
		draw(*f, 1);
	}
}

void		rot_y(t_var *f, int i, int j)
{
	if (f->etat == 1)
	{
		while (i < f->l)
		{
			j = 0;
			while (j < f->c)
			{
				f->cp[i][j].y = f->tab[i][j].y;
				f->cp[i][j].x = f->tab[i][j].x * cos(0.2 + f->rot) +
				f->tab[i][j].z * sin(0.2 + f->rot);
				f->cp[i][j].z = -1 * f->tab[i][j].x * sin(0.2 + f->rot) +
				f->tab[i][j].z * cos(0.2 + f->rot);
				iso(&f->cp[i][j].x, &f->cp[i][j].y, &f->cp[i][j].z, f->k);
				f->cp[i][j].y += (f->tab[i][j].z * f->h);
				j++;
			}
			i++;
		}
		f->rot += 0.2;
		f->step = steps(f->cp, f->l, f->c);
		mlx_clear_window(f->mlx_ptr, f->win_ptr);
		draw(*f, 1);
	}
}

void		haut_decri(t_var *f)
{
	int i;
	int j;

	i = -1;
	if (f->etat == 1)
	{
		f->h++;
		while (++i < f->l)
		{
			j = 0;
			while (j < f->c)
			{
				if (f->t[i][j])
				{
					if (f->rot)
						f->cp[i][j].y += 1;
					else
						f->cp[i][j].y += f->cp[i][j].z;
				}
				j++;
			}
		}
		mlx_clear_window(f->mlx_ptr, f->win_ptr);
		draw(*f, 1);
	}
}

void		haut_incri(t_var *f)
{
	int i;
	int j;

	i = -1;
	if (f->etat == 1)
	{
		f->h--;
		while (++i < f->l)
		{
			j = 0;
			while (j < f->c)
			{
				if (f->t[i][j])
				{
					if (f->rot)
						f->cp[i][j].y -= 1;
					else
						f->cp[i][j].y -= f->cp[i][j].z;
				}
				j++;
			}
		}
		mlx_clear_window(f->mlx_ptr, f->win_ptr);
		draw(*f, 1);
	}
}
