/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:22:58 by frmarian          #+#    #+#             */
/*   Updated: 2024/06/10 13:39:33 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			cc;

	cc = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return (i);
		i++;
	}
	if (s[i] == cc)
		return (i);
	return (-1);
}

int	ft_strlen(const char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strjoin(char	*s1, char	*s2)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	line = ft_calloc(((ft_strlen(s1) + ft_strlen(s2)) + 1), sizeof(char));
	if (s1)
	{
		while (s1[i])
		{
			line[i] = s1[i];
			i++;
		}
		free(s1);
	}
	while (s2[j])
	{
		line[i + j] = s2[j];
		j++;
	}
	free(s2);
	return (line);
}

char	*ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	dst = malloc((dstsize + 1) * sizeof(char));
	if (!dst)
		return (0);
	if (dstsize != 0)
	{
		while ((i < dstsize) && (src[i]))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (dst);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	tmp = malloc(count * size);
	if (!tmp)
		return (NULL);
	while (i < count * size)
		tmp[i++] = 0;
	return (tmp);
}
