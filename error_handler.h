/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handler.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/08 11:02:35 by anonymous      #+#    #+#                */
/*   Updated: 2019/03/20 16:08:17 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLER
# define ERROR_HANDLER
# include <stdlib.h>
# include <string.h>
# include "pointers.h"
typedef struct			error_group
{
    char				*name;
    char				*codes;
    struct error_group	*next;
}						eg_t;
typedef short			msg_id_t;
static t_pa				*messages;
static eg_t				*groups;
static int				msg_count;
#endif