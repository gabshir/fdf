#include "fdf.h"

void ft_drawLine(t_point point1, t_point point2, t_fdf *fdf)
{
	const int deltaX = abs(point1.x - point2.x);
	const int deltaY = abs(point1.y - point2.y);
	const int signX = point1.x < point2.x ? 1 : -1;
	const int signY = point1.y < point2.y ? 1 : -1;

	int error = deltaX - deltaY;
	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, point2.x, point2.y, 0xffffff );
	while(point1.x != point2.x || point1.y != point2.y)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, point1.x, point1.y, 0xffffff );
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
