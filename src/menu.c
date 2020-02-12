/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:02:45 by ydonse            #+#    #+#             */
/*   Updated: 2019/01/31 14:44:50 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_menu(t_map *map)
{
	int bpp;
	int s_l;
	int endian;

	map->menu_ptr = mlx_new_image(map->mlx_p, 400, 300);
	map->menu_str = (unsigned char*)
		mlx_get_data_addr(map->menu_ptr, &(bpp), &(s_l), &(endian));
	map->menu_on = 1;
	map->menu_on = 1;
	display_menu(map);
}

void	display_menu(t_map *map)
{
	int i;

	i = 0;
	while (i < 400 * 300 * 4)
	{
		map->menu_str[i] = 255;
		map->menu_str[i + 1] = 255;
		map->menu_str[i + 2] = 255;
		i += 4;
	}
	mlx_put_image_to_window(map->mlx_p, map->win_p, map->menu_ptr, 50, 50);
	write_menu(map);
	map->menu_on = 1;
}

void	hide_menu(t_map *map)
{
	int i;

	i = 0;
	while (i < 400 * 300 * 4)
	{
		map->menu_str[i] = 0;
		map->menu_str[i + 1] = 0;
		map->menu_str[i + 2] = 0;
		i += 4;
	}
	mlx_put_image_to_window(map->mlx_p, map->win_p, map->menu_ptr, 50, 50);
	map->menu_on = 0;
	update_image(map);
}

void	write_menu(t_map *map)
{
	int value;

	value = 60;
	mlx_string_put(map->mlx_p, map->win_p, 100, value, 0,
		"Change mode       : 1 2 3");
	mlx_string_put(map->mlx_p, map->win_p, 100, value + 50, 0,
		"Zoom              : Mouse wheel");
	mlx_string_put(map->mlx_p, map->win_p, 100, value + 100, 0,
		"Rotate            : arrows");
	mlx_string_put(map->mlx_p, map->win_p, 100, value + 150, 0,
		"Increase depth    : + -");
	mlx_string_put(map->mlx_p, map->win_p, 100, value + 200, 0,
		"Hide/display menu : return");
	mlx_string_put(map->mlx_p, map->win_p, 100, value + 250, 0,
		"Quit              : echap");
}
