
#ifndef FDF_NEW_FDF_H

# include "../libft/includes/ft_printf.h"
# include "/usr/local/include/mlx.h"

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_draw
{
	int		h;
	int		color;
}				t_draw;

typedef struct	s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_draw	**draw;
}				t_fdf;

void ft_drawLine(t_point point1, t_point point2, t_fdf *fdf);

#define FDF_NEW_FDF_H

#endif //FDF_NEW_FDF_H
