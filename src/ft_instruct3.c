/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruct3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:47:18 by bgervais          #+#    #+#             */
/*   Updated: 2022/12/23 15:07:50 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lib_push_swap.h"

t_list	*creat_elem(int data, int pos)
{
	t_list	*temp;

	temp = malloc(sizeof(t_list));
	if (!temp)
		return (0);
	temp->content = data;
	temp->position = pos;
	temp->next = NULL;
	return (temp);
}

t_list	*ft_create_element(int pos)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (0);
	lst->content = pos;
	lst->next = NULL;
	return (lst);
}

int	ft_is_sorted(t_list	**lst)
{
	t_list	*temp;
	t_list	*k;

	temp = *lst;
	while ((*lst))
	{
		k = (*lst)->next;
		while (k)
		{
			if (k->content < (*lst)->content)
			{
				*lst = temp;
				return (1);
			}
			k = k->next;
		}
		(*lst) = (*lst)->next;
	}
	*lst = temp;
	return (0);
}

t_list	*ft_create_and_delete(t_list **lst, int pos)
{
	t_list	*lst_a;

	lst_a = ft_create_element(pos);
	ft_clear_element(lst);
	ft_printf("pb\n");
	return (lst_a);
}

int	ft_check_double_one(char *str, int *nbr)
{
	int	i;
	int	k;
	int	len;

	i = 0;
	len = ft_check(str);
	while (i < len)
	{
		k = i + 1;
		while (k < len)
		{
			if (nbr[i] == nbr[k])
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}
