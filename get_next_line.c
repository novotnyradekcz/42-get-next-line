/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:28:35 by rnovotny          #+#    #+#             */
/*   Updated: 2023/01/26 13:45:41 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: add a static variable to keep ytack of read lines

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*line;
	int			check;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	check = 1;
	buffer = 0;
	while (check == 1)
	{
		buffer = read_to_buffer(fd, buffer);
		if (buffer)
			line = ft_strjoin(line, buffer);
		if (buffer[0] == '\0' || buffer[ft_strlen(buffer) - 1] == '\n')
			check = 0;
		free(buffer);
	}
	return (line);
}
