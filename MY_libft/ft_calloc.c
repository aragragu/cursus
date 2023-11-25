/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:03:59 by aragragu          #+#    #+#             */
/*   Updated: 2023/11/25 18:50:17 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*data;

	data = malloc(count * size);
	if (!data)
		return (NULL);
	ft_bzero(data, count * size);
	return (data);
}

// int main(int argc, char *argv[])
// {
// 	char *ptr;

// 	if (argc < 2)
// 		return 0;
// 	ptr = ft_calloc(10, sizeof(char));
// 	ft_memcpy(ptr, argv[1], 10);
// 	printf("|%s|\n", ptr);
// 	printf("|%s|\n", argv[1]);
	
// }
