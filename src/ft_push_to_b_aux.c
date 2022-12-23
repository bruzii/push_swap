/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_b_aux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:34:58 by bgervais          #+#    #+#             */
/*   Updated: 2022/12/23 14:14:07 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	ft_is_no_option1(int value, t_list **lst)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = *lst;
	while (*lst)
	{
		if ((*lst)->content < value)
			i = 1;
		*lst = (*lst)->next;
	}
	*lst = temp;
	return (i);
}

int	ft_best_option(int value, int len, t_list **lst)
{
	t_list	*temp;
	int		i;
	int		cout;

	temp = *lst;
	i = 0;
	cout = -1;
	while (*lst)
	{
		if ((*lst)->content < value)
		{
			if ((*lst)->position <= (len / 2))
			{
				cout = (*lst)->position;
				i = 1;
			}
			if (((*lst)->position > (len / 2)
					&& (cout > (len - (*lst)->position))) || cout == -1)
				cout = len - (*lst)->position;
		}
		*lst = (*lst)->next;
	}
	*lst = temp;
	return (i);
}
