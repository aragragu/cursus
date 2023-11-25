/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:06:44 by aragragu          #+#    #+#             */
/*   Updated: 2023/11/25 18:58:23 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

// int main(int argc, char *argv[])
// {
// 	int i = 'a';
	
// 	if (argc < 2)
// 		return 0;
// 	printf("%d\n", ft_isalnum(argv[1][0]));
// 	printf("%d", ft_isalnum(i));
// }