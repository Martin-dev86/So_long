/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagarci2 <cagarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:57:07 by cagarci2          #+#    #+#             */
/*   Updated: 2024/07/24 00:06:06 by cagarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_extension(char *file)
{
    int len;

    len = ft_strlen(file);
    if (file[len - 1] != 'r' || file[len - 2] != 'e' || file[len - 3] != 'b' || file[len - 4] != '.')
        return (0);
    return(1);
}

char    **read_maps(char *file)
{
    char    **maps;
    int     fd;
    char    *map_temp;
    int     read_cont;
    size_t file_size;
    char    buffer[1024];

    file_size = 0;
    if (!check_extension(file))
        return(ft_printf("%s Error : Extension no valida."), NULL);
    fd = open(file, O_RDONLY);
    if (fd < 0)
        return(ft_printf("%s Error : Error de lectura."), NULL);
    while((read_cont = read(fd, buffer, sizeof(buffer))) > 0)
        file_size += read_cont;
    if (read_cont == -1) 
        return (close(fd), ft_printf("%s Error : Error de lectura.", file), NULL);
    close(fd);  
    map_temp = malloc(file_size + 1);
    if(!map_temp)
        return(close(fd), ft_printf("%s Error : Error de lectura.", file), NULL);
    fd = open(file, O_RDONLY);
    read_cont = read(fd, map_temp, file_size);
    if (read_cont == -1)
        return(close(fd), ft_printf("%s Error : Error de lectura."), free(map_temp), NULL);
    map_temp[read_cont] = '\0';
    close(fd);
    maps =  ft_split(map_temp, '\n');
    free(map_temp);
    return(maps);
}
