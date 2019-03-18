/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: simonwetting <simonwetting@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/06 10:30:21 by swetting       #+#    #+#                */
/*   Updated: 2019/03/07 11:20:39 by simonwettin   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "error_handler.c"
// #include "resizable_string.c"

typedef char byte;

// int		read_next_tetrimino(int fd)
// {
// 	char	tetrimino[4][2];
// 	char	*data_read;
// 	int 	i;
// 	char	pos[2];
// 	int		pos_count;

// 	if (read(fd, data_read, 21) < 21)
// 		return (-1);
// 	pos[0] = 0;
// 	pos[1] = 0;
// 	pos_count = 0;
// 	while (i < 21)
// 	{
// 		if (data_read[i] == '#')
// 			tetrimino[pos_count] = pos;
		
// 	}
// }
// int		read_tetriminos(char *filename)
// {
// 	int		fd;

// 	fd = open(filename, O_RDONLY);
// 	if (fd == -1)
// 		return (-1);
	
// }

int		main(int argc, char **argv)
{
	// test_me();
	// add_group("aap");
	// add_group("Test1");
	// get_group("test");
	// get_group("aap");
	// get_group("Test1");
	// pa_t	*pa;
	// int		i;

	// pa = new_pa(1);
	// add_pointer(&pa, ft_strdup("Test1"));
	// add_pointer(&pa, ft_strdup("Test2"));
	// add_pointer(&pa, ft_strdup("Test3"));
	// add_pointer(&pa, ft_strdup("Test4"));
	// add_pointer(&pa, ft_strdup("Test5"));
	// add_pointer(&pa, ft_strdup("Test6"));
	// add_pointer(&pa, ft_strdup("Test7"));
	// add_pointer(&pa, ft_strdup("Test8"));
	// add_pointer(&pa, ft_strdup("Test9"));
	// add_pointer(&pa, ft_strdup("Test10"));
	// // repp(pa->pa+4, ft_strdup("test"));
	// replace_pointer(pa, 7, ft_strdup("TEST"));
	// i = 0;
	// while (i < pa->len)
	// 	printf("[%i] = %s\n", i, pa->pa[i++]);
	mem_t	*mem;

	mem = new_mem(100);
	ft_strncpy(mem->mem, "Hello", 3);
	printf("%s\n", mem->mem);
}
