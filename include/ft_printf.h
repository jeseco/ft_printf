/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:02:27 by JEAN-SEBA         #+#    #+#             */
/*   Updated: 2021/10/25 16:10:58 by JEAN-SEBA        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
void	ft_putnbr(int n);
int		ft_printf(const char *str, ...);
int		ft_check_flag(const char flag, va_list ap, int count);
int		ft_put_i(va_list ap);
int		ft_put_p(va_list ap, int count);
int		ft_put_s(va_list ap, int count);
int		ft_put_u(va_list ap, int count);
int		ft_put_h(va_list ap, int count);
int		ft_put_upperh(va_list ap, int count);
int		ft_put_c(char c);
int		ft_intlen(int x);
int		ft_uintlen(unsigned int x);

#endif
