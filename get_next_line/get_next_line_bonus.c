/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:23:10 by aragragu          #+#    #+#             */
/*   Updated: 2023/12/28 14:33:05 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_line(char *str, int fd)
{
	char	*buff;
	int		read_bytes;

	buff = (char *)malloc((BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(str, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			free(str);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		str = ft_strjoin(str, buff);
	}
	return (free(buff), str);
}

char	*get_the_line(char *s)
{
	char	*str;
	size_t	len;
	int		i;

	if (s[0] == '\0')
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		++i;
	len = i + (s[i] == '\n');
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, 1);
	return (str);
}

char	*new_stash(char *str)
{
	char	*s;
	int		start;

	start = 0;
	while (str[start] != '\0' && str[start] != '\n')
		++start;
	if (str[start] == '\0')
	{
		free(str);
		return (NULL);
	}
	s = malloc(sizeof(char) * (ft_strlen(str + start) + 1));
	if (!s)
		return (NULL);
	ft_strlcpy(s, str + start + 1, 0);
	return (free(str), s);
}

char	*get_next_line(int fd)
{
	static char		*stash[OPEN_MAX];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	stash[fd] = read_line(stash[fd], fd);
	if (!stash[fd])
		return (NULL);
	line = get_the_line(stash[fd]);
	stash[fd] = new_stash(stash[fd]);
	return (line);
}

// #include <stdio.h>

// int main()
// {
//    int fd, fc, fg;
//     char *line;
//     fd = open("text1.txt", O_CREAT | O_RDONLY);
//     fc = open("text2.txt", O_CREAT | O_RDONLY);
//     fg = open("text3.txt", O_CREAT | O_RDONLY);
//     char *str, *ptr, *gtr;
//     printf("fd = |%d|\t fc = |%d|\t fg = |%d|\n", fd, fc, fg);
//     int i = 0;
//     while(i < 3)
//     {
//         str = get_next_line(fd);
//         printf("%s", str);
//         ptr = get_next_line(fc);
//         printf("%s", ptr);
//         gtr = get_next_line(fg);
//         printf("%s", gtr);
//         i++;
//     }
// }