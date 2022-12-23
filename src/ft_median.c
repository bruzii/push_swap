/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_median.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:49:37 by bgervais          #+#    #+#             */
/*   Updated: 2022/12/21 17:45:35 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lib_push_swap.h"

void	bubble_sort(t_list **arr)
{
	int		flag;
	t_list	*temp;
	int		t;

	flag = 1;
	temp = *arr;
	while (flag)
	{
		flag = 0;
		*arr = temp;
		while ((*arr)->next)
		{
			if ((*arr)->content > (*arr)->next->content)
			{
				t = (*arr)->content;
				(*arr)->content = (*arr)->next->content;
				(*arr)->next->content = t;
				flag = 1;
			}
			*arr = (*arr)->next;
		}
	}
	*arr = temp;
}

t_list	*ft_copy(t_list	**lst)
{
	t_list	*new;
	t_list	*temp;
	t_list	*tmp;

	temp = *lst;
	new = creat_elem((*lst)->content, (*lst)->position);
	tmp = new;
	*lst = (*lst)->next;
	while (*lst)
	{
		new->next = creat_elem((*lst)->content, (*lst)->position);
		*lst = (*lst)->next;
		new = new->next;
	}
	*lst = temp;
	return (tmp);
}

void	ft_clear_and_copy(t_list	**lst, t_list **new)
{
	t_list	*temp;
	t_list	*tmp;

	ft_lstclear_bis(new);
	temp = *lst;
	*new = creat_elem((*lst)->content, (*lst)->position);
	tmp = *new;
	*lst = (*lst)->next;
	while (*lst)
	{
		(*new)->next = creat_elem((*lst)->content, (*lst)->position);
		*lst = (*lst)->next;
		*new = (*new)->next;
	}
	*lst = temp;
	*new = tmp;
}

int	ft_sort(t_list **lst)
{
	int		moitie;
	int		valeur_median;
	t_list	*temp;

	bubble_sort(lst);
	moitie = ft_lstsize(*lst) / 2;
	temp = *lst;
	while (*lst)
	{
		if ((*lst)->position == moitie)
			valeur_median = (*lst)->content;
		*lst = (*lst)->next;
	}
	*lst = temp;
	return (valeur_median);
}

int	ft_comp(int value, int value2)
{
	if (value >= value2)
		return (1);
	return (0);
}
