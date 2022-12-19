/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruct4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:45:26 by bgervais          #+#    #+#             */
/*   Updated: 2022/12/15 17:12:28 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lib_push_swap.h"

int	ft_is_min(t_list **lst)
{
	t_list	*temp;
	int		min;

	temp = *lst;
	min = (*lst)->content;
	*lst = (*lst)->next;
	while ((*lst))
	{
		if (min > (*lst)->content)
			min = (*lst)->content;
		*lst = (*lst)->next;
	}
	*lst = temp;
	return (min);
}

int	ft_is_max(t_list **lst)
{
	t_list	*temp;
	int		max;

	temp = *lst;
	max = (*lst)->content;
	*lst = (*lst)->next;
	while ((*lst))
	{
		if (max < (*lst)->content)
			max = (*lst)->content;
		*lst = (*lst)->next;
	}
	*lst = temp;
	return (max);
}

void	ft_clear_element(t_list	**lst)
{
	t_list	*temp;

	temp = (*lst)->next;
	(*lst)->next = NULL;
	free (*lst);
	*lst = temp;
}

void	ft_good_pos(t_list **lst_a, t_list **lst_b)
{
	t_list	*temp;
	t_list	*temp_b;
	int		i;

	i = 0;
	temp = *lst_a;
	while (*lst_a)
	{
		(*lst_a)->position = i++;
		*lst_a = (*lst_a)->next;
	}
	*lst_a = temp;
	temp_b = *lst_b;
	i = 0;
	while (*lst_b)
	{
		(*lst_b)->position = i++;
		(*lst_b) = (*lst_b)->next;
	}
	*lst_b = temp_b;
}

void	ft_good_pos_unique(t_list **lst_a)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = *lst_a;
	while (*lst_a)
	{
		(*lst_a)->position = i++;
		*lst_a = (*lst_a)->next;
	}
	*lst_a = temp;
}
