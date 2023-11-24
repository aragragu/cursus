/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:43:35 by aragragu          #+#    #+#             */
/*   Updated: 2023/11/10 22:13:29 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int			z;
	size_t		i;
	char		*ptr;

	z = 0;
	i = ft_strlen(s1);
	ptr = (char *)malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (NULL);
	while (s1[z])
	{
		ptr[z] = s1[z];
		z++;
	}
	ptr[z] = '\0';
	return (ptr);
}
