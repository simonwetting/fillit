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
typedef struct	s_mem
{
	void		*mem;
	size_t		len;
	size_t		size;
}				mem_t;
#endif