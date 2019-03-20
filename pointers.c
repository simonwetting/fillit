/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pointers.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/14 12:34:45 by anonymous      #+#    #+#                */
/*   Updated: 2019/03/20 17:26:22 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pointers.h"
#include "libft.h"

t_pa	*new_pa(size_t size)
{
	t_pa	*new;

	new = (t_pa *)malloc(sizeof(t_pa));
	new->pa = (void **)malloc(sizeof(void *) * size);
	new->len = 0;
	new->size = size;
	return (new);
}

void	resize_pa(t_pa **apa, size_t size)
{
	t_pa	*new;
	t_pa	*old;

	old = *apa;
	new = new_pa(size);
	new->len = old->len;
	ft_memcpy(new->pa, old->pa, sizeof(void *) * old->len);
	free(*apa);
	*apa = new;
}

void	replace_pointer(t_pa *pa, int index, void *new)
{
	ft_repp(pa->pa+index, new);
}

void	iterate_pa(t_pa *pa, void f(char *p))
{
	size_t	i;

	i = 0;
	while (i < pa->len)
	{
		f(pa->pa[i]);
		i++;
	}
}

void	add_pointer(t_pa **apa, void *p)
{
	if ((*apa)->len >= (*apa)->size)
		resize_pa(apa, (*apa)->size * 2);
	(*apa)->pa[(*apa)->len] = p;
	(*apa)->len++;
}
