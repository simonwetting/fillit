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
#endif