/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 22:21:21 by dokkim            #+#    #+#             */
/*   Updated: 2021/01/12 19:43:31 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
int		ft_return_zero(char **line, char *save, char *buffer, ssize_t size);
int		ft_return_one(char **line, char **save, char *buffer, ssize_t size);
void	ft_repeat(char **temp, char **save, char *buffer, ssize_t size);
int		ft_strlen(char *str);
void	ft_memcpy(char *dst, char *src, int n);
int		ft_check(char *str, ssize_t size);
int		ft_save(char **line, char **save);

#endif
