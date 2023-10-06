/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:37:41 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/10/06 15:02:22 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *buff)
{
	int		reader;
	char	*str_aux;
	char	*temp;

	reader = 1;
	str_aux = ft_strdup("");
	while (!(ft_strchr(buff, '\n')) && (reader != 0))
	{
		reader = read(fd, buff, BUFFER_SIZE);
		if (reader == -1)
		{
			free(str_aux);
			return (NULL);
		}		
		buff[reader] = '\0';
		temp = ft_strjoin(str_aux, buff);
		free(str_aux);
		str_aux = temp;
	}
	free(buff);
	return (str_aux);
}

char	*ft_get_lines(char *str)
{
	int		i;
	char	*res;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if(str[i] == '\0')
		return (0);
	res = ft_substr(str, i + 1, ft_strlen(str) - i - 1);
	if (!res)
		return (NULL);
	return (res);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buff)
	{
		buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (NULL);
	}	
	buff = ft_read_line(fd, buff);
	if (!buff)
		return (NULL);
	str = ft_get_lines(buff);
	return (str);
}

