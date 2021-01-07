/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 22:21:03 by dokkim            #+#    #+#             */
/*   Updated: 2021/01/07 22:19:00 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_memcpy(char *dst, char *src, int n)
{
	int	i;
	int	j;

	i = ft_strlen(dst);
	j = 0;
	while (src[i] && i < n)
	{
		dst[i] = dst[j];
		i++;
		j++;
	}
	dst[i] = '\0';
}

int		ft_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

