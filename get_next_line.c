/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:28:35 by rnovotny          #+#    #+#             */
/*   Updated: 2023/01/27 10:43:17 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: add a static variable to keep ytack of read lines

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*outputline;
	static char	*mystring;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	buffer = 0;
	mystring = read_to_string(fd, buffer, mystring);
	i = 0;
	outputline = (char *)malloc((ft_strlen(mystring, '\n') + 1) * sizeof(char));
	while (mystring[i] != '\n' && mystring[i] != '\0')
	{
		outputline[i] = mystring[i];
		i++;
	}
	i++;
	outputline[i] = '\0';
	mystring = move_on(mystring);
	return (outputline);
}
