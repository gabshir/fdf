/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <gabshire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:20:14 by gabshire          #+#    #+#             */
/*   Updated: 2019/09/24 16:10:43 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_len_str(const char *str)
{
	unsigned	i;
	int			j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			++j;
		++i;
	}
	return (j + 1);
}

static void		index_str_and_st(t_draw *drow, int i, int j, char **copy)
{
	char *temp;

	drow->x = j + 1;
	drow->y = i;
	temp = *copy;
	drow->h = mini_atoi_base(copy, 10);
	if ((**copy && **copy != ' ' && **copy != ',') || temp == *copy)
		error("not correct argument");
}

static t_draw	*one_str(char *str, int i, t_fdf *fdf)
{
	t_draw	*drow;
	int		j;
	char	*copy;

	j = 0;
	copy = str;
	if (!(drow = (t_draw *)ft_memalloc(sizeof(t_draw) * ft_len_str(str))))
		error("Error malloc");
	while (*copy)
	{
		index_str_and_st(&drow[j], i, j + 1, &copy);
		if (!(ft_strncmp(copy, ",0x", 3)))
		{
			copy += 3;
			drow[j].color = mini_atoi_base(&copy, 16);
		}
		*copy && *copy == ',' ? error("not correct argument") : 0;
		skip_spaces(&copy);
		color_grad(copy, &drow[j]);
		++j;
	}
	fdf->hight == j || fdf->hight == 0 ? fdf->hight = j : error("Wrong len");
	return (drow);
}

static t_draw	**fill_matrix(char **map, t_fdf *fdf)
{
	unsigned	len;
	int			i;
	t_draw		**drow;

	len = 0;
	i = 0;
	while (map[len])
		++len;
	if (!(drow = (t_draw **)ft_memalloc(sizeof(t_draw *) * (len + 1))))
		error("Error malloc");
	drow[len] = NULL;
	while (map[i])
	{
		drow[i] = one_str(map[i], i + 1, fdf);
		free(map[i]);
		map[i] = NULL;
		++i;
	}
	drow[i] = NULL;
	free(map);
	fdf->width = i;
	map = NULL;
	return (drow);
}

void			read_file(int fd, t_fdf *fdf)
{
	int		o;
	char	buf[10000];
	char	*file;
	char	**map;

	file = ft_strnew(0);
	while ((o = read(fd, buf, 9999)))
	{
		buf[o] = '\0';
		file = ft_strjoin_free(file, buf, 1);
	}
	if (!(map = ft_strsplit(file, '\n')))
		error("error malloc");
	!map[0] ? error("empty file") : 0;
	fdf->draw = fill_matrix(map, fdf);
}
