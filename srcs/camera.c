/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <gabshire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:20:03 by gabshire          #+#    #+#             */
/*   Updated: 2019/09/23 13:04:35 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		rotation(int key, t_fdf *fdf)
{
	if (key == 92)
		fdf->x_rotation += 0.1;
	else if (key == 88)
		fdf->x_rotation -= 0.1;
	else if (key == 91)
		fdf->y_rotation += 0.1;
	else if (key == 87)
		fdf->y_rotation -= 0.1;
	else if (key == 89)
		fdf->z_rotation += 0.1;
	else if (key == 86)
		fdf->z_rotation -= 0.1;
	return (0);
}

static int		bias(int key, t_fdf *fdf)
{
	if (key == 124)
		fdf->x += 5;
	else if (key == 123)
		fdf->x -= 5;
	else if (key == 126)
		fdf->y -= 5;
	else if (key == 125)
		fdf->y += 5;
	return (0);
}

static void		free_all(t_fdf *fdf)
{
	unsigned i;

	i = 0;
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	while (fdf->draw[i])
	{
		free(fdf->draw[i]);
		fdf->draw[i] = NULL;
		++i;
	}
	free(fdf->draw);
	fdf->draw = NULL;
	free(fdf->map);
}

static int		hook(int key, t_fdf *fdf)
{
	if (key == 53)
	{
		free_all(fdf);
		exit(0);
	}
	if (key == 92 || key == 88 || key == 91
	|| key == 87 || key == 89 || key == 86)
		rotation(key, fdf);
	else if (key == 69)
		fdf->scale += 1;
	else if (key == 78)
		fdf->scale -= 1;
	else if (key == 124 || key == 123 || key == 126 || key == 125)
		bias(key, fdf);
	else if (key == 83)
		fdf->proektion = 1;
	else if (key == 84)
		fdf->proektion = 2;
	ft_drow(fdf);
	return (0);
}

void			ft_camera(t_fdf *fdf)
{
	ft_drow(fdf);
	mlx_hook(fdf->win_ptr, 2, 0, hook, fdf);
}
