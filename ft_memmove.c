/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyupa <jinhyupa@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:07:36 by jinhyupa          #+#    #+#             */
/*   Updated: 2022/02/06 13:07:38 by jinhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_tmp;
	const unsigned char	*src_tmp;
	size_t				i;

	if (!dst && !src)
		return (dst);
	dst_tmp = (unsigned char *)dst;
	src_tmp = (const unsigned char *)src;
	if (dst_tmp > src_tmp)
	{
		i = len;
		while (i > 0)
		{
			dst_tmp[i - 1] = src_tmp[i - 1];
			i--;
		}
		return (dst);
	}
	return (ft_memcpy(dst, src, len));
}
