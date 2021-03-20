/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 16:31:37 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/07/31 20:43:14 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include "get_next_line.h"
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>

typedef struct	s_point
{
	double			x;
	double			y;
	double			z;
	unsigned int	color;
}				t_point;

typedef struct	s_vect
{
	int a;
	int b;
}				t_vect;

typedef struct	s_bres
{
	int			abs;
	int			ord;
	int			dx;
	int			dy;
	int			stepx;
	int			stepy;
	int			e;
	int			i;
	t_point		beg;
	t_point		end;
}				t_bres;

typedef struct	s_var
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_point	**tab;
	int		c;
	int		h;
	int		l;
	t_vect	step;
	t_point	**cp;
	double	k;
	int		error;
	int		etat;
	double	rot;
	int		**t;
}				t_var;

int				ft_atoi(const char *str);
void			ft_putstr(char const *s);
char			*ft_strchr(const char *s, int c);
void			ft_strdel(char **as);
char			*ft_strdup(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
size_t			ft_strlen(const char *str);
char			*ft_strnew(size_t size);
int				comma(char *str);
int				get_color(t_vect current, t_point start, t_point end);
t_vect			steps(t_point **tab, int ligne, int colon);
int				scale_calcul(t_var f);
void			part1(t_bres p, void *mlx_ptr, void *win_ptr, t_vect start);
void			part2(t_bres p, void *mlx_ptr, void *win_ptr, t_vect start);
void			draw_line(t_point p1, t_point p2, t_var f);
char			**ft_split_whitespaces(char *str);
int				ft_atoi_base(char *str, int base);
void			ft_free_tab(char **tab);
t_var			ft_stock_cord(char **argv, t_var *f);
t_vect			ft_check(char **argv);
int				*len_lines(char **argv, int t);
int				len_line(char *str);
void			iso(double *x, double *y, double *z, double k);
void			draw(t_var f, int var);
int				mlx_hook(void *win_ptr, int x_event, int x_mask,
										int (*funct)(), void *param);
int				key_press(int keycode, t_var *t);
void			centralisation(t_var *f);
void			iso_a(t_var *f);
void			more_iso(t_var *f);
void			para(t_var *f);
void			event(t_var *f);
void			rot_z(t_var *f, int i, int j);
void			rot_x(t_var *f, int i, int j);
void			rot_y(t_var *f, int i, int j);
void			color_change(t_var *f);
void			haut_decri(t_var *f);
void			haut_incri(t_var *f);
void			zoom_plus(t_var *f);
void			zoom_moins(t_var *f);
void			ft_ft(t_var f, int i);
void			menu(t_var f);
void			fill_data(int fd, t_var *f, t_vect j, int v);
void			error(void);
#endif
