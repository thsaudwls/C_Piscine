/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnyeong._.jin <rnyeong._.jin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:45:20 by rnyeong._.j       #+#    #+#             */
/*   Updated: 2022/05/16 14:53:30 by rnyeong._.j      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst)
{
    int cnt;

    cnt = 0;
    if (lst == 0x00)
        return (0);
    while (lst != 0x00)
    {
        lst = lst->next;
        cnt ++;
    }
    return (cnt);
}