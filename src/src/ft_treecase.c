/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treecase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:03:30 by bgervais          #+#    #+#             */
/*   Updated: 2022/12/19 13:13:36 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lib_push_swap.h"

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
	if ((*p)->content < (*p)->next->content
		&& (*p)->next->content > (*p)->next->next->content
		&& (*p)->next->next->content < (*p)->content)
		ft_rra(p);
}

int	ft_algo_best_pos(t_point p)
{
	int		pos;
	int		total;
	int		i;

	i = 0;
	pos = 0;
	total = p.cout_a[i] + p.cout_b[i];
	i++;
	while (p.cout_b[i] != -1)
	{
		if (total > (p.cout_a[i] + p.cout_b[i])
			&& p.cout_b[i] != -1)
		{
	//p.count_b_bis[i] != -2 
			pos = i;
			total = p.cout_a[i] + p.cout_b[i];
		}
		i++;
	}
//	p.count_b_bis[pos] = -2;
	return (pos);
}
void	ft_affiche_cout(t_point p)
{
	int	i;
	i = 0;

	while (p.cout_b[i] != -1)
	{
		printf("cout a[%d] = %d --- cout b[%d] = %d\n", i, p.cout_a[i], i,  p.cout_b[i]);
		i++;
	}
	printf("\n");
}
void	ft_print(t_list **lst)
{
	t_list	*temp;
	
	temp = *lst;
	while (*lst)
	{
		printf("liste[%d] : %d\n",(*lst)->position, (*lst)->content);
		*lst = (*lst)->next;
	}
	*lst = temp;
}
int	ft_best_option(int value, int len, t_list **lst, int min)
{
	t_list	*temp;
	int		i;
	int		cout;

	temp = *lst;
	cout = -1;
	while (*lst)
	{
		if ((*lst)->content < value && (*lst)->content != min && cout)
		{
//			printf("content :%d\n", (*lst)->content);
//			printf("position %d <= %d len\n", (*lst)->position, len);
			if ((*lst)->position <= (len / 2))
			{
				cout = (*lst)->position;
				i = 1;
			}
//			printf("cout %d > len %d - %d pos \n", cout, len, (*lst)->position);
			if ((((*lst)->position > (len / 2) && (cout > (len - (*lst)->position))) || cout == -1))
			{
				cout = len - (*lst)->position;	
				i = 0;
			}
//			printf("i : %d\n", i);
		}
		*lst = (*lst)->next;
	}
	*lst = temp;
	return (i);
}

void	ft_is_algo(t_list **lst_a, t_list **lst_b, t_point p)
{
	int		i;
	int		pos;

//	ft_print(lst_a);
	while (ft_lstsize(*lst_b) != 0)
	{
		p = ft_cost_value_a(lst_a, lst_b);
		printf("\nlist A\n");
		ft_print(lst_a);
		printf("list B\n");
		ft_print(lst_b);
		ft_affiche_cout(p);
		pos = ft_algo_best_pos(p);
		i = 0;
		while (i < p.cout_b[pos])
		{
			if (pos <= (ft_lstsize(*lst_b) / 2))
				ft_rb(lst_b);
			else
				ft_rrb(lst_b);
			i++;
		}
		i = 0;
		if (p.cout_a[pos] == 1)
			i++;
		while (i++ < (p.cout_a[pos] / 2))
			ft_ra(lst_a);
		i = 0;
		ft_pa(lst_b, lst_a);
		if (p.cout_a[pos] == 1)
		{
			ft_sa(lst_a);
			i++;
		}
		while (i++ < (p.cout_a[pos] / 2) && p.cout_a[pos] != 1)
			ft_rra(lst_a);
		free (p.cout_b);
		free (p.cout_a);
	}
}

t_list	*ft_push_all_to_b(t_list **lst_a)
{
	t_list	*lst_b;
	int		value;
	t_list	*new;
	int		len;

	lst_b = NULL;
	new = ft_copy(lst_a);
	len = ft_lstsize(new) / 2;
	value = ft_sort(&new);
	ft_print(lst_a);
	printf("\nvalue : %d\n", value);
	printf("len : %d\n", len);
	while (*lst_a)
	{
		
		if ((*lst_a)->content == ft_is_min(lst_a)
			|| (*lst_a)->content >= value)
		{
			if (ft_best_option(value, (ft_lstsize(*lst_a)), lst_a, ft_is_min(lst_a)))
				ft_ra(lst_a);
			else
				ft_rra(lst_a);
		}
		else
		{
		printf("%d\n", (*lst_a)->content);
			if (!lst_b)
				lst_b = ft_create_and_delete(lst_a, (*lst_a)->content);
			else
				ft_pb(lst_a, &lst_b);
		ft_print(lst_a);
		}
		if (ft_lstsize(*lst_a) == 3)
		{
			while ((*lst_a)->next->next->content != ft_is_min(lst_a))
				ft_rra(lst_a);
			if ((*lst_a)->content == ft_is_max(lst_a))
				ft_sa(lst_a);
			break ;
		}
		if (ft_lstsize(*lst_a) == len + 2)
		{
			printf("0K\n");
			ft_print(lst_a);
			new = ft_copy(lst_a);
			len = ft_lstsize(new) / 2;
			value = ft_sort(&new);
		printf("\nvalue : %d\n", value);
			printf("len : %d\n\n", len);
	//	printf("valeur : %d best option : %d\n\n",(*lst_a)->content, ft_best_option(value, (ft_lstsize(*lst_a)), lst_a, ft_is_min(lst_a)));
		}
	}
	ft_good_pos(lst_a, &lst_b);
	return (lst_b);
}

/*
t_point	ft_cost_value_b(t_list **lst_b)
{
	t_point	p;
	t_list	*temp_b;
	int		moitie;
	int		len;

	moitie = ft_lstsize(*lst_b) / 2;
	len = ft_lstsize(*lst_b);
//	printf("\ntaille  %d\n", ft_lstsize(*lst_b));
	printf("taille allouer : %d\n\n", ft_lstsize(*lst_b));
	p.cout_b = malloc(sizeof(int) * (ft_lstsize(*lst_b) + 1));
	if (!p.cout_b)
		return (p);
	p.count_b_bis = malloc(sizeof(int) * (ft_lstsize(*lst_b) + 1));
	temp_b = *lst_b;
	while (*lst_b)
	{
		if ((*lst_b)->position <= moitie)
			p.cout_b[(*lst_b)->position] = (*lst_b)->position;
		else if ((*lst_b)->position > moitie && (*lst_b)->position > 1)
			p.cout_b[(*lst_b)->position] = ((len) - (*lst_b)->position);
		if (!(*lst_b)->next)
			p.cout_b[(*lst_b)->position + 1] = -1;
//		printf("\ncout b :%d\n", p.cout_b[(*lst_b)->position]);
		*lst_b = (*lst_b)->next;
	}
	*lst_b = temp_b;
	return (p);
}

t_point	ft_cost_value_a(t_list **lst_a, t_list	**lst_b)
{
	t_point	p;
	t_list	*temp;
	t_list	*temp_b;
	int		i;
	int		count;

	i = 0;
	count = 0;
	p = ft_cost_value_b(lst_b);
	p.cout_a = malloc(sizeof(int) *  (ft_lstsize(*lst_b)));
	temp = *lst_a;
	temp_b = *lst_b;
	while (*lst_b)
	{
		while (p.cout_b[i] != -1)
		{
			if (!((*lst_b)->content < (*lst_a)->content))
			{
				count = 0;
				while ((*lst_b)->content > (*lst_a)->content)
				{
					ft_r(lst_a);
					temp = *lst_a;
					count++;
				}
			}
				p.cout_a[i++] = count * 2;
				while (count > 0)
				{
					ft_pull(lst_a);
					temp = *lst_a;
					count--;
				}
				break;
		}
		*lst_b = (*lst_b)->next;
	}	
	*lst_b = temp_b;
	*lst_a = temp;
	ft_good_pos(lst_a, &temp_b);
	return (p);
}
void	ft_affiche_cout(t_point p)
{
	int	i;
	i = 0;

	while (p.cout_b[i] != -1)
	{
		printf("\n\ncout a[%d] = %d --- cout b[%d] = %d---- bis = %d\n\n", i, p.cout_a[i], i,  p.cout_b[i], p.count_b_bis[i]);
		i++;
	}
}
void ft_print_bis(t_point p)
{
	int i = 0;
	while(p.cout_b[i] != -1)
		printf("\ncout bis = %d\n\n", p.count_b_bis[i++]);
}

int	ft_algo_best_pos(t_point p)
{
	int		pos;
	int		total;
	int		i;
	
	i = 0;
	pos = 0;
	ft_affiche_cout(p);
	total = p.cout_a[i] + p.cout_b[i];
	printf("cout total = %d\n", total);
	i++;
	while (p.cout_b[i] != -1)
	{
		
		if (total >= (p.cout_a[i] + p.cout_b[i]) && (p.count_b_bis[i] != -2 && p.cout_b[i] != -1))
		{
			pos = i;
			total = p.cout_a[i] + p.cout_b[i];
		}
		i++;
	}
	p.count_b_bis[pos] = -2;
	return (pos);
}

int	ft_is_end(t_point p)
{
	int	i;

	i = 0;
	while (p.cout_b[i] != -1)
	{
		if (p.count_b_bis[i] == 0)
			return (1);
		i++;
	}
	return (0);
}

void	ft_affiche_lst(t_list	**lst)
{
	t_list	*temp;

	temp = *lst;
	while (*lst)
	{
		printf("element position : %d --> %d\n",(*lst)->position, (*lst)->content);
		*lst = (*lst)->next;
	}
	*lst = temp;
}

void	ft_is_algo(t_list **lst_a, t_list **lst_b, t_point p)
{
	int		i;
	int		pos;
	int		len;

	while (ft_is_end(p))
	{
		p = ft_cost_value_a(lst_a, lst_b);
		ft_affiche_lst(lst_b);
		printf("\n\n-----\n\n");
		ft_affiche_lst(lst_a);
		pos = ft_algo_best_pos(p);
		printf("pos : %d\n", pos);
		i = 0;
		len = ft_lstsize(*lst_b);
		while (i < p.cout_b[pos])
		{
			if (pos <= (len / 2))
				ft_r(lst_b);
			else
				ft_pull(lst_b);
				
			i++;
		}
		i = 0;
		while (i < (p.cout_a[pos] / 2))
		{
			ft_r(lst_a);
			i++;
		}
		i = 0;
		ft_pa(lst_b, lst_a);
		while (i < (p.cout_a[pos] / 2))
		{
			ft_rra(lst_a);
			i++;
		}
	//	printf("Apres lst b\n");
	//	ft_affiche_lst(lst_b);
	}
}

			
void	ft_clear_element(t_list	**lst)
{
	t_list	*temp;

	temp = (*lst)->next;
	(*lst)->next = NULL;
	free (*lst);
	*lst = temp;
}

t_list	*ft_push_all_to_b(t_list **lst_a)
{
	t_list	*lst_b;
	t_list	*temp_a;
	t_list	*temp_b;
	
	while (*lst_a)
	{
		temp_a = (*lst_a)->next;
		if ((*lst_a)->content == ft_is_min(lst_a) || (*lst_a)->content == ft_is_max(lst_a))
			ft_r(lst_a);
		else
		{
			if (!lst_b)
			{
				lst_b = ft_create_element((*lst_a)->content);
				ft_clear_element(lst_a);
			}
			else
				ft_pb(lst_a, &lst_b);
			temp_b = lst_b;
		}
		if (ft_lstsize(*lst_a) == 2)
			break;
	}
	*lst_a = temp_a;
	ft_good_pos(lst_a, &temp_b);
	return (temp_b);
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

void	ft_is_algo(t_list **lst_a, t_list **lst_b, t_point p)
{
	int		i;
	int		pos;
	int		len;

	while (ft_is_end(p))
	{
		p = ft_cost_value_a(lst_a, lst_b);
		ft_affiche_lst(lst_b);
		printf("\n\n-----\n\n");
		ft_affiche_lst(lst_a);
		pos = ft_algo_best_pos(p);
		printf("pos : %d\n", pos);
		i = 0;
		len = ft_lstsize(*lst_b);
		while (i < p.cout_b[pos])
		{
			if (pos <= (len / 2))
				ft_r(lst_b);
			else
				ft_pull(lst_b);
				
			i++;
		}
		i = 0;
		while (i < (p.cout_a[pos] / 2))
		{
			ft_r(lst_a);
			i++;
		}
		i = 0;
		ft_pa(lst_b, lst_a);
		while (i < (p.cout_a[pos] / 2))
		{
			ft_rra(lst_a);
			i++;
		}
	//	printf("Apres lst b\n");
	//	ft_affiche_lst(lst_b);
	}
}

*/
