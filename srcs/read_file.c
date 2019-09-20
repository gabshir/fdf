#include "fdf.h"

int	ft_len_str(const char *str)
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

int base_connect(char c, unsigned base)
{
	if (base <= 10)
		return (c >= '0' && c <= '9');
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= ('A' + base - 10)) || \
	(c >= 'a' && c <= ('a' + base - 10)));
}

int mini_atoi_base(char **str, unsigned base)
{
	long		nbr;
	int			f;
	unsigned	k;

	f = 1;
	nbr = 0;
	k = 0;
	while (**str && **str == ' ')
		++*str;
	if (**str == '-')
	{
		++*str;
		f = -1;
	}
	while (**str && base_connect(**str, base))
	{
		if ((**str >= 'A' && **str <= 'F') || (**str >= 'a' && **str <= 'f'))
			nbr = (nbr * base) + (**str - 'A' + 10);
		else
			nbr = (nbr * base) + (**str - '0');
		++*str;
		++k;
	}
	nbr *= f;
	if ((f == -1 && k == 0) || k > 14 || nbr > 2147483647 || nbr < -2147483648)
	{
		ft_printf("Incorrect color or h");
		exit(1);
	}
	return ((int)nbr);
}

t_draw	*one_str(char *str, t_fdf *fdf, int i)
{
	t_draw		*drow;
	int 		j;
	char 		*copy;

	j = 0;
	copy = str;
	if (!(drow = (t_draw *)ft_memalloc(sizeof(t_draw) * ft_len_str(str))))
		exit(1);
	while (*copy)
	{
		drow[j].x = j + 1;
		drow[j].y = i;
		drow[j].h = mini_atoi_base(&copy, 10);
		if (!(ft_strncmp(copy, ",0x", 3)))
		{
			copy += 3;
			drow[j].color = mini_atoi_base(&copy, 16);
		}
		if (*copy == ' ')
		{
			drow[j].color = drow[j].color ? drow[j].color : 0x00FFFF;
			while (*copy && *copy == ' ')
				++copy;
		}
		++j;
	}
	free(str);
	str = NULL;
	return (drow);
}

t_draw	**fill_matrix(char **map, t_fdf *fdf)
{
	unsigned len;
	unsigned i;
	t_draw	**drow;

	len = 0;
	i = 0;
	while (map[len])
		++len;
	if (!(drow = (t_draw **)ft_memalloc(sizeof(t_draw *) * (len + 1))))
		exit(1);
	drow[len] = NULL;
	while (map[i])
	{
		drow[i] = one_str(map[i], fdf, (int)i + 1);
		++i;
	}
	drow[i] = NULL;
	free(map);
	map = NULL;
	return (drow);

}

void	read_file(int fd, t_fdf *fdf)
{
	int o;
	char buf[10000];
	char *file;
	char **map;

	file = ft_strnew(0);
	while ((o = read(fd, buf, 9999)))
	{
		buf[o] = '\0';
		file = ft_strjoin_free(file, buf, 1);
	}
	if (!(map = ft_strsplit(file, '\n')))
	{
		ft_printf("empty file\n");
		exit(1);
	}
	fdf->draw = fill_matrix(map, fdf);

}

