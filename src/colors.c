/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:05:34 by ydonse            #+#    #+#             */
/*   Updated: 2019/01/31 19:19:58 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color		modify_color(t_color color, char *str)
{
	if (ft_strcmp(str, "green") == 0)
	{
		color.r = 0;
		color.g = 255;
		color.b = 0;
	}
	else if (ft_strcmp(str, "black") == 0)
	{
		color.r = 0;
		color.g = 0;
		color.b = 0;
	}
	else if (ft_strcmp(str, "brown") == 0)
	{
		color.r = 0;
		color.g = 50;
		color.b = 200;
	}
	else if (ft_strcmp(str, "white") == 0)
	{
		color.r = 255;
		color.g = 255;
		color.b = 255;
	}
	return (color);
}

int			percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	distance = distance < 0 ? distance * -1 : distance;
	placement = placement < 0 ? placement * -1 : placement;
	return (distance == 0 ? 100 : (placement / distance) * 100);
}

int			get_light(int start, int end, double percentage)
{
	return (start + ((percentage * end) / 100));
}

t_color		get_color_stage(int z, t_color color)
{
	if (z < 10)
		color = modify_color(color, "green");
	if (z >= 10 && z < 200)
		color = modify_color(color, "brown");
	if (z >= 200)
		color = modify_color(color, "white");
	return (color);
}
