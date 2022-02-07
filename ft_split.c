/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyupa <jinhyupa@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:42:26 by jinhyupa          #+#    #+#             */
/*   Updated: 2022/02/07 23:37:17 by jinhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	ptr = NULL;
	return (NULL);
}

static char	**ft_seperator(char **ptr, char const *s, char c, size_t count)
{
	size_t	i;
	size_t	next;
	size_t	idx;

	i = 0;
	idx = 0;
	while (s[i] && idx < count)
	{
		if (s[i] != c)
		{
			next = i + 1;
			while (s[next] && s[next] != c)
				next++;
			ptr[idx] = ft_substr(s, i, next - i);
			if (!ptr[idx])
				return (ft_free(ptr));
			idx++;
			i = next;
		}
		else
			i++;
	}
	ptr[idx] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	word_count;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	word_count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			word_count++;
			while ((s[i] != c) && s[i])
				i++;
		}
		else
			i++;
	}
	ptr = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!ptr)
		return (NULL);
	return (ft_seperator(ptr, s, c, word_count));
}
