/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputnbr_ct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:48:40 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/04/15 16:47:27 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int	ft_fputnbr_ct(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count = ft_fputstr_ct("-2147483648", fd);
		return (count = 11);
	}
	else if (n < 0)
	{
		n = -n;
		count += ft_fputchar_ct('-', fd);
	}
	if (n > 9)
	{
		count += ft_fputnbr_ct((n / 10), fd);
		count += ft_fputnbr_ct((n % 10), fd);
	}
	else
		count += ft_fputchar_ct(n + '0', fd);
	return (count);
}

int	ft_fputunsigned_int(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_fputunsigned_int(n / 10, fd);
		count += ft_fputunsigned_int(n % 10, fd);
	}
	else
		count += ft_fputchar_ct(n + '0', fd);
	return (count);
}
