/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-moun <iel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 21:55:38 by iel-moun          #+#    #+#             */
/*   Updated: 2022/06/26 20:41:51 by iel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_comp	init(double re, double im)
{
	t_comp	c;

	c.re = re;
	c.im = im;
	return (c);
}

t_comp	add(t_comp a, t_comp b)
{
	t_comp	c;

	c.re = a.re + b.re;
	c.im = a.im + b.im;
	return (c);
}

t_comp	multiply(t_comp a, t_comp b)
{
	t_comp	c;

	c.re = a.re * b.re - a.im * b.im;
	c.im = a.re * b.im + a.im * b.re;
	return (c);
}

double	modulus(t_comp z)
{
	return (sqrt(z.re * z.re + z.im * z.im));
}
