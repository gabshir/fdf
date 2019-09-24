/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_atoi_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <gabshire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 13:43:43 by gabshire          #+#    #+#             */
/*   Updated: 2019/09/24 16:01:31 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	base_connect(char c, int base)
{
	if (base <= 10)
		return (c >= '0' && c <= '9');
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= ('A' + base - 10)) || \
	(c >= 'a' && c <= ('a' + base - 10)));
}

int			mini_atoi_base(char **str, int base)
{
	long		nbr;
	int			f;
	unsigned	k;

	f = 1;
	nbr = 0;
	k = 0;
	skip_spaces(str);
	if (**str && **str == '-')
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
	if ((f == -1 && k == 0) || k > 14 || nbr * f > MAX_INT || nbr * f < MIN_INT)
		error("Incorrect color or h");
	return ((int)nbr * f);
}
