/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:28:35 by rnovotny          #+#    #+#             */
/*   Updated: 2023/03/07 17:40:47 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (!mystring || !mystring[0])
		return (0);
	i = 0;
	outputline = (char *)malloc((ft_strlen(mystring, '\n') + 2) * sizeof(char));
	if (!outputline)
		return (0);
	while (mystring[i] != '\n' && mystring[i] != '\0')
	{
		outputline[i] = mystring[i];
		i++;
	}
	outputline[i] = mystring[i];
	outputline[i + 1] = '\0';
	mystring = move_on(mystring);
	return (outputline);
}
