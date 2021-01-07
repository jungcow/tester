/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 22:18:14 by dokkim            #+#    #+#             */
/*   Updated: 2021/01/08 01:31:16 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_returnone(char **line, char *save, char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n')
		i++;
	if (!(*line = (char *)malloc(sizeof(save) + (sizeof(char) * (i + 1)))))
		return (0);
	ft_memcpy(*line, save, ft_strlen(save));
	ft_memcpy(*line, buffer, i);
	(*line)[ft_strlen(*line)] = '\0';
	free(save);
	if (!(save = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1))))
		return (0);
	ft_memcpy(save, buffer + i, ft_strlen(buffer) - i);
	save[ft_strlen(save)] = '\0';
	return (1);
}

void	ft_returnzero(char **line, char *save, char *buffer)
{
	if (!(*line = (char *)malloc(sizeof(save) + 
					(sizeof(char) * (ft_strlen(buffer) + 1)))))
		return ;
	ft_memcpy(*line, save, ft_strlen(save));
	ft_memcpy(*line, buffer, ft_strlen(buffer));
	free(save);
}

int		get_next_line(int fd, char **line)
{
	char		*buffer;
	static char	*save;
	int			size;
	char		*temp;

	if (fd <= 2 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	while (size != 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == BUFFER_SIZE)
		{
			if (ft_check(buffer))
				return (ft_returnone(line, save, buffer));
			ft_returnzero(&temp, save, buffer);
			save = temp;
		}
		else
		{
			if (ft_check(buffer))
				return (ft_returnone(line, save, buffer));
			ft_returnzero(line, save, buffer);
			return (0);
		}
	}
	return (-1);
}
