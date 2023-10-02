/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:37:41 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/10/02 18:35:55 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_get_line(int fd, char *str, char *res)
{
	int		line;
	char	*str_aux;

	line = 1;
	while (line != '\0')
	{
		line = read(fd, str, BUFFER_SIZE);
		if (line == -1)
			return (NULL);
		if (line == 0)
			break;
		res[line] = '\0';
		if (!res)
			res = ft_strdup("");
		str_aux = res;
		res = ft_strjoin(str_aux, str);
		free(str_aux);
		str_aux = NULL;
		if (ft_strchr(buf, '\n'))
			break;
	}
	return (res);
}


char *get_next_line(int fd)
{
	char	*str;
	char	*line;
	char	*res;
	
    if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	str = (char * )malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	line = ft_get_line(fd, str, res);
	free(str);
	str = NULL;
	if (!line)
		return (NULL);

	return (line);
}