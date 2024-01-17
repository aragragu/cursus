/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:01:38 by aragragu          #+#    #+#             */
/*   Updated: 2024/01/17 22:13:06 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len] != '\0')
		++len;
	return (len);
}

char	*ft_strlcpy(char *dest, char *src, int stop)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		if (stop && src[i] == '\n')
		{
			++i;
			break ;
		}
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *buff)
{
	char			*ptr;
	size_t			i;
	size_t			y;

	ptr = (char *)malloc((ft_strlen(s1) + ft_strlen(buff) + 1));
	if (!ptr)
		return (free(s1), s1 = NULL, NULL);
	i = 0;
	y = 0;
	while (s1 && s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	free(s1);
	s1 = NULL;
	while (buff && buff[y] != '\0')
	{
		ptr[i++] = buff[y++];
	}
	ptr[i] = '\0';
	return (ptr);
}
