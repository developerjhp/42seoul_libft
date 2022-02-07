/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyupa <jinhyupa@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:39:58 by jinhyupa          #+#    #+#             */
/*   Updated: 2022/02/07 18:40:02 by jinhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*find_ptr;
	size_t		i;
	size_t		j;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = i;
		find_ptr = needle;
		while (haystack[j] == *find_ptr && j < len && haystack[j] && *find_ptr)
		{
			j++;
			find_ptr++;
		}
		if (*find_ptr == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
