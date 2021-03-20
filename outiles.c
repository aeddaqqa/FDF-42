/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outiles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:23:47 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/07/29 23:54:33 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_atoi_hex(char *str)
{
	int i;
	int r;

	i = 0;
	r = 0;
	while (str[i])
	{
		r = r * 16;
		if (str[i] >= '0' && str[i] <= '9')
			r += str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'Z')
			r += str[i] - 55;
		else if (str[i] >= 'a' && str[i] <= 'z')
			r += str[i] - 87;
		i++;
	}
	return (r);
}

int				comma(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
		{
			if (ft_strlen(&str[i + 1]) > 2)
			{
				if (str[i + 1] == '0' && str[i + 2] == 'x')
					return (ft_atoi_hex(&str[i + 3]));
			}
			return (16777215);
		}
		i++;
	}
	return (16777215);
}

void			zoom_plus(t_var *f)
{
	int i;
	int j;

	i = 0;
	while (i < f->l)
	{
		j = 0;
		while (j < f->c)
		{
			f->tab[i][j].x *= 2;
			f->tab[i][j].y *= 2;
			f->cp[i][j].x *= 2;
			f->cp[i][j].y *= 2;
			j++;
		}
		i++;
	}
	centralisation(f);
}

void			zoom_moins(t_var *f)
{
	int i;
	int j;

	i = 0;
	while (i < f->l)
	{
		j = 0;
		while (j < f->c)
		{
			f->tab[i][j].x /= 2;
			f->tab[i][j].y /= 2;
			f->cp[i][j].x /= 2;
			f->cp[i][j].y /= 2;
			j++;
		}
		i++;
	}
	centralisation(f);
}

void			fill_data(int fd, t_var *f, t_vect j, int v)
{
	char	**tmp;
	int		r;
	char	*t1;

	while ((r = get_next_line(fd, &t1)) > 0)
	{
		tmp = ft_split_whitespaces(t1);
		j.b = -1;
		if (!(f->t[j.a] = (int*)malloc(sizeof(int) * f->c)) ||
		!(f->tab[j.a] = (t_point*)malloc(sizeof(t_point) * f->c)) ||
		!(f->cp[j.a] = (t_point*)malloc(sizeof(t_point) * f->c)))
			return ;
		while (++j.b < f->c)
		{
			f->tab[j.a][j.b].y = j.a * v;
			f->tab[j.a][j.b].x = j.b * v;
			f->tab[j.a][j.b].z = ft_atoi(tmp[j.b]);
			f->t[j.a][j.b] = (f->tab[j.a][j.b].z) ? 1 : 0;
			f->tab[j.a][j.b].color = comma(tmp[j.b]);
			f->cp[j.a][j.b].color = f->tab[j.a][j.b].color;
		}
		ft_free_tab(tmp);
		ft_strdel(&t1);
		j.a++;
	}
}
