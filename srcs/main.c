#include <fdf.h>
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

void	index_in_array(t_draw **draw)
{
	unsigned i;
	unsigned j;
	unsigned px;
	unsigned py;
	double x;
	double y;
	int 	xp;
	int 	yp;

	i = 0;
	px = 0;
	while (draw[i])
	{
		j = 0;
		px += 25;
		py = 0;
		while (draw[i][j].color)
		{
			py += 25;
			draw[i][j].point.x = px;
			draw[i][j].point.y = py;
			x = draw[i][j].point.x;
			y = draw[i][j].point.y;
			draw[i][j].point.x = (x + y) * cos(0.46373398) + 500;
			draw[i][j].point.y = -draw[i][j].h + (x - y) * sin(0.46373398) + 500;
			//draw[i][j].color += draw[i][j].h * 0.95;
			++j;
		}
		++i;
	}
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
	index_in_array(fdf.draw);
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, width , height, "MLX 42" );
	ft_drow(&fdf);
	mlx_hook(fdf.win_ptr, 2, 0, ft_close, &fdf);
	mlx_loop(fdf.mlx_ptr);

	return 0;
}