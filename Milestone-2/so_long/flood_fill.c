/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacuccu <vacuccu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:24:53 by vacuccu           #+#    #+#             */
/*   Updated: 2025/07/15 17:24:58 by vacuccu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'F' ||
	map[y][x] == 'E' || map[y][x] == '\n')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

int	check_path_valid(t_map *map)
{
	int	y;
	int	x;

	flood_fill(map->map_copy, map->player_x, map->player_y);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (map->map_copy[y][x] && map->map_copy[y][x] != '\n')
		{
			if (map->map_copy[y][x] == 'C' || map->map_copy[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
