/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:50:24 by bgervais          #+#    #+#             */
/*   Updated: 2022/12/26 11:10:02 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	ft_do_instruct(char *str, t_list **lst_a, t_list **lst_b)
{
	if (!ft_strncmp(str, "pa", 2))
		ft_p(lst_b, lst_a);
	if (!ft_strncmp(str, "pb", 2))
	{
		if (!lst_b)
			ft_create(lst_a, (*lst_a)->content);
		else
			ft_p(lst_a, lst_b);
	}
	if (!ft_strncmp(str, "ra", 2))
		ft_r(lst_a);
	if (!ft_strncmp(str, "rra", 3))
		ft_pull(lst_a);
	if (!ft_strncmp(str, "rrr", 3))
		ft_rrr(lst_a, lst_b);
	if (!ft_strncmp(str, "rb", 2))
		ft_r(lst_b);
	if (!ft_strncmp(str, "rrb", 3))
		ft_pull(lst_b);
	if (!ft_strncmp(str, "sa", 2))
		ft_s(lst_a);
	if (!ft_strncmp(str, "sb", 2))
		ft_s(lst_b);
}

int	ft_parcing(char *str)
{
	if (ft_strncmp(str, "pa", 2) && ft_strncmp(str, "pb", 2)
		&& ft_strncmp(str, "ra", 2) && ft_strncmp(str, "rra", 3)
		&& ft_strncmp(str, "rrr", 2) && ft_strncmp(str, "rb", 2)
		&& ft_strncmp(str, "rrb", 3) && ft_strncmp(str, "sa", 2)
		&& ft_strncmp(str, "sb", 2))
		return (0);
	return (1);
}

void	ft_checker(t_list **lst_a, t_list **lst_b)
{
	char	*str;

	str = get_next_line(0);
	while (str != NULL)
	{
		if (!ft_parcing(str))
		{
			ft_putstr_fd("Error\n", 2);
			return ;
		}
		ft_do_instruct(str, lst_a, lst_b);
		free (str);
		str = get_next_line(0);
	}
	if (ft_is_sorted(lst_a))
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
}

int	main(int argc, char **argv)
{
	t_list	*pile_a;
	t_list	*pile_b;

	pile_b = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2)
		pile_a = ft_recup_list_one(argv[1]);
	else
		pile_a = ft_recup_list(argc, argv);
	if (!pile_a)
	{
		ft_lstclear_bis(&pile_a);
		return (0);
	}
	ft_checker(&pile_a, &pile_b);
	ft_lstclear_bis(&pile_a);
	return (0);
}
