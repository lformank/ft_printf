/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lformank <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:56:50 by lformank          #+#    #+#             */
/*   Updated: 2024/06/26 12:47:01 by lformank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>

int	ft_char(char ch, int count);
int	ft_str(char *str, int count);
int	ft_ptr(unsigned long num, int count);
int	ft_int(int num, int count);
int	ft_unsignedint(unsigned int num, int count);
int	ft_lowhexdec(unsigned int num, int count);
int	ft_uphexdec(unsigned int num, int count);
int	ft_putnbr_fd(int n, int fd);
int	ft_printf(const char *format, ...);

#endif
