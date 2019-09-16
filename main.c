#include "fdf.h"

int		ft_close(int key, void *param)
{
	if (key == 53)
	{
		(void) param;
		exit(0);
	}
	return (0);
}

int main(int a, char **b)
{
	int		fd;
	t_fdf	fdf;
	t_point point1;
	t_point point2;

	point1.x = 13;
	point1.y = 1000;
	point2.y = 100;
	point2.y = 350;

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
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, 1920, 1080, "MLX 42" );
	ft_drawLine(point1, point2, &fdf);
	mlx_hook(fdf.win_ptr, 2, 0, ft_close, &fdf);
	mlx_loop(fdf.mlx_ptr);

	return 0;
}