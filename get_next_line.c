/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:08:57 by frmarian          #+#    #+#             */
/*   Updated: 2024/06/11 13:19:53 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			cc;

	if (s)
	{
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
	}
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

char	*ft_getrest(char **line, int index)
{
	char	*rest;
	int		rest_len;
	int		i;

	i = 0;
	rest_len = 0;
	while ((*line)[rest_len + index])
		rest_len++;
	rest = malloc ((rest_len + 1) * sizeof(char));
	if (!rest)
		return (NULL);
	while ((*line)[index + i])
	{
		rest[i] = (*line)[index + i];
		i++;
	}
	rest[i] = '\0';
	free(*line);
	*line = ft_strlcpy(*line, rest, rest_len + 1);
	free(rest);
	return (*line);
}

char	*ft_getline(char **line)
{
	char	*str;
	int		i;

	str = "";
	i = ft_strchr((*line), '\n');
	str = ft_strlcpy(str, (*line), (i + 1));
	*line = ft_getrest(line, (i + 1));
	return (str);
}

void	*ft_exit(char	**txt)
{
	free(*txt);
	*txt = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char		*line;
	char			*txt;
	int				bytes_read;

	txt = NULL;
	while (ft_strchr(txt, '\n') == -1)
	{
		txt = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!txt || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0 || fd == 0)
			return (NULL);
		bytes_read = read(fd, txt, BUFFER_SIZE);
		if (bytes_read == -1 || (bytes_read == 0 && ft_strlen(line) == 0))
			return (ft_exit(&txt));
		txt[bytes_read] = '\0';
		line = ft_strjoin(line, txt);
		if (ft_strchr(line, '\n') != -1)
			return (ft_getline(&line));
		if (ft_strchr(line, '\n') == -1 && bytes_read == 0)
		{
			txt = ft_strlcpy(txt, line, ft_strlen(line));
			return (line = "", txt);
		}
	}
	return (NULL);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("teta.txt", O_RDONLY);
	if (fd == -1)
		return (-1);

	while ((line = get_next_line(fd)))
	{
		printf("Linea: %s", line);
		free(line);
	}
	return (0);
}
