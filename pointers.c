/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pointers.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/14 12:34:45 by anonymous      #+#    #+#                */
/*   Updated: 2019/03/14 12:34:45 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pointers.h"
#include "libft.h"

pa_t	*new_pa(size_t size)
{
	pa_t	*new;

	new = (pa_t *)malloc(sizeof(pa_t));
	new->pa = (void **)malloc(sizeof(void *) * size);
	new->len = 0;
	new->size = size;
	return (new);
}

void	resize_pa(pa_t **apa, size_t size)
{
	pa_t	*new;
	pa_t	*old;

	old = *apa;
	new = new_pa(size);
	new->len = old->len;
	ft_memcpy(new->pa, old->pa, sizeof(void *) * old->len);
	free(*apa);
	*apa = new;
}

void	replace_pointer(pa_t *pa, int index, void *new)
{
	ft_repp(pa->pa+index, new);
}

void	add_pointer(pa_t **apa, char *p)
{
	if ((*apa)->len >= (*apa)->size)
		resize_pa(apa, (*apa)->size * 2);
	(*apa)->pa[(*apa)->len] = p;
	(*apa)->len++;
}