/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handler.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/08 11:02:19 by anonymous      #+#    #+#                */
/*   Updated: 2019/03/08 11:02:19 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "error_handler.h"
#include "libft.h"
#include <stdio.h>
#include "pointers.c"
#include "mem.c"

void		add_group(char *group_name)
{
	eg_t	*new_group;

	new_group = (eg_t *)malloc(sizeof(eg_t));
	new_group->name = group_name;
	new_group->codes = NULL;
	new_group->next = NULL;
	if (!groups)
		groups = new_group;
	else
	{
		new_group->next = groups;
		groups = new_group;
	}
}

eg_t		*get_group(char *group_name)
{
	eg_t	*tmp;

	tmp = groups;
	while (tmp && tmp->name != group_name)
		tmp = tmp->next;
	if (tmp)
		return (tmp);
	return (NULL);
	// 	printf("Found group %s\n", group_name);
	// else
	// 	printf("Couldn't find group %s\n", group_name);
}

msg_id_t	get_code(char *codes, int code)
{
	int		i;

	i = 0;
	while (codes && codes[i] != code)
		i += 3;
	if (!codes || !codes[i])
		return (-1);
	return ((msg_id_t)codes[i + 1]);
}

msg_id_t	get_msg_id(char *msg)
{
	int		i;

	i = 0;
	while (i < messages->len)
		if (!ft_strcmp(msg, messages->pa[i]))
			return (i);
	return (0);
}

msg_id_t	add_msg(char *msg)
{
	if (!messages)
		messages = new_pa(1);
	add_pointer(&messages, msg);
}

char	*new_error_code(char *code, msg_id_t msg_id)
{

}

int			add_error_code(char *group_name, int code, char *msg)
{
	eg_t		*group;
	msg_id_t	msg_id;

	group = get_group(group_name);
	if (!group)
		add_group(group_name);
	if (get_code(group->codes, code))
		return (-1);
	msg_id = get_msg_id(msg);
	if (!msg_id)
		msg_id = add_msg(msg);
	group->codes = ft_strjoin(group->codes, "abc");
}

void		test_me(void)
{
	printf("groups>%p\nmessages>%p\nmsg_count>%p%n", groups, messages, msg_count);
}