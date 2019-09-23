/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proektion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <gabshire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:44:27 by gabshire          #+#    #+#             */
/*   Updated: 2019/09/23 12:54:55 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void		rotate_x(int *y, int *z, double alpha)
{
	int previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

static void		rotate_y(int *x, int *z, double beta)
{
	int previous_x;

	previous_x = *x;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
}

static void		rotate_z(int *x, int *y, double gamma)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gamma) - previous_y * sin(gamma);
	*y = previous_x * sin(gamma) + previous_y * cos(gamma);
}

static void		iso(t_draw *draw, t_fdf *fdf)
{
	int x;
	int y;

	x = draw->x;
	y = draw->y;
	draw->x = (draw->x - y) * cos(0.523599) + 500;
	draw->y = -draw->h + (x + draw->y) * sin(0.523599) + 500;
	fdf->y = 0;
	fdf->x = 0;
}

t_draw			operation(t_draw drow, t_fdf *fdf)
{
	t_draw temp;

	temp = drow;
	temp.h *= fdf->scale;
	temp.x *= fdf->scale;
	temp.y *= fdf->scale;
	if (fdf->proektion)
	{
		fdf->x_rotation = 0;
		fdf->y_rotation = 0;
		fdf->z_rotation = 0;
	}
	rotate_x(&temp.y, &temp.h, fdf->x_rotation);
	rotate_y(&temp.x, &temp.h, fdf->y_rotation);
	rotate_z(&temp.x, &temp.y, fdf->z_rotation);
	fdf->proektion == 2 ? iso(&temp, fdf) : 0;
	temp.y += fdf->y;
	temp.x += fdf->x;
	return (temp);
}
