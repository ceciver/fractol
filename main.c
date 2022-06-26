/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-moun <iel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 21:05:03 by iel-moun          #+#    #+#             */
/*   Updated: 2022/06/26 14:58:23 by iel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_env	*env;

	env = init_env(0);
	draw(env);
	mlx_hook(env->win, 2, 1L << 0, &handle_keyboard, env);
	mlx_mouse_hook(env->win, handle_mouse, env);
	mlx_loop(env->mlx);
}
