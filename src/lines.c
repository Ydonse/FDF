/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:23:47 by ydonse            #+#    #+#             */
/*   Updated: 2019/01/31 14:55:43 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	trace_vertical(t_map *m, char *my_image)
{
	int sens_x;
	int sens_y;
	int perct;

	m->e = m->y2 > m->y1 ? m->y2 - m->y1 : m->y1 - m->y2;
	sens_x = m->x2 > m->x1 ? 1 : -1;
	sens_y = m->y2 > m->y1 ? 1 : -1;
	m->dy = m->e * 2;
	m->dx = m->x2 > m->x1 ? (m->x2 - m->x1) * 2 : (m->x1 - m->x2) * 2;
	m->pixel_o = m->y1;
	while (m->y1 != m->y2)
	{
		perct = percent(m->pixel_o, m->y2, m->y1);
		if (m->z1 < m->z2)
			m->virtual_z = m->z1 + ((perct * abs(m->z2 - m->z1)) / 100);
		else
			m->virtual_z = m->z2 + (((100 - perct) * abs(m->z1 - m->z2)) / 100);
		fill_pixel(my_image, m);
		m->y1 += sens_y;
		if ((m->e -= m->dx) <= 0)
		{
			m->x1 += sens_x;
			m->e += m->dy;
		}
	}
}

void	check_j_line(t_map *m, int i, int j, char *my_image)
{
	if (j < m->size_x - 1)
	{
		m->x1 = m->grid[i][j]->x;
		m->y1 = m->grid[i][j]->y;
		m->z1 = m->grid[i][j]->z;
		m->x2 = m->grid[i][j + 1]->x;
		m->y2 = m->grid[i][j + 1]->y;
		m->z2 = m->grid[i][j + 1]->z;
		m->e = m->x2 > m->x1 ? m->x2 - m->x1 : m->x1 - m->x2;
		m->dy = m->y2 > m->y1 ? (m->y2 - m->y1) * 2 : (m->y1 - m->y2) * 2;
		m->dx = m->e * 2;
		trace_line(m, my_image);
	}
}

void	get_line(t_map *m, int i, int j, char *my_image)
{
	check_j_line(m, i, j, my_image);
	if (i < m->size_y - 1)
	{
		m->x1 = m->grid[i][j]->x;
		m->y1 = m->grid[i][j]->y;
		m->z1 = m->grid[i][j]->z;
		m->x2 = m->grid[i + 1][j]->x;
		m->y2 = m->grid[i + 1][j]->y;
		m->z2 = m->grid[i + 1][j]->z;
		m->e = m->x2 > m->x1 ? m->x2 - m->x1 : m->x1 - m->x2;
		m->dy = m->y2 > m->y1 ? (m->y2 - m->y1) * 2 : (m->y1 - m->y2) * 2;
		m->dx = m->e * 2;
		trace_line(m, my_image);
	}
}

int		trace_line(t_map *m, char *my_image)
{
	int sens_x;
	int sens_y;
	int perct;

	sens_x = m->x2 > m->x1 ? 1 : -1;
	sens_y = m->y2 > m->y1 ? 1 : -1;
	if (m->dx < m->dy)
		trace_vertical(m, my_image);
	m->pixel_o = m->x1;
	while (m->x1 != m->x2)
	{
		perct = percent(m->pixel_o, m->x2, m->x1);
		if (m->z1 < m->z2)
			m->virtual_z = m->z1 + ((perct * abs(m->z2 - m->z1)) / 100);
		else
			m->virtual_z = m->z2 + (((100 - perct) * abs(m->z2 - m->z1)) / 100);
		fill_pixel(my_image, m);
		m->x1 += sens_x;
		if ((m->e -= m->dy) <= 0)
		{
			m->y1 += sens_y;
			m->e += m->dx;
		}
	}
	return (0);
}

void	fill_pixel(char *my_image_string, t_map *map)
{
	int coo;

	map->current_c = get_color_stage(map->virtual_z, map->current_c);
	if (map->destroy)
		map->current_c = modify_color(map->current_c, "black");
	coo = (4 * map->x1) + (4 * (map->max_x + 5) * map->y1);
	my_image_string[coo] = map->current_c.r;
	my_image_string[coo + 1] = map->current_c.g;
	my_image_string[coo + 2] = map->current_c.b;
}
