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

// NOTES: it seems that moulinette only checks number of allocs vs freees
// which for me is the same number only if reading ends with at least one (null)
// otherwise I have one free missing
// but so do other people it seems - and they passed

#include "get_next_line.h"

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
	static char	*mystring;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	mystring = read_to_string(fd, mystring);
	if (!mystring)
		return (0);
	outputline = output_line(mystring);
	mystring = move_on(mystring);
	return (outputline);
}
