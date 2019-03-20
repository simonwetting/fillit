/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/06 10:30:21 by swetting       #+#    #+#                */
/*   Updated: 2019/03/20 17:28:30 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "error_handler.c"
#include "libft.h"
#include "get_next_line.h"

int		get_next_tetrimino(int fd, char ***tetrimino)
{
	char	line_count;

	line_count = 0;
	while (line_count < 4)
	{
		get_next_line(fd, *tetrimino + line_count);
		line_count++;
	}
}

char	***read_tetriminos(char *filename)
{
	t_pa	*tetriminos;
	char	**tetrimino;
	int		fd;

	tetriminos = new_pa(1);
	tetrimino = (char **)malloc(sizeof(char *) * 4);
	fd = open(filename, O_RDONLY);
	while (get_next_tetrimino(fd, &tetrimino))
		add_pointer(&tetriminos, "tetrimino");
	for (int n = 0; n < 4; n++)
		printf("%s\n", tetrimino[n]);
}

int		main(int argc, char **argv)
{
	// test_me();
	t_pa	***tetriminos;

	if (argc != 2)
	{
		ft_putendl("You should specify 1 file as a parameter");
		return (-1);
	}
	tetriminos = read_tetriminos();
}
