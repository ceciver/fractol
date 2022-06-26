/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-moun <iel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 21:05:03 by iel-moun          #+#    #+#             */
/*   Updated: 2022/06/26 19:53:01 by iel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	choosen_fractol(int ac, char **av)
{
	int	fractol;

	if (ac != 2)
		return (-1);
	fractol = ft_atoi(av[1]);
	if (fractol < 0 || fractol > 2)
		return (-1);
	return (fractol);
}

void	print_doc(void)
{
	ft_putstr_fd("\n\n---------------------\n", 1);
	ft_putstr_fd("Reset: R\n", 1);
	ft_putstr_fd("Move: arrows\n", 1);
	ft_putstr_fd("Zoom: scrool\n", 1);
	ft_putstr_fd("Fix julia constant: S\n", 1);
	ft_putstr_fd("Close: ESC\n", 1);
	ft_putstr_fd("---------------------\n\n", 1);
}

int	main(int ac, char **av)
{
	t_env	*env;
	int		fractol;

	fractol = choosen_fractol(ac, av);
	if (fractol == -1)
	{
		ft_putstr_fd("Invalid Parameter!\n", 2);
		return (1);
	}
	print_doc();
	env = init_env(fractol);
	draw(env);
	mlx_hook(env->win, 2, 1L << 0, &handle_keyboard, env);
	mlx_hook(env->win, 17, 1L << 2, &kill, env);
	mlx_hook(env->win, 6, (1L << 6), change_julia_c, env);
	mlx_mouse_hook(env->win, handle_mouse, env);
	mlx_loop(env->mlx);
	return (0);
}
