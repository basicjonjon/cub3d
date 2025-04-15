/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:04:41 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/04/15 16:50:47 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int	ft_fputptr(void *ptr, int fd)
{
	int					count;
	unsigned long long	adrs;

	count = 0;
	if (!ptr)
		return (ft_fputstr_ct("(nil)", fd));
	adrs = (unsigned long long)ptr;
	count = ft_fputstr_ct("0x", fd) \
		+ ft_fhexa_llong((unsigned long long)adrs, fd);
	return (count);
}
