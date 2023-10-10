/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:37:41 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/10/10 11:57:35 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_write_in_aux(int fd, char *aux)
{
	char	*buffer;
	int		check;

	check = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!(ft_strchr(aux, '\n')) && check != 0)
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check == -1)
		{
			free(buffer);			
			return (NULL);
		}
		buffer[check] = '\0';
		aux = ft_strjoin(aux, buffer);
	}
	free(buffer);	
	return (aux);
}

char	*get_next_line(int fd)
{
	char			*line;	
	static char		*aux;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	aux = ft_write_in_aux(fd, aux);
	if (!aux)
		return (NULL);
	line = ft_extract_line(aux);
	aux = ft_new_static(aux);
	// system("leaks a.out");
	return (line);
}

int main(void)
{
	int fd1;
	char	*str;
	
	fd1 = open("hola.txt", O_RDONLY);
	str = get_next_line(fd1);
	printf("%s\n", str);
	str = get_next_line(fd1);
	printf("%s\n", str);
	str = get_next_line(fd1);
	printf("%s\n", str);
	str = get_next_line(fd1);
	printf("%s\n", str);
	close(fd1);
	return (0);
}