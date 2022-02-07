/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyupa <jinhyupa@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:42:44 by jinhyupa          #+#    #+#             */
/*   Updated: 2022/02/07 18:42:45 by jinhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_n_len(int n)
{
	size_t	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
		count++;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		n_len;
	long long	num;

	n_len = ft_n_len(n);
	str = (char *)malloc(sizeof(char) * n_len + 1);
	num = (long long)n;
	if (!str)
		return (NULL);
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	str[n_len] = '\0';
	while (num)
	{
		str[n_len - 1] = num % 10 + 48;
		num /= 10;
		n_len--;
	}
	return (str);
}
