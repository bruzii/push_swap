/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special_case.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:45:31 by bgervais          #+#    #+#             */
/*   Updated: 2022/12/23 14:13:15 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lib_push_swap.h"

void	ft_is_2(t_list **p)
{
	if ((*p)->content > (*p)->next->content)
		ft_sa(p);
}

void	ft_reduc(t_list **p)
{
	if ((*p)->content < (*p)->next->content
		&& (*p)->next->content > (*p)->next->next->content
		&& (*p)->next->next->content < (*p)->content)
		ft_rra(p);
}

void	ft_is_3(t_list	**p)
{
	if ((*p)->content > (*p)->next->content
		&& (*p)->next->content < (*p)->next->next->content
		&& (*p)->next->next->content > (*p)->content)
		ft_sa(p);
	if ((*p)->content > (*p)->next->content
		&& (*p)->next->content > (*p)->next->next->content
		&& (*p)->next->next->content < (*p)->content)
	{
		ft_sa(p);
		ft_rra(p);
	}
	if ((*p)->content > (*p)->next->content
		&& (*p)->next->content < (*p)->next->next->content
		&& (*p)->next->next->content < (*p)->content)
		ft_ra(p);
	if ((*p)->content < (*p)->next->content
		&& (*p)->next->content > (*p)->next->next->content
		&& (*p)->next->next->content > (*p)->content)
	{
		ft_sa(p);
		ft_ra(p);
	}
	ft_reduc(p);
}

void	ft_is_5(t_list **lst_a)
{
	t_list	*lst_b;
	int		median;
	t_list	*cpy;

	lst_b = NULL;
	cpy = ft_copy(lst_a);
	median = ft_sort(&cpy);
	while (1)
	{
		while ((*lst_a)->content >= median)
			ft_ra(lst_a);
		if (!lst_b)
			lst_b = ft_create_and_delete(lst_a, (*lst_a)->content);
		else
			ft_pb(lst_a, &lst_b);
		if (ft_lstsize(*lst_a) == 3)
			break ;
	}
	ft_is_3(lst_a);
	if (lst_b->content < lst_b->next->content)
		ft_sb(&lst_b);
	ft_pa(&lst_b, lst_a);
	ft_pa(&lst_b, lst_a);
	ft_lstclear_bis(&cpy);
}

void	ft_short(t_list **lst_a)
{
	if (ft_lstsize(*lst_a) <= 1)
	{
		ft_printf("Error\n");
		return ;
	}
	else
	{
		if (ft_lstsize(*lst_a) == 2)
			ft_is_2(lst_a);
		if (ft_lstsize(*lst_a) == 3)
			ft_is_3(lst_a);
		if (ft_lstsize(*lst_a) == 5)
			ft_is_5(lst_a);
	}
}
