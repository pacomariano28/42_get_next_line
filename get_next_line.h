/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:22:55 by frmarian          #+#    #+#             */
/*   Updated: 2024/06/11 12:05:01 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

/**
 * @brief Copy src in dst. Take the full size of the destination buffer and 
 * guarantee NUL-termination if there is room 
 * @param dst 
 * @param src 
 * @return size_t - lenght of the string created 
 */
char		*ft_strjoin(char *s1, char *s2);
/**
 * @brief Locates the first occurence of c
 * 
 * @param s 
 * @param c 
 * @return int 
 */
int			ft_strchr(const char *s, int c);
/**
 * @brief Returns len of str
 * 
 * @param str 
 * @return int 
 */
int			ft_strlen(const char *str);
/**
 * @brief Copy src in dst with dstsize
 * 
 * @param dst 
 * @param src 
 * @param dstsize 
 * @return char* 
 */
char		*ft_strlcpy(char *dst, char *src, size_t dstsize);
/**
 * @brief allocates memory and bytes = 0
 * 
 * @param count 
 * @param size 
 * @return void* 
 */
void		*ft_calloc(size_t count, size_t size);
/**
 * @brief Returns the content of line before '\n', also realocates 
 * memory of line to fit the new content without that line wich we 
 * save on str. 
 * 
 * @param line 
 * @return char *str 
 */
char		*ft_getline(char **line);
/**
 * @brief Returns the rest of str that line has after '\n'. 
 * Deletes the previous content before '\n' and relocates memory of
 * line to fit the updated content.
 * 
 * @param line 
 * @param index 
 * @return char* 
 */
char		*ft_getrest(char **line, int index);
/**
 * @brief free txt and returns NULL
 * 
 * @param txt 
 * @return void* 
 */
void		*ft_exit(char	**txt);
/**
 * @brief Get the next line object
 * 
 * @param fd 
 * @return char* 
 */
char		*get_next_line(int fd);
#endif