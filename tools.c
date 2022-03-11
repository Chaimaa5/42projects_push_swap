/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:24:20 by cel-mhan          #+#    #+#             */
/*   Updated: 2022/03/03 13:24:22 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s11;
	unsigned char	*s22;

	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s11[i] && s22[i] && s11[i] == s22[i])
		{
			i++;
			continue ;
		}
		return (s11[i] - s22[i]);
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*buff;
	char	*s;

	s = (char *)s1;
	i = 0;
	len = ft_strlen(s);
	buff = malloc(sizeof(char) * len + 1);
	if (!buff)
		return (0);
	while (s[i])
	{
		buff[i] = s[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

int	ft_isdigit(int c)
{
	if (c <= 57 && c >= 48)
		return (1);
	return (0);
}
