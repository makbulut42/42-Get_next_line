/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 13:08:31 by makbulut          #+#    #+#             */
/*   Updated: 2022/01/31 21:10:50 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*first_line(int fd, char *buffer)
{
	char	*buff;
	int		read_byt;

	read_byt = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	while (!find_new_line_char(buffer) && read_byt != 0)
	{
		read_byt = read (fd, buff, BUFFER_SIZE);
		if (read_byt == -1)
		{
			free (buffer);
			free (buff);
			return (0);
		}	
		buff[read_byt] = 0;
		buffer = strjoin(buffer, buff);
	}
	free(buff);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = first_line(fd, buffer);
	if (buffer == 0)
		return (0);
	line = get_new_line(buffer);
	buffer = get_new_buffer(buffer);
	return (line);
}
/*
int	main(void)
{
	int	fd;

	fd = open ("kirmizikafalikiz.txt", O_RDONLY);
	char *a = get_next_line(fd);
	char *b = get_next_line(fd);
	char *c = get_next_line(fd);
	char *d = get_next_line(fd);
	char *e = get_next_line(fd);

	printf("%s", a);
	printf("%s", b);
	printf("%s", c);
	printf("%s", d);
	printf("%s", e);
	close (fd);
}
*/