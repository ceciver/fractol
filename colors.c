/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-moun <iel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:25:57 by iel-moun          #+#    #+#             */
/*   Updated: 2022/06/26 20:51:08 by iel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int iter, t_env *env)
{
	int	red;
	int	green;
	int	blue;

	if (iter == env->iterations)
		return (0);
	red = env->color_base * (cos((double)iter) + 1);
	green = env->color_base * (sin((double)iter) + 1);
	blue = env->color_base * (1 - cos((double)iter));
	return ((red << 16) | (green << 8) | blue);
}
