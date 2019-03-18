/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   resizable_string.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/22 15:43:36 by swetting       #+#    #+#                */
/*   Updated: 2019/02/22 16:28:53 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESIZABLE_STRING
# define RESIZABLE_STRING
#include "libft.h"

typedef struct	resizable_string
{
	char		*str;
	size_t		size;
}				rs_t;

rs_t	*new_rstr(const char *str);
rs_t	*new_rstrn(const char *str, size_t len);
void	rep_rstr(rs_t **old, rs_t *new);
rs_t	*append_rstr(rs_t **rstr, const char *str);

#endif