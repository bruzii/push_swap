/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:54:19 by bgervais          #+#    #+#             */
/*   Updated: 2022/12/21 18:07:39 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lib_push_swap.h"

void	ft_free_p(t_point p)
{
	free (p.valeur);
	free (p.cout_a);
	free (p.cout_b);
}

void	ft_del(int *content)
{
	if (content)
	{
		free(content);
		content = NULL;
	}
}

void	ft_lstclear_bis(t_list **lst)
{
	t_list	*temp;
	t_list	*next;

	temp = *lst;
	while (temp)
	{
		next = temp->next;
		free (temp);
		temp = next;
	}
	*lst = NULL;
}
