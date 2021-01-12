/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 22:18:14 by dokkim            #+#    #+#             */
/*   Updated: 2021/01/12 20:27:45 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_return_one(char **line, char **save, char *buffer, ssize_t size)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n')
		i++;
	if (!(*line = (char *)malloc(ft_strlen(*save) + (sizeof(char) * (i + 1)))))
	{
		free(*save);
		return (-1);
	}
	**line = '\0';
	ft_memcpy(*line, *save, ft_strlen(*save));
	ft_memcpy(*line, buffer, i);
	free(*save);
	if (!(*save = (char *)malloc(sizeof(char) * (size - i))))
	{
		free(*line);
		return (-1);
	}
	**save = '\0';
	ft_memcpy(*save, buffer + i + 1, size - i - 1);
	return (1);
}

int		ft_return_zero(char **line, char *save, char *buffer, ssize_t size)
{
	if (!(*line = (char *)malloc(ft_strlen(save)
	+ (sizeof(char) * (size + 1)))))
	{
		free(save);
		return (-1);
	}
	**line = '\0';
	ft_memcpy(*line, save, ft_strlen(save));
	ft_memcpy(*line, buffer, size);
	free(save);
	return (0);
}

void	ft_repeat(char **temp, char **save, char *buffer, ssize_t size)
{
	if (!(*temp = (char *)malloc(ft_strlen(*save)
	+ (sizeof(char) * (size + 1)))))
	{
		free(*save);
		return ;
	}
	**temp = '\0';
	ft_memcpy(*temp, *save, ft_strlen(*save));
	ft_memcpy(*temp, buffer, size);
	free(*save);
	*save = *temp;
}

int		ft_save(char **line, char **save)
{
	ssize_t	i;
	ssize_t len;
	char	*temp;

	i = 0;
	len = ft_strlen(*save);
	while ((*save)[i] != '\n')
		i++;
	if (!(*line = (char *)malloc(sizeof(char) * (i + 1))))
	{
		free(*save);
		return (-1);
	}
	**line = '\0';
	ft_memcpy(*line, *save, i);
	if (!(temp = (char *)malloc(sizeof(char) * (len - i))))
	{
		free(*line);
		free(*save);
		return (-1);
	}
	*temp = '\0';
	ft_memcpy(temp, *save + i + 1, len - i - 1);
	*save = temp;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE];
	static char	*save = NULL;
	ssize_t		size;
	char		*temp;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if (ft_check(save, ft_strlen(save)))
		return (ft_save(line, &save));
	while (size >= 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (ft_check(buffer, size))
			return (ft_return_one(line, &save, buffer, size));
		if (size == BUFFER_SIZE)
		{
			ft_repeat(&temp, &save, buffer, size);
		}
		else if (size >= 0)
			return (ft_return_zero(line, save, buffer, size));
	}
	return (-1);
}
