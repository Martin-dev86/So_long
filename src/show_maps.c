/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagarci2 <cagarci2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:16:41 by cagarci2          #+#    #+#             */
/*   Updated: 2024/07/24 18:15:18 by cagarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    load_texture(t_game *game)
{
    game->textures = ft_calloc(1, sizeof(t_textures));
    game->textures->floor = mlx_load_png("./input/floor.png");
    game->textures->wall = mlx_load_png("./input/wall.png");
    game->textures->character = mlx_load_png("./input/mando.png");
    game->textures->collect = mlx_load_png("./input/baby_yoda.png");
    game->textures->exit = mlx_load_png("./input/nave.png");
}
void    load_image(t_game *game)
{
    game->images = ft_calloc(1, sizeof(t_images));
    game->images->collect = mlx_texture_to_image(game->mlx, game->textures->collect);
    game->images->wall = mlx_texture_to_image(game->mlx, game->textures->wall);
    game->images->character = mlx_texture_to_image(game->mlx, game->textures->character);
    game->images->floor = mlx_texture_to_image(game->mlx, game->textures->floor);
    game->images->exit = mlx_texture_to_image(game->mlx, game->textures->exit);
    mlx_delete_texture(game->textures->character);
    mlx_delete_texture(game->textures->collect);
	mlx_delete_texture(game->textures->floor);
	mlx_delete_texture(game->textures->wall);
	mlx_delete_texture(game->textures->exit);
}
void    display_game(t_game *game, t_images *image)
{
    int y;
    int x;

    y = 0;
    x = 0;
    while(game->maps[y])
    {
        x = 0;
        while(game->maps[y][x] != '\0')
        {
            if(game->maps[y][x] == WALL)
                mlx_image_to_window(game->mlx, image->wall, x * 64, y * 64);
            if(game->maps[y][x] != '1')
                mlx_image_to_window(game->mlx, image->floor, x * 64, y * 64);
            if(game->maps[y][x] == EXIT_MAP)
                mlx_image_to_window(game->mlx, image->exit, x * 64, y * 64);
            if(game->maps[y][x] == COLLECT)
                mlx_image_to_window(game->mlx, image->collect, x * 64, y * 64);
            if(game->maps[y][x] == START_PLAYER)
                mlx_image_to_window(game->mlx, image->character, x * 64, y * 64);
            x++;
        }
        y++;
    }
}