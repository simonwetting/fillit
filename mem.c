/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mem.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 11:00:18 by anonymous      #+#    #+#                */
/*   Updated: 2019/03/20 17:03:20 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

mem_t	*new_mem(size_t size)
{
	mem_t	*new;

	new = (mem_t *)malloc(sizeof(mem_t));
	new->mem = (void *)malloc(size);
	new->len = 0;
	new->size = size;
	return (new);
}



void	append_mem(mem_t **dest, mem_t *appendage)
{
	size_t	size;

	size = (*dest)->len + appendage->len;
	if ((*dest)->size < size)
		*dest = ft_memmove(new_mem(size)->mem, (*dest)->mem, (*dest)->len);
	ft_memmove((*dest)->mem + (*dest)->len, appendage->mem, appendage->len);
}