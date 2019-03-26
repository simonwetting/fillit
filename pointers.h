/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pointers.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/14 12:35:52 by anonymous      #+#    #+#                */
/*   Updated: 2019/03/20 16:08:03 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINTERS_H
# define POINTERS_H
#include <string.h>
#include <stdlib.h>
typedef struct	s_pointer_array
{
	void		**pa;
	size_t		len;
	size_t		size;
}				t_pa;

t_pa			*new_pa(size_t size);
void			resize_pa(t_pa **apa, size_t size);
void			replace_pointer(t_pa *pa, int index, void *new);
void			iterate_pa(t_pa *pa, void f(char *p));
void			add_pointer(t_pa **apa, void *p);
#endif