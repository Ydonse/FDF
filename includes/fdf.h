/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:49:47 by ydonse            #+#    #+#             */
/*   Updated: 2019/01/31 19:13:33 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include "libft.h"
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <math.h>
# define WIN_X 1500
# define WIN_Y 1000
# define LEFT_BTN 1
# define RIGHT_BTN 2
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct		s_color
{
	int r;
	int g;
	int b;
	int alpha;
}					t_color;

typedef struct		s_point
{
	int x;
	int y;
	int z;
	int ori_z;
}					t_point;

typedef struct		s_map
{
	int				size_x;
	int				size_y;
	float			depth;
	t_point			***grid;
	void			*mlx_p;
	void			*win_p;
	int				ori_x;
	int				ori_y;
	int				dx;
	int				dy;
	int				e;
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				z1;
	int				z2;
	int				little_x;
	int				little_y;
	int				great_x;
	int				great_y;
	int				virtual_z;
	int				min_z;
	int				pixel_o;
	float			space;
	int				max_x;
	int				max_y;
	int				max_z;
	float			iso_fx;
	float			iso_fy;
	t_color			current_c;
	char			*mode;
	void			*image_ptr;
	void			*my_image_str;
	void			*menu_ptr;
	unsigned char	*menu_str;
	int				menu_on;
	short			destroy;
}					t_map;

int					fill_tab(char **argv, t_map *map, int i, int fd);
int					init(t_map *map);
int					convert_tab(char **tab, t_map *map, int i, int j);
int					fill_grid(char **tab, t_map *map, int i, int j);
int					trace_line(t_map *m, char *my_image);
int					control_mouse(int button, int x, int y, void *map);
int					control_keyboard(int key, void *map);
void				zoom(int button, t_map *map);
void				create_mlx(t_map *map);
void				create_image(t_map *map);
void				fill_pixel(char *my_image_string, t_map *map);
void				trace_vertical(t_map *m, char *my_image);
void				get_line (t_map *m, int i, int j, char *my_image);
void				check_j_line(t_map *m, int i, int j, char *my_image);
int					trace_line(t_map *m, char *my_image);
void				iso(t_map *map, int i, int j);
void				parallelle(t_map *map, int i, int j);
void				plane(t_map *map, int i, int j);
void				reset_grid(t_map *map, int i, int j);
void				centre_position(t_map *map);
int					get_y_center(t_map *map, int i, int j);
int					get_x_center(t_map *map, int i, int j);
void				move_to_centre(t_map *map, int little_x, int little_y);
t_color				modify_color(t_color color, char *str);
void				destroy_image(t_map *map);
void				rotate(t_map *map, int key);
void				update_image(t_map *map);
void				*get_mode(t_map *map);
void				change_mode(t_map *map, char *str);
void				modify_depth(t_map *map, int key);
int					percent (int start, int end, int current);
t_color				get_color_stage(int z, t_color color);
t_color				get_color (t_map *m, t_color color);
int					check_nb (char *tab);
int					check_lines_size(t_map *map);
void				create_menu(t_map *map);
void				display_menu(t_map *map);
void				hide_menu(t_map *map);
void				write_menu(t_map *map);
#endif
