/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:37:41 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/10/05 12:50:24 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *buff)
{
	int		reader;
	char	*str_aux;

	reader = 1;
	str_aux = ft_strdup("");
	while (ft_strchr(buff, '\n') && (reader != 0))
	{
		reader = read(fd, buff, BUFFER_SIZE);
		if (reader == -1)
			return (NULL);
		buff[reader] = '\0';
		str_aux = ft_strjoin(str_aux, buff);
		free(buff);
	}
	return (str_aux);
}

char	*ft_get_lines(char *str)
{
	int		i;
	char	*res;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] || str[i] != '\n')
		i++;
	res = ft_substr(str, i + 1, ft_strlen(str) - i);
	if (*res == '\0')
	{
		free(res);
		res = NULL;
	}
	return (res);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*buff;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	buff = ft_read_line(fd, buff);
	if (!buff)
		return (NULL);
	free(buff);
	buff = NULL;
	str = ft_get_lines(buff);
	return (buff);
}

/*
1. Añadir protecciones al str_join
2. Meter el memcpy
TODO:
3. Función los trozos que sobran
*/
