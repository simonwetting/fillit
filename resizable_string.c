/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   resizable_string.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/22 15:28:48 by swetting       #+#    #+#                */
/*   Updated: 2019/02/22 16:32:44 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "resizable_string.h"
#include <unistd.h>

rs_t	*new_rstr(const char *str)
{
	rs_t		*new_rstr;

	new_rstr = (rs_t *)malloc(sizeof(rs_t));
	new_rstr->str = ft_strdup(str);
	new_rstr->size = ft_strlen(str);
	return (new_rstr);
}

rs_t	*new_rstrn(const char *str, size_t len)
{
	rs_t		*new_rstr;

	if (ft_strlen(str) < len)
		return (NULL);
	new_rstr = (rs_t *)malloc(sizeof(rs_t));
	new_rstr->str = ft_strdup(str);
	new_rstr->size = len;
	return (new_rstr);
}

void	rep_rstr(rs_t **old, rs_t *new)
{
	rs_t	*free_this;

	free_this = *old;
	*old = new;
	free(free_this->str);
	free(free_this);
}

void	print_rstr(rs_t *rstr)
{
	write(1, rstr->str)
}

rs_t	*append_rstr(rs_t **rstr, const char *str)
{
	size_t	len_str;
	size_t	len_appendage;
	rs_t	*new_rstr;

	len_str = ft_strlen((*rstr)->str);
	len_appendage = ft_strlen(str);
	if (len_str + len_appendage + 1 < (*rstr)->size)
	{
		new_rstr = new_rstrn(str, len_str + len_appendage);
		ft_strcpy(new_rstr->str, (*rstr)->str);
		//new_rstr->size = len_str + len_appendage;
		rep_rstr(rstr, new_rstr);
	}
	ft_strcpy((*rstr)->str + len_str, str);
	return (*rstr);
}