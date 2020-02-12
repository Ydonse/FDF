/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:06:57 by ydonse            #+#    #+#             */
/*   Updated: 2019/01/31 15:52:05 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	control_mouse(int button, int x, int y, void *map)
{
	t_map *m;

	m = (t_map *)map;
	if (button == LEFT_BTN || button == SCROLL_UP || button == SCROLL_DOWN)
		zoom(button, m);
	x = 0;
	y = 0;
	return (1);
}

int	control_keyboard(int key, void *map)
{
	t_map *m;

	m = (t_map *)map;
	if (key >= 123 && key <= 126)
		rotate(m, key);
	else if (key == 53)
		exit(1);
	else if (key == 18 || key == 83)
		change_mode(m, "plane");
	else if (key == 19 || key == 84)
		change_mode(m, "iso");
	else if (key == 20 || key == 85)
		change_mode(m, "parallelle");
	else if (key == 69 || key == 78)
		modify_depth(m, key);
	else if (key == 36)
	{
		if (m->menu_on == 0)
			display_menu(map);
		else
			hide_menu(map);
	}
	return (1);
}
