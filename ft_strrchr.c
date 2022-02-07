/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyupa <jinhyupa@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:38:57 by jinhyupa          #+#    #+#             */
/*   Updated: 2022/02/07 18:39:09 by jinhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const unsigned char	*ptr;
	size_t				i;

	ptr = (const unsigned char *)s;
	i = ft_strlen(s);
	if ((unsigned char)c == '\0')
		return ((char *)ptr + i);
	while (i)
	{
		i--;
		if (ptr[i] == (unsigned char)c)
			return ((char *)ptr + i);
	}
	return (NULL);
}
