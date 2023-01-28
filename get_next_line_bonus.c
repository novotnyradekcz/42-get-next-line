/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:28:35 by rnovotny          #+#    #+#             */
/*   Updated: 2023/01/28 15:49:53 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*outputline;
	static char	*mystring[32768];
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	buffer = 0;
	mystring[fd] = read_to_string(fd, buffer, mystring[fd]);
	if (!mystring[fd] || !mystring[fd][0])
		return (0);
	i = 0;
	outputline = malloc((ft_strlen(mystring[fd], '\n') + 1) * sizeof(char));
	if (!outputline)
		return (0);
	while (mystring[fd][i] != '\n' && mystring[fd][i] != '\0')
	{
		outputline[i] = mystring[fd][i];
		i++;
	}
	outputline[i] = mystring[fd][i];
	outputline[i + 1] = '\0';
	mystring[fd] = move_on(mystring[fd]);
	return (outputline);
}
