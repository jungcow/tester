/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 22:21:03 by dokkim            #+#    #+#             */
/*   Updated: 2021/01/12 18:44:11 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_strlen(char *str)
{
	ssize_t	i;

	i = 0;
	if (str == NULL)
		return (0);
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
	while (j < n && src)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
}

int		ft_check(char *str, ssize_t size)
{
	ssize_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (i < size)
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
