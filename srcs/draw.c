/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <gabshire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:19:35 by gabshire          #+#    #+#             */
/*   Updated: 2019/09/23 13:30:37 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_drawline(t_draw point1, t_draw point2, t_fdf *fdf, int color)
{
	t_line	line;

	line.delta_x = abs(point1.x - point2.x);
	line.delta_y = abs(point1.y - point2.y);
	line.sign_x = point1.x < point2.x ? 1 : -1;
	line.sign_y = point1.y < point2.y ? 1 : -1;
	line.error = line.delta_x - line.delta_y;
	while (point1.x != point2.x || point1.y != point2.y)
	{
		line.t = point1.x + point1.y * WIDTH;
		if (point1.x < WIDTH && point1.y < HIGHT
		&& point1.x > 0 && point1.y > 0 && t < WIDTH * HIGHT && line.t > 0)
			fdf->map[line.t] = color;
		line.error2 = line.error * 2;
		if (line.error2 > -line.delta_y)
		{
			line.error -= line.delta_y;
			point1.x += line.sign_x;
		}
		if (line.error2 < line.delta_x)
		{
			line.error += line.delta_x;
			point1.y += line.sign_y;
		}
	}
}

static void	ft_draw_y(t_fdf *fdf)
{
	unsigned	i;
	unsigned	j;
	t_draw		**draw;

	i = 0;
	draw = fdf->draw;
	while (draw[i])
	{
		j = 0;
		while (draw[i][j + 1].color)
		{
			ft_drawline(operation(draw[i][j], fdf),
					operation(draw[i][j + 1], fdf), fdf, draw[i][j].color);
			++j;
		}
		++i;
	}
}

static void	ft_draw_x(t_fdf *fdf)
{
	unsigned	i;
	unsigned	j;
	t_draw		**draw;

	i = 0;
	draw = fdf->draw;
	j = 0;
	while (draw[i][j].color)
	{
		i = 0;
		while (draw[i + 1])
		{
			ft_drawline(operation(draw[i][j], fdf),
					operation(draw[i + 1][j], fdf), fdf, draw[i][j].color);
			++i;
		}
		++j;
	}
}

void		ft_drow(t_fdf *fdf)
{
	ft_bzero(fdf->map, WIDTH * HIGHT * sizeof(int));
	ft_draw_y(fdf);
	ft_draw_x(fdf);
	fdf->proektion = 0;
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
}
