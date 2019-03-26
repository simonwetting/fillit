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
#include "pointers.h"
#include "mem.h"

void print_bytes(void *ptr, int size) 
{
    unsigned char *p = ptr;
    int i;
    for (i=0; i<size; i++) {
        printf("%02hhX ", p[i]);
    }
    printf("\n");
}

eg_t		*add_group(char *group_name)
{
	eg_t	*new_group;

	new_group = (eg_t *)malloc(sizeof(eg_t));
	new_group->name = group_name;
	new_group->codes = ft_strdup("");
	new_group->next = NULL;
	if (!groups)
		groups = new_group;
	else
	{
		new_group->next = groups;
		groups = new_group;
	}
	return (new_group);
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
	while (codes[i] && codes[i] != code)
		i += 3;
	printf("i>%i\n", i);
	print_bytes(codes + i - 3, 3);
	print_bytes(codes, ft_strlen(codes));
	if (codes[i] != (char)code)
		return (0);
	return ((msg_id_t)codes[i + 1]);
}

msg_id_t	get_msg_id(char *msg)
{
	int		i;

	i = 0;
	if (!messages)
		messages = new_pa(1);
	while (i < messages->len)
	{
		if (!ft_strcmp(msg, messages->pa[i]))
			return (i + 1);
		i++;
	}
	return (0);
}

msg_id_t	add_msg(char *msg)
{
	if (!messages)
		messages = new_pa(1);
	add_pointer(&messages, msg);
	return (messages->len);
}

char	*new_error_code(char code, msg_id_t msg_id)
{
	char	*error_code;

	error_code = (char *)malloc(sizeof(char) * 3);
	error_code[0] = code;
	ft_memcpy(error_code + 1, &msg_id, 2);
	return (error_code);
}

int			add_error_code(char *group_name, int code, char *msg)
{
	eg_t		*group;
	msg_id_t	msg_id;

	group = get_group(group_name);
	if (!group)
		group = add_group(group_name);
	if (get_code(group->codes, code))
		return (-1);
	msg_id = get_msg_id(msg);
	if (!msg_id)
		msg_id = add_msg(msg);
	group->codes = ft_strjoin(group->codes, new_error_code(code, msg_id));
	return (0);
}


int			print_error(int code, char *group_name)
{
	eg_t		*group;
	msg_id_t	msg_id;

	printf("trying to print error %i for %s\n", code, group_name);
	group = get_group(group_name);
	if (!group)
		return (-1);
	msg_id = get_code(group->codes, code);
	if (!msg_id)
		return (-2);
	printf("%s\n", (char *)messages->pa[msg_id - 1]);
	return (0);
}

void		test_me(void)
{
	// printf("groups>%p\nmessages>%p\nmsg_count>%i\n", groups, messages, msg_count);
	// test_me();
	// add_group("aap");
	// add_group("Test1");
	// get_group("test");
	// get_group("aap");
	// get_group("Test1");
	// t_pa	*pa;
	// int		i;

	// pa = new_pa(1);
	// add_pointer(&pa, ft_strdup("Test1"));
	// add_pointer(&pa, ft_strdup("Test2"));
	// add_pointer(&pa, ft_strdup("Test3"));
	// add_pointer(&pa, ft_strdup("Test4"));
	// add_pointer(&pa, ft_strdup("Test5"));
	// add_pointer(&pa, ft_strdup("Test6"));
	// add_pointer(&pa, ft_strdup("Test7"));
	// add_pointer(&pa, ft_strdup("Test8"));
	// add_pointer(&pa, ft_strdup("Test9"));
	// add_pointer(&pa, ft_strdup("Test10"));
	// repp(pa->pa+4, ft_strdup("test"));
	// replace_pointer(pa, 7, ft_strdup("TEST"));
	// iterate_pa(pa, &ft_putendl);
	// i = 0;
	// while (i < pa->len)
	// 	printf("[%i] = %s\n", i, pa->pa[i++]);
	// mem_t	*mem;

	// mem = new_mem(100);
	// ft_strncpy(mem->mem, "Hello", 3);
	// printf("%s\n", mem->mem);
	// char *error_code = new_error_code(54, 12849);
	// write(1, error_code, 3);
	add_error_code("eh_print_error", -1, "Group doens't exist");
	add_error_code("eh_print_error", -2, "Error code isn't specified");
	add_error_code("Group1", 1, "invalid amount of arguments");
	print_error(-2, "eh_print_error");
	print_error(print_error(1, "Group1"), "eh_print_error");
	print_error(2, "Group1");
	print_error(1, "Group2");
	printf("Done!");
}