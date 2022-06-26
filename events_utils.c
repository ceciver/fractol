/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-moun <iel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:29:12 by iel-moun          #+#    #+#             */
/*   Updated: 2022/06/26 18:29:26 by iel-moun         ###   ########.fr       */
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
