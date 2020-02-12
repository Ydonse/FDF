/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 12:07:35 by ydonse            #+#    #+#             */
/*   Updated: 2019/01/31 16:46:05 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	update_image(t_map *map)
{
	int		i;
	int		j;
	void	(*f)(t_map*, int, int);

	i = 0;
	j = 0;
	f = get_mode(map);
	destroy_image(map);
	reset_grid(map, 0, 0);
	(*f)(map, 0, 0);
	centre_position(map);
	create_image(map);
	while (map->grid[i])
	{
		while (map->grid[i][j])
			get_line(map, i, j++, map->my_image_str);
		j = 0;
		i++;
	}
	mlx_put_image_to_window(map, map->win_p, map->image_ptr,
			WIN_X / 2 - (map->max_x / 2), WIN_Y / 2 - (map->max_y / 2));
	if (map->menu_on)
		display_menu(map);
}

void	destroy_image(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	map->destroy = 1;
	while (map->grid[i])
	{
		while (map->grid[i][j])
			get_line(map, i, j++, map->my_image_str);
		j = 0;
		i++;
	}
	mlx_put_image_to_window(map, map->win_p, map->image_ptr,
			WIN_X / 2 - (map->max_x / 2), WIN_Y / 2 - (map->max_y / 2));
	mlx_destroy_image(map->mlx_p, map->image_ptr);
	map->destroy = 0;
}

void	create_image(t_map *map)
{
	int bpp;
	int s_l;
	int endian;

	map->image_ptr = mlx_new_image(map->mlx_p,
			(map->max_x + 5), (map->max_y + 5));
	map->my_image_str = mlx_get_data_addr(map->image_ptr, &(bpp),
			&(s_l), &(endian));
	mlx_put_image_to_window(map, map->win_p, map->image_ptr,
			WIN_X / 2 - (map->max_x / 2), WIN_Y / 2 - (map->max_y / 2));
}
