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
#include <stdio.h>
#include "libft.h"
#include "get_next_line.h"
#include "error_handler.h"

int		get_next_tetrimino(int fd, char ***tetrimino)
{
	char	line_count;
	int		state;
	char	c;

	line_count = 0;
	while (line_count < 4)
	{
		if (get_next_line(fd, *tetrimino + line_count) != 1)
			return (-1);
		line_count++;
	}
	read(fd, &c, 1);
}

t_pa	*read_tetriminos(char *filename)
{
	t_pa	*tetriminos;
	char	**tetrimino;
	int		fd;

	tetriminos = new_pa(1);
	tetrimino = (char **)malloc(sizeof(char *) * 4);
	fd = open(filename, O_RDONLY);
	while (get_next_tetrimino(fd, &tetrimino))
		add_pointer(&tetriminos, tetrimino);
	// for (int m = 0; m < tetriminos->len; m++)
	// 	for (int n = 0; n < 4; n++)
	// 		printf("%s\n", ((char **)tetriminos->pa)[m][n]);
	// for (int n = 0; n < tetriminos->len; n++)
	// 	printf(tetriminos)
	for (int m = 0; m < tetriminos->len; m++)
		for (int n = 0; n < 4; n++)
			printf("%s\n", ((char **)tetriminos->pa[m])[n]);
}

int		main(int argc, char **argv)
{
	test_me();
	// t_pa	*tetriminos;

	// if (argc != 2)
	// {
	// 	ft_putendl("You should specify 1 file as a parameter");
	// 	return (-1);
	// }
	// tetriminos = read_tetriminos(argv[1]);
}
