/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-moun <iel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:51:56 by iel-moun          #+#    #+#             */
/*   Updated: 2022/06/26 20:58:59 by iel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include "keys.h"
# include <stdbool.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_comp
{
	double	re;
	double	im;
}	t_comp;

typedef struct s_env
{
	void	*mlx;
	void	*win;
	t_data	img;
	double	re_start;
	double	re_end;
	double	im_start;
	double	im_end;
	double	width;
	double	height;
	int		iterations;
	t_comp	julia_c;
	int		(*f)(struct s_comp, struct s_env *);
	bool	is_julia_active;
	int		color_base;
}	t_env;

t_env	*init_env(int fractol);
void	pixel_put(t_data *data, int x, int y, int color);

t_comp	add(t_comp a, t_comp b);
t_comp	multiply(t_comp a, t_comp b);
double	modulus(t_comp z);
t_comp	init(double re, double im);
double	dot(t_comp a, t_comp b);

int		mandelbrot(t_comp c, t_env *env);
int		julia(t_comp z, t_env *env);
int		tricorn(t_comp c, t_env *env);

t_comp	remap(double x, double y, t_env *env);
int		get_color(int iterations, t_env *env);
void	draw(t_env *env);

int		handle_keyboard(int key, t_env *env);
void	zoom_in(t_env *env, int x, int y);
void	zoom_out(t_env *env, int x, int y);
int		handle_mouse(int key, int x, int y, t_env *env);
void	ft_putstr_fd(char *s, int fd);

int		max(int a, int b);
int		min(int a, int b);
int		kill(t_env *env);
int		ft_atoi(const char *n);

void	move(t_env *env, t_comp delta);
void	reset(t_env *env);

int		change_julia_c(int x, int y, t_env *env);
#endif
