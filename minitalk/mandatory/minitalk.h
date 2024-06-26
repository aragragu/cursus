/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 02:43:13 by aragragu          #+#    #+#             */
/*   Updated: 2024/03/26 09:58:41 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "../ft_printf/ft_printf.h"

int		ft_atoi(const char *str);
int		checkdigits(char *s);
void	bad_pid(void);
void	bad_pid_limit(void);
void	synthax_error(void);

#endif 