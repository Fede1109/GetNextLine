/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:37:41 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/10/05 11:18:19 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *buff)
{
	int		reader;
	char	*str_aux;
	char	*result;

	reader = 1;
	while (reader != 0)
	{
		reader = read(fd, buff, BUFFER_SIZE);
		if (reader == -1)
			return (NULL);
		buff[reader] = '\0';
		result = ft_strjoin(str_aux, buff);
		if(ft_strchr(buff, '\n'))
			break;
	}
	return (result);
}


char	*get_next_line(int fd)
{
	char		*str;
	static char	*buff;
	
    if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buff = (char * )malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	buff = ft_read_line(fd, buff);

}