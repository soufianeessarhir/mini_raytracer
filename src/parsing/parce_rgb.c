/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:18:32 by sessarhi          #+#    #+#             */
/*   Updated: 2024/12/24 14:06:05 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../minirt.h"

int check_pnt(const char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i])
    {
        if (str[i] == ',')
            count++;
        i++;
    }
    return (count);
}
bool	parse_rgb(const char *str ,int *r ,int *g ,int *b)
{
    char **tab;

    if (check_pnt(str) != 2)
        return (false);
    tab = ft_split(str, ',');
    if (!tab)
        return (false);
    *r = Rgb_value(tab[0]);
    *g = Rgb_value(tab[1]);
    *b = Rgb_value(tab[2]);
    free(tab);
    if (*r == -1 || *g == -1 || *b == -1)
        return (false);
    return (true);
}
