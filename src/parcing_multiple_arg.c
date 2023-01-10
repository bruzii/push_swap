/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_multiple_arg.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgervais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:49:40 by bgervais          #+#    #+#             */
/*   Updated: 2022/12/23 14:41:34 by bgervais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lib_push_swap.h"

int	ft_len(char *str)
{
	int	i;
	int	s;

	s = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			s = 1;
		i++;
	}
	if ((s == 1 && i == 11) || (!s && i == 10))
		return (-1);
	if ((!s && i > 10) || (s == 1 && i > 11))
		return (0);
	return (1);
}

int	ft_check_string(char *str)
{
	int	i;
	int	signe;

	signe = 0;
	i = 0;
	if (str[i] == '-')
	{
		i++;
		signe = 1;
	}
	while (str[i])
	{
		if (!(str[i] <= '9' && str[i] >= '0'))
			return (0);
		i++;
	}
	return (1 + signe);
}

int	ft_check_int_aux(char *str, int t, int i)
{
	char	*nb;
	char	*nb_n;

	nb = "2147483647";
	nb_n = "-2147483648";
	if (!t)
	{
		while (str[i])
		{
			if (str[i] > nb_n[i])
				return (0);
			i++;
		}
	}
	if (t == 1)
	{
		while (str[i])
		{
			if (str[i] > nb[i])
				return (0);
			i++;
		}
	}
	return (1);
}

int	ft_check_int(char *str)
{
	int		i;

	i = 0;
	if (ft_len(str) == 0)
		return (0);
	if (ft_len(str) == -1)
	{
		if (str[0] == '-')
			ft_check_int_aux(str, 0, i);
		else
			ft_check_int_aux(str, 1, i);
	}
	return (1);
}

t_list	*ft_recup_list(int argc, char **argv)
{
	int		i;
	int		*nbr;
	t_list	*lst;
	t_list	*cpy;

	i = 0;
	if (argc == 1)
	{
		ft_printf("Error\n");
		return (NULL);
	}
	nbr = ft_recup(argc, argv);
	if (!nbr)
		return (NULL);
	lst = creat_elem(nbr[i], i);
	cpy = lst;
	i++;
	while (i < (argc - 1))
	{
		lst->next = creat_elem(nbr[i], i);
		lst = lst->next;
		i++;
	}
	return (free(nbr), cpy);
}
