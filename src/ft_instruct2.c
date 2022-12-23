/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruct2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:31:21 by bgervais          #+#    #+#             */
/*   Updated: 2022/12/21 16:53:24 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lib_push_swap.h"

void	ft_sa(t_list **lst)
{
	int	temp;

	if (*lst && (*lst)->next)
	{
		temp = (*lst)->content;
		(*lst)->content = (*lst)->next->content;
		(*lst)->next->content = temp;
		ft_printf("sa\n");
	}
}

void	ft_sb(t_list **lst)
{
	int	temp;

	if (*lst && (*lst)->next)
	{
		temp = (*lst)->content;
		(*lst)->content = (*lst)->next->content;
		(*lst)->next->content = temp;
		ft_printf("sb\n");
	}
}

void	ft_pb(t_list **lst, t_list **lst2)
{
	t_list	*temp;
	t_list	*temp2;

	temp2 = creat_elem((*lst)->content, (*lst)->position);
	temp = (*lst)->next;
	free(*lst);
	*lst = temp;
	ft_lstadd_front(lst2, temp2);
	ft_good_pos_unique(lst);
	ft_printf("pb\n");
}

void	ft_pa(t_list **lst, t_list **lst2)
{
	t_list	*temp;
	t_list	*temp2;

	temp2 = ft_create_element((*lst)->content);
	temp = (*lst)->next;
	free(*lst);
	*lst = temp;
	ft_lstadd_front(lst2, temp2);
	ft_good_pos_unique(lst);
	ft_printf("pa\n");
}
