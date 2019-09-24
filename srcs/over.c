/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <gabshire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:18:40 by gabshire          #+#    #+#             */
/*   Updated: 2019/09/24 16:12:34 by gabshire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

void	skip_spaces(char **str)
{
	while (**str && **str == ' ')
		++*str;
}

void	color_grad(char *copy, t_draw *drow)
{
	if (*copy)
	{
		if (!drow->color && drow->h >= 0)
			drow->color = 0x00FFF1 * (drow->h + 1);
		else if (!drow->color && drow->h < 0)
			drow->color = 0x00FFF1 / (-drow->h);
	}
}
