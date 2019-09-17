#include "fdf.h"

void ft_drawLine(t_point point1, t_point point2, t_fdf *fdf, double color)
{
	const int deltaX = abs((int)point1.x - (int)point2.x);
	const int deltaY = abs((int)point1.y - (int)point2.y);
	const int signX = point1.x < point2.x ? 1 : -1;
	const int signY = point1.y < point2.y ? 1 : -1;

	int error = deltaX - deltaY;
	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (int)point2.x, (int)point2.y, (int)color);
	while((int)point1.x != (int)point2.x || (int)point1.y != (int)point2.y)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (int)point1.x, (int)point1.y, (int)color);
		const int error2 = error * 2;
		if (error2 > -deltaY)
		{
			error -= deltaY;
			point1.x += signX;
		}
		if (error2 < deltaX)
		{
			error += deltaX;
			point1.y += signY;
		}
	}
}

void	ft_draw_y(t_fdf *fdf)
{
	unsigned i;
	unsigned j;
	t_draw	**draw;

	i = 0;
	draw = fdf->draw;
	while (draw[i])
	{
		j = 0;
		while (draw[i][j + 1].color)
		{
			ft_drawLine(draw[i][j].point, draw[i][j + 1].point, fdf, draw[i][j].color);
			++j;
		}
		++i;
	}
}

void	ft_draw_x(t_fdf *fdf)
{
	unsigned i;
	unsigned j;
	t_draw	**draw;

	i = 0;
	draw = fdf->draw;
	j = 0;

	while (draw[i][j].color)
	{
		i = 0;
		while (draw[i + 1])
		{
			ft_drawLine(draw[i][j].point, draw[i + 1][j].point, fdf, draw[i][j].color);
			++i;
		}
		++j;
	}
}

void	ft_drow(t_fdf *fdf)
{
	ft_draw_y(fdf);
	ft_draw_x(fdf);

}