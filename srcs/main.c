#include <fdf.h>

void	inc_mlx(t_fdf *fdf)
{
	int g;

	g = 1;
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH , HIGHT, "FDF" );
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, WIDTH, HIGHT);
	fdf->map = (int*)mlx_get_data_addr(fdf->img_ptr, &g, &fdf->size_line, &fdf->endian);
	fdf->scale = 25;
	//			draw[i][j].point.x = (x + y) * cos(0.46373398) + 500;
//			draw[i][j].point.y = -draw[i][j].h * fdf->scale + (x - y) * sin(0.46373398) + 500;
//	fdf->y_rotation = -0.615472907;
//	fdf->x_rotation	= -0.785398;
}

int main(int a, char **b)
{
	int		fd;
	t_fdf	fdf;

	if (a != 2)
	{
		ft_printf("Usage : file not found\n");
		exit(1);
	}
	fd = ft_read_file(b[1]);
	if (fd == -1)
	{
		ft_printf("block file\n");
		exit(1);
	}
	ft_bzero(&fdf, sizeof(fdf));
	read_file(fd, &fdf);
	inc_mlx(&fdf);
	ft_camera(&fdf);
	mlx_loop(fdf.mlx_ptr);

	return 0;
}