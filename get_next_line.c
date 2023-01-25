/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:28:35 by rnovotny          #+#    #+#             */
/*   Updated: 2023/01/23 22:28:43 by rnovotny         ###   ########.fr       */
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
	char *buffer;
	char *line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	line = ft_strjoin(line, buffer);
	return (line);
}