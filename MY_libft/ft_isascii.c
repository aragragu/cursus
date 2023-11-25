/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:15:27 by aragragu          #+#    #+#             */
/*   Updated: 2023/11/25 19:02:50 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

// int main(int argc, char *argv[])
// {
// 	int i = 'a';
	
// 	if (argc < 2)
// 		return 0;
// 	printf("%d\n", ft_isascii(argv[1][0]));
// 	printf("%d", ft_isascii(i));
// }