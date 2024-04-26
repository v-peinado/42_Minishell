/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:50:01 by vpeinado          #+#    #+#             */
/*   Updated: 2024/03/09 00:54:05 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	comp(const char *set, char i)
{
	size_t	j;

	j = 0;
	while (set[j])
	{
		if (set[j] == i)
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	s1_len;
	char	*str;

	i = 0;
	if (!s1)
		return (NULL);
	while (s1[i] && comp(set, s1[i]))
		i++;
	s1_len = ft_strlen(s1);
	while (i < s1_len && comp(set, s1[s1_len - 1]))
		s1_len--;
	str = (char *)malloc(sizeof(char) * (s1_len - i + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (i < s1_len)
		str[j++] = s1[i++];
	str[j] = '\0';
	return (str);
}
