/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 18:26:41 by student           #+#    #+#             */
/*   Updated: 2020/08/11 18:26:44 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_is_number(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		if (!(ft_isdigit(s[i]) || (i == 0 && s[i] == '-')))
			return (-1);
	return (1);
}

int		ft_word_count(char *s, char c)
{
	int	res;
	int i;

	res = 0;
	i = 0;
	while (*(s + i))
	{
		while (*(s + i) == c)
			i++;
		if (*(s + i) != c && *(s + i) != '\0')
			res++;
		while (*(s + i) != c && *(s + i) != '\0')
			i++;
	}
	return (res);
}

void	ft_free_lines(char ***lines)
{
	char	**line;
	int		i;

	line = *lines;
	i = 0;
	while (*line)
	{
		ft_strdel(line);
		line = &(*lines)[++i];
	}
	ft_memdel((void**)lines);
}
