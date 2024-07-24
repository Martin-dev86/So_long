/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagarci2 <cagarci2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:07:31 by cagarci2          #+#    #+#             */
/*   Updated: 2024/07/24 18:18:49 by cagarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	if (game->maps[game->images->character->instances->y / 64
			- 1][game->images->character->instances->x / 64] != WALL)
	{
		game->images->character->instances->y -= 64;
		game->move_counter++;
		ft_printf("MOVE: %i\n", game->move_counter);
	}
}

void	move_down(t_game *game)
{
	if (game->maps[game->images->character->instances->y / 64
			+ 1][game->images->character->instances->x / 64] != WALL)
	{
		game->images->character->instances->y += 64;
		game->move_counter++;
		ft_printf("MOVE: %i\n", game->move_counter);
	}
}

void	move_left(t_game *game)
{
	if (game->maps[game->images->character->instances->y
			/ 64][game->images->character->instances->x / 64 - 1] != WALL)
	{
		game->images->character->instances->x -= 64;
		game->move_counter++;
		ft_printf("MOVE: %i\n", game->move_counter);
	}
}

void	move_right(t_game *game)
{
	if (game->maps[game->images->character->instances->y
			/ 64][game->images->character->instances->x / 64 + 1] != WALL)
	{
		game->images->character->instances->x += 64;
		game->move_counter++;
		ft_printf("MOVE: %i\n", game->move_counter);
	}
}

void	ft_key_move(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		move_up(game);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		move_down(game);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		move_left(game);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		move_right(game);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(game->mlx);
		ft_printf("\nClosed Game-You Lose");
		return ;
	}
}