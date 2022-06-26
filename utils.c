/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-moun <iel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:55:03 by iel-moun          #+#    #+#             */
/*   Updated: 2022/06/26 19:43:58 by iel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	kill(t_env *env)
{
	if (env->win != 0)
		free(env->win);
	if (env->img.img != 0)
		free(env->img.img);
	if (env->img.addr != 0)
		free(env->img.addr);
	if (env->mlx != 0)
		free(env->mlx);
	if (env != 0)
		free(env);
	exit(0);
	return (0);
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

int	ft_atoi(const char *n)
{
	int		ans;
	int		sign;
	char	*nb;

	ans = 0;
	sign = 1;
	nb = (char *)n;
	while (*nb == ' ' || *nb == '\n' || *nb == '\f'
		|| *nb == '\r' || *nb == '\t' || *nb == '\v')
		nb++;
	if (*nb == '-' || *nb == '+')
	{
		if (*nb == '-')
			sign = -1;
		nb++;
	}
	while (*nb >= '0' && *nb <= '9')
	{
		ans *= 10;
		ans += *nb - '0';
		nb++;
	}
	return (sign * ans);
}
