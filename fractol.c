/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-moun <iel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:26:36 by iel-moun          #+#    #+#             */
/*   Updated: 2022/06/26 15:26:39 by iel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_env	*init_env(int fractol)
{
	t_env	*env;

	env = (t_env *) malloc(sizeof(t_env));
	env->mlx = mlx_init();
	env->height = 500;
	env->width = 500;
	env->win = mlx_new_window(env->mlx, env->width, env->height, "world!");
	env->re_start = -2;
	env->re_end = 2;
	env->im_start = -2;
	env->im_end = 2;
	env->img.img = mlx_new_image(env->mlx, env->width, env->height);
	env->img.addr = mlx_get_data_addr(env->img.img, &(env->img.bits_per_pixel),
			&(env->img.line_length), &(env->img.endian));
	env->iterations = 2e3;
	return (env);
}

void	draw(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	while (i < env->height)
	{
		j = 0;
		while (j < env->width)
		{
			pixel_put(&(env->img), j, i, get_color(
					mandelbrot(remap(j, i, env), env), env));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
}

t_comp	remap(double x, double y, t_env *env)
{
	double	new_range_x;
	double	new_range_y;
	t_comp	new_val;

	new_range_x = env->re_end - env->re_start;
	new_range_y = env->im_end - env->im_start;
	new_val.re = x * (new_range_x / env->width) + env->re_start;
	new_val.im = y * (new_range_y / env->height) + env->im_start;
	return (new_val);
}

int	mandelbrot(t_comp c, t_env *env)
{
	t_comp	z;
	int		n;

	z.re = 0;
	z.im = 0;
	n = 0;
	while (n < env->iterations && modulus(z) <= 2)
	{
		z = add(multiply(z, z), c);
		n++;
	}
	if (n == env->iterations)
		return (n);
	return n;

}
