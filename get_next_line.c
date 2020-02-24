/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 08:51:23 by qli            #+#    #+#                */
/*   Updated: 2019/12/18 11:34:12 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**	free the container whenever there is an error
**	return either 0 or 1 based on the condition
**	special condition (res == -2) to deal with invalid fd
*/

static int		ft_free_container(char **container, int res)
{
	if (res == -2)
	{
		if (!(*container))
			return (-1);
		if (*container)
		{
			free(*container);
			*container = 0;
		}
		return (-1);
	}
	if (!(*container))
		return (0);
	if (*container)
	{
		free(*container);
		*container = 0;
	}
	return (res);
}

/*
**	create a new container whenever there is a new line has been created
**	remove the created new line and keep the rest
**	important to free the old container and point it to the new container
*/

static int		ft_container_new(char **container, size_t len)
{
	size_t	total_len;
	char	*new_container;
	size_t	i;

	i = 0;
	total_len = ft_strlen(*container) - len;
	if (total_len == 0)
		return (ft_free_container(container, 0));
	new_container = malloc(sizeof(char) * (total_len + 1));
	if (new_container == NULL)
		return (ft_free_container(container, -1));
	while ((*container)[i + len] != '\0')
	{
		new_container[i] = (*container)[i + len];
		i++;
	}
	new_container[i] = 0;
	free(*container);
	*container = new_container;
	return (0);
}

/*
**	create the new line whenever there is '\n' in the container
*/

static int		ft_line_create(char *container, char **line, char c)
{
	size_t	i;
	size_t	len;
	char	*new_line;

	i = 0;
	len = ft_char_find(container, c);
	new_line = (char *)malloc(sizeof(char) * (len + 1));
	if (new_line == NULL)
		return (ft_free_container(&container, -1));
	while (container[i] != c)
	{
		new_line[i] = container[i];
		i++;
	}
	new_line[i] = '\0';
	*line = new_line;
	return (1);
}

/*
**	deal with two conditions
**	1. when there's nothing to read and check if there is anything to return
**	2. when there is something to read and the container needs to be updated
*/

static int		ft_read_line(char **con, char **line, ssize_t n, char *buf)
{
	if (n == 0)
	{
		if (!(*con))
		{
			free(*con);
			*line = ft_strdup("");
			if (*line == 0)
				return (ft_free_container(con, -1));
			return (0);
		}
		if (ft_line_create(*con, line, '\0') == -1
		|| ft_container_new(con, ft_strlen(*con)) == -1)
			return (ft_free_container(con, -1));
		return (ft_free_container(con, 0));
	}
	if (n == 2)
	{
		if (!(*con))
			*con = ft_strdup(buf);
		else if (*con)
			*con = ft_strjoin(*con, buf);
		if (*con == 0)
			return (ft_free_container(con, -1));
	}
	return (0);
}

/*
**	input control in the first function
**	check if the container (static buf) has '\n'
**	If no '\n', read until a '\n' is found
**	If there is a '\n', return the new line and clean the container
*/

int				get_next_line(int fd, char **line)
{
	static char		*container;
	char			buf[BUFFER_SIZE + 1];
	ssize_t			res;

	if (fd == -1 || line == NULL)
		return (-1);
	while (ft_check_line(container) == 0 && res != -1)
	{
		if ((res = read(fd, buf, BUFFER_SIZE)) == 0 && res != -1)
			return (ft_read_line(&container, line, 0, buf));
		else if (res > 0)
		{
			buf[res] = '\0';
			if (ft_read_line(&container, line, 2, buf) == -1)
				return (-1);
		}
	}
	if (ft_check_line(container) == 1 || res == -1)
	{
		if (res == -1 || ft_line_create(container, line, '\n') == -1
		|| ft_container_new(&container, ft_char_find(container, '\n')) == -1)
			return (ft_free_container(&container, -2));
		return (1);
	}
	return (0);
}
