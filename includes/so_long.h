/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagarci2 <cagarci2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:19:40 by cagarci2          #+#    #+#             */
/*   Updated: 2024/07/24 17:55:44 by cagarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <memory.h>
# include <stdint.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "MLX42.h"
# include "libft.h"
# include "ft_printf.h"

# define EXIT_MAP 'E'
# define START_PLAYER 'P'
# define COLLECT 'C'
# define WALL '1'
# define FLOOR '0'

typedef struct s_images
{
	mlx_image_t	    *floor;
	mlx_image_t		*wall;
	mlx_image_t		*collect;
	mlx_image_t		*character;
    mlx_image_t       *exit;
}						t_images;
typedef struct s_texture
{
	mlx_texture_t		*floor;
	mlx_texture_t		*wall;
	mlx_texture_t		*collect;
	mlx_texture_t		*character;
    mlx_texture_t       *exit;
}						t_textures;
typedef struct s_game
{
    struct s_texture	*textures;
    struct s_images     *images;
    mlx_t				*mlx;
    char                **maps;
    int                 width;
    int                 heigth;
	int					move_counter;
}           t_game;

int     check_extension(char *file);
char    **read_maps(char *file);
int     check_maps(t_game game);
int     check_wall(char **maps, t_game *game);
int     check_component(char **maps, char component);
int 	check_error(t_game *game);
int     f_strlen(const char *c);
void    load_texture(t_game *game);
void    load_image(t_game *game);
void    display_game(t_game *game, t_images *images);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	ft_key_move(mlx_key_data_t keydata, void *param);

#endif