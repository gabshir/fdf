/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <gabshire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:19:14 by gabshire          #+#    #+#             */
/*   Updated: 2019/09/24 16:11:26 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/ft_printf.h"
# include "/usr/local/include/mlx.h"
# include <math.h>
# define WIDTH 1920
# define HIGHT 1080
# define MIN_INT -2147483648
# define MAX_INT 2147483647

typedef struct	s_draw
{
	int			h;
	int			color;
	int			x;
	int			y;
}				t_draw;

typedef struct	s_line
{
	int			delta_x;
	int			delta_y;
	int			sign_x;
	int			sign_y;
	int			error;
	int			error2;
	int			t;
}				t_line;

typedef struct	s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*map;
	int			size_line;
	int			endian;
	int			scale;
	t_draw		**draw;
	double		x_rotation;
	double		y_rotation;
	double		z_rotation;
	int			x;
	int			y;
	int			hight;
	int			width;
	int			proektion;
}				t_fdf;

void			read_file(int fd, t_fdf *fdf);
void			error(char *str);
int				mini_atoi_base(char **str, int base);
void			ft_drow(t_fdf *fdf);
void			ft_camera(t_fdf *fdf);
void			skip_spaces(char **str);
t_draw			operation(t_draw drow, t_fdf *fdf);
void			color_grad(char *copy, t_draw *drow);
int				get_color(t_draw current, t_draw start, t_draw end,
t_line delta);

#endif
