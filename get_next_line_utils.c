/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 11:02:48 by qli            #+#    #+#                */
/*   Updated: 2019/12/18 11:31:31 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**	count the len of a string
*/

size_t		ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

/*
** duplicate the buf to containter, when the container is empty
*/

char		*ft_strdup(const char *s1)
{
	char	*dst;
	char	*src;
	size_t	len;
	size_t	i;

	i = 0;
	src = (char *)s1;
	len = ft_strlen(src);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (0);
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

/*
**	join the buffer to container, when the containerontainer is not empty
*/

char		*ft_strjoin(char *s1, char *s2)
{
	size_t	i1;
	size_t	i2;
	char	*dst;

	if (s1 == 0 || s2 == 0)
		return (0);
	i1 = 0;
	i2 = 0;
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dst == NULL)
		return (0);
	while (s1[i1] != '\0')
	{
		dst[i1] = s1[i1];
		i1++;
	}
	while (s2[i2] != '\0')
	{
		dst[i1 + i2] = s2[i2];
		i2++;
	}
	dst[i1 + i2] = '\0';
	free((void *)s1);
	return (dst);
}

/*
** count the len before the '\n' or '\0' in the container
*/

size_t		ft_char_find(char *s, char c)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i + 1);
		i++;
	}
	return (i);
}

/*
** Check if there is '\n' in the container
*/

int			ft_check_line(char *container)
{
	size_t	i;

	i = 0;
	if (!container)
		return (0);
	if (container)
	{
		while (container[i] != '\0')
		{
			if (container[i] == '\n')
				return (1);
			i++;
		}
	}
	return (0);
}
