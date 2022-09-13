/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnyeong._.jin <rnyeong._.jin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:07:00 by rnyeong._.j       #+#    #+#             */
/*   Updated: 2022/09/06 11:31:29 by rnyeong._.j      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char    *map_init(char *first_line_map)
{
    int     i;
    char    *new;

    i  = 0;
    new = (char*)malloc(sizeof(char) * (ft_strlen(first_line_map)));
    if (!new)
        return (NULL);
    while (i < (int)ft_strlen(first_line_map))
    {
        new[i] = first_line_map[i];
        i ++;
    }
    return (new);
}

char    *map_connect(char *s1, char *s2)
{
    char    *new;
    int     i;
    int     j;

    i = 0;
    j = 0;
    if (s1 == NULL && s2 == NULL)
        return (NULL);
    new = (char *)malloc(sizeof(char) *(ft_strlen(s1) + ft_strlen(s2) - 1));
    if (!new)
        return (NULL);
    while (s1[i] != '\n' && s1[i] != '\0')
    {
        new[i] = s1[i];
        i ++;
    }
    while (i < (int)ft_strlen(s1) - 1 + (int)ft_strlen(s2))
    {
        new[i] = s2[j];
        i ++;
        j ++;
    }
    free(s1);
    free(s2);
    return (new);
}