/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 14:48:19 by qli           #+#    #+#                 */
/*   Updated: 2020/11/06 15:10:38 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int     fd;
	char    *line;

	if (argc != 2)
    {
        printf("Please run \"./get_next_line file_name\"\n");
        return (1);
    }    
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        return (1);
    else
    {
        while (get_next_line(fd, &line) == 1)
        {
            printf("%s\n", line);
            free(line);
        }
    }
    free(line);
    close(fd);
	return (0);
}
