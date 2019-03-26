/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mem.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 11:02:01 by anonymous      #+#    #+#                */
/*   Updated: 2019/03/15 11:02:01 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H
#include <string.h>
#include <stdlib.h>
#include "libft.h"
typedef struct	s_mem
{
	void		*mem;
	size_t		len;
	size_t		size;
}				mem_t;

mem_t			*new_mem(size_t size);
void			append_mem(mem_t **dest, mem_t *appendage);
#endif