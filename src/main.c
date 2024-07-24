/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagarci2 <cagarci2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:04:06 by cagarci2          #+#    #+#             */
/*   Updated: 2024/07/24 17:55:24 by cagarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_error(t_game *game)
{
		if (check_maps(*game) == 0)
			{
				printf("Error: dimension no valida\n");
				return(0);
			}
		if (check_wall((*game).maps, game) == 0)
			{
				printf("Error: muros no validos\n");
				return(0);
			}
		if (check_component((*game).maps, EXIT_MAP) == 0 || (check_component((*game).maps, EXIT_MAP) > 1))
		{	
			printf("Error: No hay salida valida\n");
			return(0);
		}
		if (check_component((*game).maps, START_PLAYER) == 0 || (check_component((*game).maps, START_PLAYER) > 1))
		{	
			printf("Error: No hay Jugador\n");
			return(0);
		}
		if (check_component((*game).maps, COLLECT) == 0)
		{	
			printf("Error: No hay coleccionable\n");
			return(0);
		}
		return(1);
}
int	game_init(t_game *game)
{
	game->move_counter = 0;
	game->mlx = mlx_init(game->width, game->heigth, "so_long", false);
	if (!game->mlx)
        return(0);
	load_texture(game);
	load_image(game);
	display_game(game, game->images);
	mlx_key_hook(game->mlx, &ft_key_move, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return(1);
}

int32_t	main(int argc, char **argv)
{
	t_game	game;
	
	if (argc == 2)
	{
		game.maps = read_maps(argv[1]);
		if (game.maps == 0)
			return(EXIT_FAILURE);
		if (check_error(&game) == 0)
			return(EXIT_FAILURE);
		game_init(&game);
	}

	return (EXIT_SUCCESS);
}
