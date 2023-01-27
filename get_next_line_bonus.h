/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:29:14 by rnovotny          #+#    #+#             */
/*   Updated: 2023/01/27 12:15:09 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*move_on(char *str);
char	*read_to_string(int fd, char *buffer, char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str, char end);

#endif