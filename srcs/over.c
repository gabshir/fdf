/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabshire <gabshire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:18:40 by gabshire          #+#    #+#             */
/*   Updated: 2019/09/23 14:22:52 by gabshire         ###   ########.fr       */
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