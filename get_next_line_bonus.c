/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:28:35 by rnovotny          #+#    #+#             */
/*   Updated: 2023/02/09 17:04:27 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*output_line(char *mystr)
{
	int		i;
	char	*outputline;

	i = 0;
	outputline = (char *)malloc((ft_strlen(mystr, '\n') + 2) * sizeof(char));
	if (!outputline)
		return (0);
	while (mystr[i] != '\n' && mystr[i] != '\0')
	{
		outputline[i] = mystr[i];
		i++;
	}
	outputline[i] = mystr[i];
	outputline[i + 1] = '\0';
	return (outputline);
}

char	*get_next_line(int fd)
{
	char		*outputline;
	static char	*mystring[32768];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	mystring[fd] = read_to_string(fd, mystring[fd]);
	if (!mystring[fd])
		return (0);
	outputline = output_line(mystring[fd]);
	mystring[fd] = move_on(mystring[fd]);
	return (outputline);
}
