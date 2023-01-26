/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:28:35 by rnovotny          #+#    #+#             */
/*   Updated: 2023/01/26 08:56:05 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
TODO: make buffer-size independent - 
	- read char by char until \n or end of file is encountered
IDEA: use strjoin to add buffer-sized strings until we get to a \n,
	then print
*/

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;
	int		check;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	while (check == 1 && line[ft_strlen(line) - 1] != '\n')
	{
		buffer = read_to_buffer(fd, buffer);
		line = ft_strjoin(line, buffer);
		free(buffer);
	}
	return (line);
}