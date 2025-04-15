/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarpaul <mmarpaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:56:52 by mmarpaul          #+#    #+#             */
/*   Updated: 2025/04/15 16:45:07 by mmarpaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FPRINTF_H
# define FT_FPRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_fprintf(int fd, const char *format, ...);

int	ft_fsummary(va_list args, const char **str, int fd);

int	ft_fhexa(unsigned int n, int i, int fd);

int	ft_fhexa_llong(unsigned long long n, int fd);

int	ft_fputstr_ct(char *str, int fd);

int	ft_fputnbr_ct(int n, int fd);

int	ft_fputchar_ct(char c, int fd);

int	ft_fputunsigned_int(unsigned int n, int fd);

int	ft_fputptr(void *ptr, int fd);

#endif