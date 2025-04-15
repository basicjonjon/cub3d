/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:46:16 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/04/15 16:47:51 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int	ft_fsummary(va_list args, const char **format, int fd)
{
	int	count;

	count = 0;
	if (**format == '%')
		count = write(fd, "%", 1);
	if (**format == 'c')
		count = ft_fputchar_ct(va_arg(args, int), fd);
	if (**format == 's')
		count = ft_fputstr_ct(va_arg(args, char *), fd);
	if (**format == 'd' || **format == 'i')
		count = ft_fputnbr_ct(va_arg(args, int), fd);
	if (**format == 'u')
		count = ft_fputunsigned_int(va_arg(args, unsigned int), fd);
	if (**format == 'x')
		count = ft_fhexa(va_arg(args, unsigned int), 0, fd);
	if (**format == 'X')
		count = ft_fhexa(va_arg(args, unsigned int), 1, fd);
	if (**format == 'p')
		count = ft_fputptr(va_arg(args, void *), fd);
	return (count);
}

int	ft_fprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_fsummary(args, &format, fd);
			format++;
		}
		else
		{
			count += ft_fputchar_ct(*format, fd);
			format++;
		}
	}
	va_end(args);
	return (count);
}
