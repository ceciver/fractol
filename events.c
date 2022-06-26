/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-moun <iel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 14:57:56 by iel-moun          #+#    #+#             */
/*   Updated: 2022/06/26 18:31:32 by iel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_keyboard(int key, t_env *env)
{
	t_comp	delta;

	delta = init(0, 0);
	printf("%d\n", key);
	if (key == KEY_LEFT)
		delta.re = -0.1 * (env->re_end - env->re_start);
	if (key == KEY_RIGHT)
		delta.re = 0.1 * (env->re_end - env->re_start);
	if (key == KEY_UP)
		delta.im = -0.1 * (env->im_end - env->im_start);
	if (key == KEY_DOWN)
		delta.im = 0.1 * (env->im_end - env->im_start);
	if (key == KEY_Z)
		env->iterations = min(1000, env->iterations + 10);
	if (key == KEY_N)
		env->iterations = max(40, env->iterations - 10);
	if (key == KEY_ESCAPE)
		kill(env);
	if (key == KEY_ESCAPE)
		kill(env);
	if (key == KEY_R)
		reset(env);
	move(env, delta);
	draw(env);
	return (0);
}

void	center_in(t_env *env, double x, double y)
{
	env->re_start += x;
	env->re_end += x;
	env->im_start += y;
	env->im_end += y;
}

void	zoom_in(t_env *env, int x, int y)
{
	double	re_d;
	double	im_d;
	t_comp	c1;
	t_comp	c2;

	c1 = remap(x, y, env);
	center_in(env, remap(x, y, env).re, remap(x, y, env).im);
	re_d = 0.1 * (env->re_end - env->re_start);
	im_d = 0.1 * (env->im_end - env->im_start);
	env->im_start += im_d;
	env->im_end -= im_d;
	env->re_start += re_d;
	env->re_end -= re_d;
	c2 = remap(x, y, env);
	env->im_start -= (c2.im - c1.im);
	env->im_end -= (c2.im - c1.im);
	env->re_start -= (c2.re - c1.re);
	env->re_end -= (c2.re - c1.re);
	draw(env);
}

void	zoom_out(t_env *env, int x, int y)
{
	double	re_d;
	double	im_d;
	t_comp	c1;
	t_comp	c2;

	c1 = remap(x, y, env);
	center_in(env, remap(x, y, env).re, remap(x, y, env).im);
	re_d = 0.1 * (env->re_end - env->re_start);
	im_d = 0.1 * (env->im_end - env->im_start);
	env->im_start -= im_d;
	env->im_end += im_d;
	env->re_start -= re_d;
	env->re_end += re_d;
	c2 = remap(x, y, env);
	env->im_start -= (c2.im - c1.im);
	env->im_end -= (c2.im - c1.im);
	env->re_start -= (c2.re - c1.re);
	env->re_end -= (c2.re - c1.re);
	draw(env);
}

int	handle_mouse(int key, int x, int y, t_env *env)
{
	if (key == 4)
		zoom_in(env, x, y);
	if (key == 5)
		zoom_out(env, x, y);
	draw(env);
}
