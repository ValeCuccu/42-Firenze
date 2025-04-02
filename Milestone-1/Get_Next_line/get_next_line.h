/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacuccu <vacuccu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:20:10 by vacuccu           #+#    #+#             */
/*   Updated: 2025/02/28 12:51:12 by vacuccu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h> 
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <ctype.h>
# include <stddef.h> 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif

size_t	ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*ft_strchr(char *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif