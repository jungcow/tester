/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 22:21:21 by dokkim            #+#    #+#             */
/*   Updated: 2021/01/08 01:32:55 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
void	ft_returnzero(char **line, char *save, char *buffer);
int		ft_returnone(char **line, char *save, char *buffer);
int		ft_strlen(char *str);
void	ft_memcpy(char *dst, char *src, int n);
int		ft_check(char *str);

#endif
