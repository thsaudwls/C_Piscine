/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnyeong._.jin <rnyeong._.jin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:28:21 by rnyeong._.j       #+#    #+#             */
/*   Updated: 2022/05/16 14:53:01 by rnyeong._.j      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == 0x00 || new == 0x00)
		return ;
	new->next = *lst;
	*lst = new;
}
