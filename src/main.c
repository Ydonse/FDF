/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:38:46 by ydonse            #+#    #+#             */
/*   Updated: 2019/01/31 17:46:04 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		abs(int nb)
{
	return (nb = nb < 0 ? nb * -1 : nb);
}

void	reset_grid(t_map *map, int i, int j)
{
	i = 0;
	j = 0;
	while (map->grid[i])
	{
		while (map->grid[i][j])
		{
			map->grid[i][j]->x = map->ori_x + (j * map->space);
			map->grid[i][j]->y = map->ori_y + (i * map->space);
			map->grid[i][j]->z = map->grid[i][j]->ori_z * map->depth;
			j++;
		}
		j = 0;
		i++;
	}
}

void	create_mlx(t_map *map)
{
	map->mlx_p = mlx_init();
	map->win_p = mlx_new_window(map->mlx_p, WIN_X, WIN_Y, "Fil De Fer");
}

int		init(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	map->iso_fx = 0.523599;
	map->iso_fy = 0.523599;
	centre_position(map);
	create_mlx(map);
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
	create_menu(map);
	return (1);
}

int		main(int argc, char **argv)
{
	t_map	*map;
	int		fd;

	if (argc != 2)
	{
		ft_putstr("usage : ./fdf [text_file]\n");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 1)
	{
		ft_putstr("The file cannot be opened\n");
		return (0);
	}
	if (!(map = malloc(sizeof(t_map))))
		return (0);
	if (!(fill_tab(argv, map, 0, fd)))
	{
		ft_putstr("not a valid file (figure volume might be too big)\n");
		return (0);
	}
	init(map);
	mlx_mouse_hook(map->win_p, control_mouse, (void *)(map));
	mlx_hook(map->win_p, 2, 5, control_keyboard, (void *)(map));
	mlx_loop(map->mlx_p);
	return (0);
}
