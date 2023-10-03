/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:37:31 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/10/02 16:45:10 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (res == NULL)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	size_len;
	size_t	i;

	i = 0;
	size_len = ft_strlen(s1);
	ptr = (char *)malloc(size_len + 1);
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, size_len);
	ptr[size_len] = '\0';
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = NULL;
	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == (unsigned char)c)
		{
			return (ptr);
		}
		ptr++;
	}
	if ((unsigned char)c == 0)
		return ((char *)ptr);
	return (NULL);
}