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
IDEA: first read line to find it's length, 
	then malloc and read again, saving into mallocked string 
*/

char *get_next_line(int fd)
{
	char *buffer;


	return (buffer);
}