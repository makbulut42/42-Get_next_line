/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:11:46 by makbulut          #+#    #+#             */
/*   Updated: 2022/02/02 12:51:08 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(char *buf);
char	*get_next_line(int fd);
char	*get_new_line(char *buffer);
char	*first_line(int fd, char *buffer);
char	*strjoin(char *buffer, char *new_buffer);
char	*get_new_buffer(char *buffer);
int		find_new_line_char(char *buffer);

#endif
