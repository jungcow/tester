/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:00:18 by dokkim            #+#    #+#             */
/*   Updated: 2021/01/12 20:04:47 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	char *line;
	int fd;
	int len;

	fd = open("sample.txt", O_CREAT | O_RDONLY, 0777);
	while ((len = get_next_line(fd, &line)) == 1)
	{
		printf("%d, %s\n", len,  line);
		free(line);
	}
	printf("%d, %s\n", len, line);
	return (0);
}

