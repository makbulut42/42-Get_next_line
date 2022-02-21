/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 15:14:15 by makbulut          #+#    #+#             */
/*   Updated: 2022/01/31 21:12:11 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*first_line(int fd, char *buffer)
{
	char	*buff;
	int		read_byte;

	read_byte = 1;
	buff = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!find_new_line_char(buffer) && read_byte != 0)
	{
		read_byte = read (fd, buff, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free (buffer);
			free (buff);
			return (NULL);
		}
		buff[read_byte] = '\0';
		buffer = strjoin(buffer, buff);
	}
	free (buff);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*fd_buffer[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (0);
	fd_buffer[fd] = first_line(fd, fd_buffer[fd]);
	if (fd_buffer[fd] == NULL)
		return (NULL);
	line = get_new_line(fd_buffer[fd]);
	fd_buffer[fd] = get_new_buffer(fd_buffer[fd]);
	return (line);
}
