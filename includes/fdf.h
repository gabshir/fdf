
#ifndef FDF_H
# define FDF_H

# include "../libft/includes/ft_printf.h"
# include "/usr/local/include/mlx.h"
# include <math.h>

# define	WIDTH 1920
# define	HIGHT 1080

typedef struct	s_draw
{
	int		h;
	int		color;
	int 	x;
	int		y;
}				t_draw;

typedef struct	s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int 	*map;
	int 	size_line;
	int 	endian;
	int		scale;
	t_draw	**draw;
	double 		x_rotation;
	double 		y_rotation;
	double 		z_rotation;
}				t_fdf;

void ft_drawLine(t_draw point1, t_draw point2, t_fdf *fdf, int color);
void	read_file(int fd, t_fdf *fdf);
void	ft_drow(t_fdf *fdf);
void	ft_camera(t_fdf *fdf);

#endif //FDF_NEW_FDF_H
