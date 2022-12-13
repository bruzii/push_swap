/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruct3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:47:18 by bgervais          #+#    #+#             */
/*   Updated: 2022/12/13 15:48:05 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lib_push_swap.h"

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

void	ft_add_one(t_list **lst)
{
	t_list	*temp;

	temp = *lst;
	(*lst)->position = 0;
	*lst = (*lst)->next;
	while (*lst)
	{
		(*lst)->position = (*lst)->position + 1;
		(*lst) = (*lst)->next;
	}
	*lst = temp;
}

int	ft_is_sorted(t_list	**lst)
{
	t_list	*temp;
	t_list	*k;

	temp = *lst;
	while ((*lst)->next)
	{
		k = (*lst)->next;
		while (k->next)
		{
			if (k->content < (*lst)->content)
				return (1);
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
	return (lst_a);
}

/*
void	ft_push(int *pile_a)
{
	int	count;
	int	i;
	int	*temp;

	i = 0;
	count = ft_strlen_int(pile_a);
	temp = malloc(sizeof(int) * (count + 1));
	if (!temp)
		return ;
	temp[count--] = -1;
	temp[0] = pile_a[count];
	while (count != 0)
	{
		temp[count] = pile_a[count - 1];
		count--;
	}
	i = 0;
	while (temp[i] != -1)
	{
		pile_a[i] = temp[i];
		i++;
	}
	free (temp);
}


int	ft_is_sorted(int *pile_a)
{
	int	i;
	int	k;

	i = 0;
	while (pile_a[i] != -1)
	{
		k = i + 1;
		while (pile_a[k] != -1)
		{
			if (pile_a[k] < pile_a[i])
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}
*/
