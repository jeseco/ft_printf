/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:01:00 by JEAN-SEBA         #+#    #+#             */
/*   Updated: 2021/10/22 15:37:48 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h" 

int	ft_printf_helper(const char *str, va_list ap, int count)
{
	int	i;
	int	str_len;

	i = 0;
	str_len = ft_strlen(str + 1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count = ft_check_flag((char)str[i], ap, count);
		}
		if (str[i - 1] != '%' || (str[i] == 32))
			count += ft_put_c((char)str[i]);
		if (i <= str_len)
			i++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	int			count;

	count = 0;
	va_start(ap, str);
	count = ft_printf_helper(str, ap, count);
	va_end(ap);
	return (count);
}
