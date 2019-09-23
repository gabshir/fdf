/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <gabshire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:20:30 by gabshire          #+#    #+#             */
/*   Updated: 2019/09/23 20:15:21 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	inc_mlx(t_fdf *fdf)
{
	int g;

	g = 1;
	if (!(fdf->mlx_ptr = mlx_init()))
		error("mlx = NULL");
	if (!(fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH,
			HIGHT, "FDF")))
		error("windows = NULL");
	if (!(fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, WIDTH, HIGHT)))
		error("image = NULL");
	if (!(fdf->map = (int*)mlx_get_data_addr(fdf->img_ptr, &g,
			&fdf->size_line, &fdf->endian)))
		error("data_addr = NULL");
	fdf->scale = 25;
}

int		main(int a, char **b)
{
	int		fd;
	t_fdf	fdf;

	if (a != 2)
		error("Usage : enter an argument");
	fd = ft_read_file(b[1]);
	ft_bzero(&fdf, sizeof(fdf));
	read_file(fd, &fdf);
	inc_mlx(&fdf);
	ft_camera(&fdf);
	mlx_loop(fdf.mlx_ptr);
	close(fd);
	return (0);
}
