/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:45:33 by ydonse            #+#    #+#             */
/*   Updated: 2019/01/31 13:54:17 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parallelle(t_map *map, int i, int j)
{
	int previous_x;
	int	previous_y;

	while (map->grid[i])
	{
		while (map->grid[i][j])
		{
			previous_x = (map->grid[i][j]->x);
			previous_y = (map->grid[i][j]->y);
			map->grid[i][j]->x = (previous_x + map->grid[i][j]->z * map->depth);
			map->grid[i][j]->y = previous_y + map->grid[i][j]->z * map->depth;
			j++;
		}
		j = 0;
		i++;
	}
	free(map->mode);
	map->mode = ft_strdup("parallelle");
}

void	iso(t_map *map, int i, int j)
{
	int previous_x;
	int	previous_y;

	while (map->grid[i])
	{
		while (map->grid[i][j])
		{
			previous_x = (map->grid[i][j]->x);
			previous_y = (map->grid[i][j]->y);
			map->grid[i][j]->x = (previous_x - previous_y) * cos(map->iso_fx);
			map->grid[i][j]->y = (map->grid[i][j]->z * -1) +
			(previous_x + previous_y) * sin(map->iso_fy);
			j++;
		}
		j = 0;
		i++;
	}
	free(map->mode);
	map->mode = ft_strdup("iso");
}

void	plane(t_map *map, int i, int j)
{
	i = 0;
	j = 0;
	reset_grid(map, 0, 0);
	free(map->mode);
	map->mode = ft_strdup("plane");
}

void	*get_mode(t_map *map)
{
	void (*f)(t_map*, int, int);

	f = NULL;
	if (ft_strcmp(map->mode, "iso") == 0)
		f = &(iso);
	else if (ft_strcmp(map->mode, "plane") == 0)
		f = &(reset_grid);
	else if (ft_strcmp(map->mode, "parallelle") == 0)
		f = &(parallelle);
	return (f);
}
