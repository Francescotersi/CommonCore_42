/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:31:00 by lparolis          #+#    #+#             */
/*   Updated: 2024/12/10 15:27:46 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
int		ft_printer(const char *str, va_list(arglist));
int		ft_hexprint_upper(unsigned int nb);
int		ft_hexprint_lower(unsigned int nb);
int		ft_putaddress(unsigned long long nb);
int		ft_putchar_count_fd(char c, int fd);
int		ft_putstr_count_fd(char *s, int fd);
int		ft_unsigned_numlen(unsigned int nb);
int		ft_numlen(int nb);
int		ft_retputnbr_fd(int n, int fd);
int		ft_unsigned_putnbr_fd(unsigned int n, int fd);
int		ft_putaddress_check(unsigned long long nb);
int		ft_intcheck(int n, int fd);

#endif