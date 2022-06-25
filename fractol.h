/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-moun <iel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:51:56 by iel-moun          #+#    #+#             */
/*   Updated: 2022/06/25 21:26:36 by iel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include <stdlib.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_env
{
	void	*mlx;
	void	*win;
	t_data	img;
	double	re_start;
	double	re_end;
	double	im_start;
	double	im_end;
	int		width;
	int		height;
}	t_env;

typedef struct s_comp
{
	double	re;
	double	im;
}	t_comp;

t_env	*init_env(int fractol);
void	pixel_put(t_data *data, int x, int y, int color);

#endif