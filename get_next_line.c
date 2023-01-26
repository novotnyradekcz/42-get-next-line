/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:28:35 by rnovotny          #+#    #+#             */
/*   Updated: 2023/01/26 10:31:10 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;
	int		check;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	check = 1;
	buffer = 0;
	line = 0;
	while (check == 1)
	{
		buffer = read_to_buffer(fd, buffer);
		if (buffer)
			line = ft_strjoin(line, buffer);
		if (!buffer || buffer[ft_strlen(buffer) - 1] == '\n')
			check = 0;
		free(buffer);
	}
	return (line);
}
