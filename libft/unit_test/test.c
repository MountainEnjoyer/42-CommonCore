/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                              :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 17:25:00 by zchauve           #+#    #+#             */
/*   Updated: 2026/10/09 19:03:36 by zchauve        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../libft.h"
#include <bsd/string.h>

int	intArrTesting()
{
	return (0);
}

int	strTesting()
{
	return (0);
}

int	intTesting()
{
	return (0);
}

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("[%s] -> ", (char *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

void	free_list(t_list *lst)
{
	t_list	*next;

	while (lst)
	{
		next = lst->next;
		free(lst);
		lst = next;
	}
}

int	main(void)
{
	t_list	*head;

	head = NULL;
	printf("Empty list: ");
	print_list(head);

	ft_lstadd_front(&head, ft_lstnew("third"));
	printf("Add to empty list: ");
	print_list(head);

	ft_lstadd_front(&head, ft_lstnew("second"));
	printf("Add second: ");
	print_list(head);

	ft_lstadd_front(&head, ft_lstnew("first"));
	printf("Add first: ");
	print_list(head);

	free_list(head);
	return (0);
}
