/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centre.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:29:28 by ydonse            #+#    #+#             */
/*   Updated: 2019/01/31 17:01:50 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_to_centre(t_map *map, int little_x, int little_y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < map->size_y)
	{
		while (j < map->size_x)
		{
			if (little_x < 0)
				map->grid[i][j]->x += abs(little_x);
			if (little_y < 0)
				map->grid[i][j]->y += abs(little_y);
			j++;
		}
		j = 0;
		i++;
	}
}

int		get_x_center(t_map *map, int i, int j)
{
	int little_x;
	int great_x;

	little_x = 0;
	great_x = 0;
	while (i < map->size_y)
	{
		while (j < map->size_x)
		{
			if (map->grid[i][j]->x < little_x)
				little_x = map->grid[i][j]->x;
			if (map->grid[i][j]->x > great_x)
				great_x = map->grid[i][j]->x;
			j++;
		}
		j = 0;
		i++;
	}
	map->max_x = (great_x - little_x);
	return (little_x);
}

int		get_y_center(t_map *map, int i, int j)
{
	int little_y;
	int great_y;

	little_y = 0;
	great_y = 0;
	while (i < map->size_y)
	{
		while (j < map->size_x)
		{
			if (map->grid[i][j]->y < little_y)
				little_y = map->grid[i][j]->y;
			if (map->grid[i][j]->y > great_y)
				great_y = map->grid[i][j]->y;
			j++;
		}
		j = 0;
		i++;
	}
	map->max_y = (great_y - little_y);
	return (little_y);
}

void	centre_position(t_map *map)
{
	int little_x;
	int little_y;

	little_x = get_x_center(map, 0, 0);
	little_y = get_y_center(map, 0, 0);
	move_to_centre(map, little_x, little_y);
}
