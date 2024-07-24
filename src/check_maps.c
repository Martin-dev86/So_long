/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagarci2 <cagarci2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:21:56 by cagarci2          #+#    #+#             */
/*   Updated: 2024/07/24 17:18:36 by cagarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	f_strlen(const char *c)
{
	int	i;

	i = 0;
	while (*c && *c != '\r')
	{
		c++;
		i++;
	}
	return (i);
}

int check_maps(t_game game)
{
    int len;
    int i;
    int j;
    
    len = f_strlen(game.maps[0]);
    i = 0;
    while(game.maps[i])
    {
        j = f_strlen(game.maps[i]);
        if(len != j)
            return(0);
        j = 0;
        i++;
    }
    return(1);
}
int check_wall(char **maps, t_game *game)
{   
    int i;
    int j;
    int h;

    i = 0;
    j = 0;
    h = 0;
    game->heigth = 0;
    game->width = f_strlen(maps[0]);
    while(maps[game->heigth])     
        game->heigth++;
    while(maps[i][j] != '\0' && maps[i][j] != '\r')
    {
        if (maps[i][j] != WALL)
            return (0);
        j++;
    }
    i++;
    while (maps[i])
    {
        if(maps[i][0] != WALL || maps[i][game->width - 1] != WALL)
            return(0);
        i++;
    }
    i--;
    while(maps[i][h] != '\0' && maps[i][h] != '\r')
    {
        if (maps[i][h] != WALL)
            return (0);
        h++;
    }
    game->width = game->width * 64;
    game->heigth = game->heigth * 64;
    return(1);
}
int check_component(char **maps, char component)
{
    int flag;
    int i;
    int j;
    
    flag = 0;
    i = 0;
    j = 0;
    while (maps[i])
    {
        while(maps[i][j] != '\0')
        {
            if (maps[i][j] == component)
                flag += 1;
            j++;
        }
        j = 0;
        i++;
    }
    return (flag);
}