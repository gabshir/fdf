
#ifndef FDF_H
# define FDF_H

# include "../libft/includes/ft_printf.h"
# include "/usr/local/include/mlx.h"
# include <math.h>

# define	width 1920
# define	height 1080

typedef struct	s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct	s_draw
{
	int		h;
	int		color;
	t_point point;
}				t_draw;

typedef struct	s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_draw	**draw;
}				t_fdf;

void ft_drawLine(t_point point1, t_point point2, t_fdf *fdf, double color);
void	read_file(int fd, t_fdf *fdf);
void	ft_drow(t_fdf *fdf);

#endif //FDF_NEW_FDF_H
