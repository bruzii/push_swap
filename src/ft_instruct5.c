/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruct5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:40:57 by bgervais          #+#    #+#             */
/*   Updated: 2022/12/13 15:41:03 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lib_push_swap.h"

void	ft_r(t_list **lst)
{
	t_list	*temp;
	t_list	*temp2;

	temp = (*lst)->next;
	temp2 = ft_create_element((*lst)->content);
	(*lst)->next = NULL;
	free(*lst);
	*lst = temp;
	ft_lstadd_back(lst, temp2);
	ft_good_pos_unique(lst);
}

void	ft_ra(t_list **lst)
{
	ft_r(lst);
	ft_printf("ra\n");
}

void	ft_rb(t_list **lst)
{
	ft_r(lst);
	ft_printf("rb\n");
}

void	ft_rr(t_list **lst, t_list **lst2)
{
	ft_r(lst);
	ft_r(lst2);
	ft_printf("rr\n");
}
