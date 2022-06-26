/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-moun <iel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:26:36 by iel-moun          #+#    #+#             */
/*   Updated: 2022/06/26 19:53:22 by iel-moun         ###   ########.fr       */
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
	env->win = mlx_new_window(env->mlx, env->width, env->height, "Fract-ol");
	reset(env);
	env->img.img = mlx_new_image(env->mlx, env->width, env->height);
	env->img.addr = mlx_get_data_addr(env->img.img, &(env->img.bits_per_pixel),
			&(env->img.line_length), &(env->img.endian));
	env->iterations = 80;
	env->julia_c = init(0, 0);
	env->is_julia_active = false;
	if (fractol == 0)
		env->f = mandelbrot;
	else if (fractol == 1)
	{
		env->f = julia;
		env->is_julia_active = true;
	}
	else
		env->f = tricorn;
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
					env->f(remap(j, i, env), env), env));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
}
