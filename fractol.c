/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-moun <iel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 21:03:59 by iel-moun          #+#    #+#             */
/*   Updated: 2022/06/25 21:27:37 by iel-moun         ###   ########.fr       */
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
	env->height = 1920;
	env->width = 1080;
	env->win = mlx_new_window(env->mlx, env->width, env->height, "world!");
	env->re_start = -2;
	env->re_end = 2;
	env->im_start = -2;
	env->im_end = 2;
	env->img.img = mlx_new_image(env->mlx, env->width, env->height);
	env->img.addr = mlx_get_data_addr(env->img.img, &(env->img.bits_per_pixel),
			&(env->img.line_length), &(env->img.endian));
	return (env);
}
