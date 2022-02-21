/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 13:07:40 by makbulut          #+#    #+#             */
/*   Updated: 2022/02/02 12:31:59 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *buf)
{
	size_t	index;

	index = 0;
	if (!buf)
		return (0);
	while (buf[index])
		index++;
	return (index);
}

char	*strjoin(char *s1, char *s2)
{
	int		index;
	int		index_join;
	char	*join;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (0);
	join = malloc(sizeof(char) * (ft_strlen((char *) s1) \
	+ ft_strlen((char *)s2) + 1));
	if (!join)
		return (0);
	index = 0;
	index_join = 0;
	while (s1[index])
		join[index_join++] = s1[index++];
	index = 0;
	while (s2[index])
		join[index_join++] = s2[index++];
	join[index_join] = 0;
	free (s1);
	return (join);
}

int	find_new_line_char(char *buffer)
{
	int	index;

	index = 0;
	if (!buffer)
		return (0);
	while (buffer[index])
	{
		if (buffer[index] == '\n')
			return (1);
		index++;
	}
	return (0);
}

char	*get_new_line(char *buffer)
{
	char	*line;
	int		index;
	int		newline;

	newline = find_new_line_char(buffer);
	index = 0;
	if (!buffer[index])
		return (0);
	while (buffer[index] != '\0' && buffer[index] != '\n')
		index++;
	line = malloc(sizeof(char) * (index + newline + 1));
	index = 0;
	while (buffer[index] != '\0' && buffer[index] != '\n')
	{
		line[index] = buffer[index];
		index++;
	}
	if (buffer[index] == '\n')
		line[index++] = '\n';
	line[index] = '\0';
	return (line);
}

char	*get_new_buffer(char *buffer)
{
	char	*newbuffer;
	size_t	index;
	size_t	join;

	index = 0;
	join = 0;
	while (buffer[index] != '\0' && buffer[index] != '\n')
		index++;
	if (!buffer[index])
	{
		free (buffer);
		return (0);
	}
	newbuffer = malloc(sizeof(char) * (ft_strlen(buffer) - index + 1));
	if (!newbuffer)
		return (0);
	index++;
	while (buffer[index] != '\0')
		newbuffer[join++] = buffer[index++];
	newbuffer[join] = '\0';
	free(buffer);
	return (newbuffer);
}

/*
int main(void)
{
	char *str;
	char *b;
	str = "MehmetEren";
	b = malloc(sizeof(char *) * ft_strlen(str));
	printf("%s", get_new_buffer(b));
}
*/
/*
int main(void)
{
	char *buffer;
	buffer = "Mehmet Eren Akbulut\n";
	printf("%s", get_new_line(buffer));
}
*//*
int main()
{
	char *buffer;
	int d;

	buffer = "Mehmet\n";
	d = find_new_line_char(buffer);
	printf("%d", d);

}
*/

/*
int main()
{
	char *s1 = "Mehmet";
	char *s2 = "Eren";

	printf("%s", strjoin(s1, s2));
}
*/
