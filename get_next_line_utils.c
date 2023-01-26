/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:29:11 by rnovotny          #+#    #+#             */
/*   Updated: 2023/01/26 10:36:40 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	n;

	n = 0;
	while (str[n] != 0)
		n++;
	return (n);
}

char *one_buffer(char const *s)
{
	int		len;
	int		i;
	char	*joined;

	len = ft_strlen(s);
	i = 0;
	joined = (char *)malloc((len + 1) * sizeof(char));
	if (!joined)
		return (0);
	while (i < len)
	{
		joined[i] = s[i];
		i++;
	}
	joined[i] = '\n';
	return (joined);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*joined;

	if (!s2)
		return (one_buffer(s1));
	if (!s1)
		return (one_buffer(s2));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	joined = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!joined)
		return (0);
	while (i < len1 + len2)
	{
		if (i < len1)
			joined[i] = s1[i];
		else
			joined[i] = s2[i - len1];
		i++;
	}
	joined[i] = '\0';
	return (joined);
}

char	*read_to_buffer(int fd, char *buffer)
{
	int		i;
	int		check;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	i = 0;
	check = 1;
	while (i < BUFFER_SIZE && check == 1)
	{
		check = read(fd, &buffer[i], 1);
		if (buffer[i] == '\n')
			check = 0;
		i++;
	}
	return (buffer);
}
