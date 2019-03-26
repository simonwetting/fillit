# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: swetting <swetting@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/08 13:16:08 by anonymous      #+#    #+#                 #
#    Updated: 2019/03/20 17:12:08 by swetting      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

win:
	gcc -g -c fillit.c get_next_line.c error_handler.c mem.c pointers.c
	gcc	-g *.o libft.a
	./a.exe tetriminos
