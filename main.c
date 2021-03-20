/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 16:31:26 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/07/31 20:41:47 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_free(void **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
		}
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

void			error(void)
{
	ft_putstr("error\n");
	exit(0);
}

int				main(int argc, char **argv)
{
	t_var		t;
	t_point		**tab;

	if (argc != 2)
	{
		ft_putstr("usage: ./fdf [file_name]\n");
		return (0);
	}
	else
	{
		t.mlx_ptr = mlx_init();
		t.win_ptr = mlx_new_window(t.mlx_ptr, 2100, 1500, argv[1]);
		t = ft_stock_cord(argv, &t);
		t.error == 1 ? error() : 1;
		t.rot = 0;
		t.h = 0;
		t.step = steps(t.tab, t.l, t.c);
		draw(t, 0);
		mlx_hook(t.win_ptr, 2, 0, &key_press, &t);
		mlx_loop(t.mlx_ptr);
		ft_free((void**)t.tab);
		ft_free((void**)t.cp);
		ft_free((void**)t.t);
	}
	return (0);
}
