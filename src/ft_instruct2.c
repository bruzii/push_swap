/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruct2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:38:29 by bgervais          #+#    #+#             */
/*   Updated: 2022/12/13 15:46:59 by bgervais         ###   ########.fr       */
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
	(*lst)->next = NULL;
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
	(*lst)->next = NULL;
	free(*lst);
	*lst = temp;
	ft_lstadd_front(lst2, temp2);
	ft_good_pos_unique(lst);
	ft_printf("pa\n");
}

/*
int	*ft_pb(int *pile_a, int *pile_b)
{
	int	i;
	int	*pile_b_new;
	int	len;

	len = ft_strlen_int(pile_b);	
	pile_b_new = malloc(sizeof(int) * (len + 2));
	if (!pile_b_new)
		return (0);
	i = 0;
	pile_b_new[i] = pile_a[i];
	while (pile_b[i - 1] != -1)
	{
		i++;
		pile_b_new[i] = pile_b[i - 1];
	}
	pile_b_new[i] = -1;
	i = 0;
	while (pile_a[i] != -1)
	{
		pile_a[i] = pile_a[i + 1];
		i++;
	}
	free (pile_b);
	ft_printf("pb\n");
	return (pile_b_new);
}

void	ft_less_one(t_list **lst)
{
	t_list	*temp;
	int		len;

	len = ft_lstsize(*lst);
	temp = *lst;
	while ((*lst)->next)
	{
		(*lst)->position = (*lst)->position - 1;
		*lst = (*lst)->next;
	}
	(*lst)->position = len - 1;
	*lst = temp;
}
void	ft_r(int *pile_a)
{
	int	count;
	int	i;
	int	*temp;

	i = 0;
	count = ft_strlen_int(pile_a);
	temp = malloc(sizeof(int) * (count + 1));
	if (!temp)
		return ;
	temp[i++] = pile_a[count - 1];
	while (pile_a[i] != -1)
	{
		temp[i] = pile_a[i - 1];
		i++;
	}
	temp[i] = -1;
	i = 0;
	while (temp[i] != -1)
	{
		pile_a[i] = temp[i];
		i++;
	}
	free (temp);
}
*/
