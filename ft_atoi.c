/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyupa <jinhyupa@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:40:17 by jinhyupa          #+#    #+#             */
/*   Updated: 2022/02/07 18:40:18 by jinhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	result;
	unsigned long long	max;
	int					sign;

	result = 0;
	sign = 1;
	max = 9223372036854775807;
	while (((*str >= 9 && *str <= 13) || *str == ' ') && *str)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str)
	{
		result = (result * 10) + (*str - 48);
		str++;
	}
	if (result > max && sign == 1)
		return (-1);
	else if (result > max + 1 && sign == -1)
		return (0);
	return (result * sign);
}
