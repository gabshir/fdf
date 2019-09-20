#include "fdf.h"

/*
 * вращение с клавиатуры
 */
int	rotation(int key, t_fdf *fdf)
{
	if (key == 53)
	{
		exit(0);
	}
	else if (key == 92)
		fdf->x_rotation = (fdf->x_rotation + 0.1);
	else if (key == 88)
		fdf->x_rotation = (fdf->x_rotation - 0.1);
	else if (key == 91)
		fdf->y_rotation = (fdf->y_rotation + 0.1);
	else if (key == 87)
		fdf->y_rotation = (fdf->y_rotation - 0.1);
	else if (key == 89)
		fdf->z_rotation = (fdf->z_rotation + 0.1);
	else if (key == 86)
		fdf->z_rotation = (fdf->z_rotation - 0.1);
	else if (key == 69)
		fdf->scale += 1;
	ft_drow(fdf);
	return (0);
}

//void	transform_array(t_draw **draw, t_fdf *fdf)
//{
//	unsigned i;
//	unsigned j;
//	int x;
//	int y;
//
//	i = 0;
//	while (draw[i])
//	{
//		j = 0;
//		while (draw[i][j].color)
//		{
//			x = draw[i][j].point.x * fdf->scale;
//			y = draw[i][j].point.y * fdf->scale;
//			draw[i][j].point.x = (x + y) * cos(0.46373398) + 500;
//			draw[i][j].point.y = -draw[i][j].h * fdf->scale + (x - y) * sin(0.46373398) + 500;
//			++j;
//		}
//		++i;
//	}
//}


void	ft_camera(t_fdf *fdf)
{
	ft_drow(fdf);
	mlx_hook(fdf->win_ptr, 2, 0, rotation, fdf);
}

