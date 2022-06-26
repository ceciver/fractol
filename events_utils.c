/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-moun <iel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:29:12 by iel-moun          #+#    #+#             */
/*   Updated: 2022/06/26 21:03:07 by iel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move(t_env *env, t_comp delta)
{
	env->im_start += delta.im;
	env->im_end += delta.im;
	env->re_start += delta.re;
	env->re_end += delta.re;
}

void	reset(t_env *env)
{
	env->re_start = -2;
	env->re_end = 2;
	env->im_start = -2;
	env->im_end = 2;
}

int	change_julia_c(int x, int y, t_env *env)
{
	if (!env->is_julia_active)
		return (0);
	env->julia_c = remap(x, y, env);
	draw(env);
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	handle_mouse(int key, int x, int y, t_env *env)
{
	if (key == 4)
		zoom_in(env, x, y);
	if (key == 5)
		zoom_out(env, x, y);
	draw(env);
	return (0);
}
