/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handler.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/08 11:02:19 by anonymous      #+#    #+#                */
/*   Updated: 2019/03/20 17:11:40 by swetting      ########   odam.nl         */
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
	return (messages->len - 1);
}

char	*new_error_code(char *code, msg_id_t msg_id)
{
	return (NULL);
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
	return (0);
}

void		test_me(void)
{
	printf("groups>%p\nmessages>%p\nmsg_count>%i\n", groups, messages, msg_count);
	// test_me();
	// add_group("aap");
	// add_group("Test1");
	// get_group("test");
	// get_group("aap");
	// get_group("Test1");
	t_pa	*pa;
	// int		i;

	pa = new_pa(1);
	add_pointer(&pa, ft_strdup("Test1"));
	add_pointer(&pa, ft_strdup("Test2"));
	add_pointer(&pa, ft_strdup("Test3"));
	add_pointer(&pa, ft_strdup("Test4"));
	add_pointer(&pa, ft_strdup("Test5"));
	add_pointer(&pa, ft_strdup("Test6"));
	add_pointer(&pa, ft_strdup("Test7"));
	add_pointer(&pa, ft_strdup("Test8"));
	add_pointer(&pa, ft_strdup("Test9"));
	add_pointer(&pa, ft_strdup("Test10"));
	// repp(pa->pa+4, ft_strdup("test"));
	replace_pointer(pa, 7, ft_strdup("TEST"));
	iterate_pa(pa, &ft_putendl);
	// i = 0;
	// while (i < pa->len)
	// 	printf("[%i] = %s\n", i, pa->pa[i++]);
	// mem_t	*mem;

	// mem = new_mem(100);
	// ft_strncpy(mem->mem, "Hello", 3);
	// printf("%s\n", mem->mem);
}