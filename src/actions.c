/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:26:20 by ydonse            #+#    #+#             */
/*   Updated: 2019/01/31 14:50:26 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(int button, t_map *map)
{
	if (button == SCROLL_DOWN && map->max_x < WIN_X * 2 &&
		map->max_y < WIN_Y * 2)
		map->space *= 1.2;
	else if ((button == LEFT_BTN || button == SCROLL_UP)
			&& map->max_x > map->size_x && map->max_y > map->size_y)
		map->space *= 0.8;
	update_image(map);
}

void	modify_depth(t_map *map, int key)
{
	if (key == 69 && map->depth < 20 && map->max_y < WIN_Y * 1.5
		&& map->max_x < WIN_X * 1.5 && map->space > 1)
		map->depth *= 1.2;
	if (key == 78 && map->depth)
		map->depth *= 0.8;
	update_image(map);
}

void	rotate(t_map *map, int key)
{
	float speed;

	speed = 0.1;
	if (key == 123)
		map->iso_fx += speed;
	if (key == 124)
		map->iso_fx -= speed;
	if (key == 126)
		map->iso_fy += speed;
	if (key == 125)
		map->iso_fy -= speed;
	update_image(map);
}

void	change_mode(t_map *map, char *str)
{
	free(map->mode);
	map->mode = ft_strdup(str);
	map->depth = 5;
	update_image(map);
}
