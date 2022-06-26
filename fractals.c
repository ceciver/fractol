/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-moun <iel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:03:27 by iel-moun          #+#    #+#             */
/*   Updated: 2022/06/26 18:42:10 by iel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	return (n);
}

int	julia(t_comp z, t_env *env)
{
	int		n;
	t_comp	c;

	c = env->julia_c;
	n = 0;
	while (n < env->iterations && modulus(z) <= 2)
	{
		z = add(multiply(z, z), c);
		n++;
	}
	if (n == env->iterations)
		return (n);
	return (n);
}
