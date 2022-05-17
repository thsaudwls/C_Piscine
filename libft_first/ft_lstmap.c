/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnyeong._.jin <rnyeong._.jin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:13:28 by rnyeong._.j       #+#    #+#             */
/*   Updated: 2022/05/17 15:03:09 by rnyeong._.j      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *result;
    t_list *new;

    if (lst == 0x00 || f == 0x00)
        return (0x00);
    result = ft_lstnew(f(lst->content));
    if (result == 0x00)
        return (0x00);
    new = result;
    lst = lst->next;
    while (lst != 0x00)
    {
        new->next = ft_lstnew(f(lst->content));
        if (new == 0x00)
        {
            ft_lstclear(&result, del);
            return (0x00);
        }
        new = new->next;
        lst = lst->next;
    }
    return (result);
}