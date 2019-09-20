#include "fdf.h"

void ft_drawLine(t_draw point1, t_draw point2, t_fdf *fdf, int color)
{
	const int deltaX = abs(point1.x - point2.x);
	const int deltaY = abs(point1.y - point2.y);
	const int signX = point1.x < point2.x ? 1 : -1;
	const int signY = point1.y < point2.y ? 1 : -1;
	int t;

	int error = deltaX - deltaY;
	while(point1.x != point2.x || point1.y != point2.y)
	{
		t = point1.x + point1.y * WIDTH;
		if (point1.x < WIDTH  && point1.y < HIGHT && point1.x > 0 && point1.y > 0 && t < WIDTH * HIGHT && t > 0)
		{
			fdf->map[t] = color;
		}
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

static void	rotate_x(int *y, int *z, double alpha)
{
	int previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

static void	rotate_y(int *x, int *z, double beta)
{
	int previous_x;

	previous_x = *x;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
}

/*
** Rotate coordinate by z axis
*/

static void	rotate_z(int *x, int *y, double gamma)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gamma) - previous_y * sin(gamma);
	*y = previous_x * sin(gamma) + previous_y * cos(gamma);
}

static void	scale(int *x, int *y, int *z, int scale)
{
	*x *= scale;
	*y *= scale;
	*z *= scale;
}

t_draw	operation(t_draw drow, t_fdf *fdf)
{
	t_draw temp;

	temp = drow;
	scale(&temp.x, &temp.y, &temp.h, fdf->scale);
	rotate_x(&temp.y, &temp.y, fdf->x_rotation);
	rotate_y(&temp.x, &temp.y, fdf->y_rotation);
	rotate_z(&temp.x, &temp.y, fdf->z_rotation);
	temp.x = (temp.x - temp.y) * cos(0.523599) + 500;
	temp.y = -temp.h + (temp.x + temp.y) * sin(0.523599) + 500;
	return (temp);
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
			ft_drawLine(operation(draw[i][j], fdf), operation(draw[i][j + 1], fdf), fdf, draw[i][j].color);
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
			ft_drawLine(operation(draw[i][j], fdf), operation(draw[i + 1][j],fdf),fdf, draw[i][j].color);
			++i;
		}
		++j;
	}
}

void	ft_drow(t_fdf *fdf)
{
	ft_bzero(fdf->map, WIDTH * HIGHT * sizeof(int));
	ft_draw_y(fdf);
	ft_draw_x(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
}