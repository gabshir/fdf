#include "fdf.h"

unsigned	ft_len_str(char *str)
{
	unsigned	i;
	unsigned	j;

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

int one_coord(const char *str, unsigned *i)
{
	unsigned	j;
	int			f;
	int			h;

	j = *i;
	f = 1;
	h = 0;
	if (str[j] && str[j] == '-')
	{
		++j;
		f = -1;
	}
	while (str[j] && str[j] >= '0' && str[j] <= '9')
	{
		h = h * 10 + str[j] - '0';
		++j;
	}
	h *= f;
	if (j - *i > 14 || h > 2147483647 || h < -2147483648
	|| (f == -1 && j - *i == 1))
	{
		ft_printf("not valid height");
		exit(1);
	}
	*i = j;
	return (h);
}

int one_color(char *str, unsigned *i)
{
	unsigned j;
	int 	t;

	j = *i;
	if (str[j] == ' ')
	{
		++*i;
		return (0xffffff);
	}
	if ((t = ft_strncmp(str, ",0x", 3)))
	{
		ft_printf("not valid parameter");
		exit(1);
	}


}

t_draw	*one_str(char *str)
{
	unsigned 	i;
	t_draw		*drow;
	unsigned 	j;

	i = 0;
	j = 0;
	if (!(drow = ft_memalloc(sizeof(drow) * ft_len_str(str))))
		exit(1);
	while (str[i])
	{
		drow[j].h = one_coord(str, &i);

	}
}

t_draw	**fill_matrix(char **map)
{
	unsigned len;
	unsigned i;
	t_draw	**drow;

	len = 0;
	i = 0;
	while (map[len])
		++len;
	if (!(drow = ft_memalloc(sizeof(t_draw *) * (len + 1))))
		exit(1);
	drow[len] = NULL;
	while (i < len)
	{
		drow[i] =
	}

}

void	read_file(int fd, t_fdf *fdf)
{
	int o;
	char buf[10000];
	char *file;
	char **map;

	file = ft_strnew(0);
	while (!(o = read(fd, buf, 9999)))
	{
		buf[o] = '\0';
		file = ft_strjoin_free(file, buf, 1);
	}
	if (!(map = ft_strsplit(file, '\n')))
	{
		ft_printf("empty file\n");
		exit(1);
	}

}

