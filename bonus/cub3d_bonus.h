/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaspar <dgaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:12:29 by dgaspar           #+#    #+#             */
/*   Updated: 2025/05/10 10:38:36 by dgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <stdlib.h> 
# include <unistd.h> 
# include <stdio.h> 
# include <sys/time.h> 
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>
# include <limits.h>
# include <mlx.h>

# include "../libft/include/libft.h"

# define WIDTH 640
# define HEIGHT 400

# define _W 119
# define _A 97
# define _S 115
# define _D 100

# define _LEFT 65361
# define _RIGTH 65363

# define MOV_SPEED 0.006
# define ROT_SPEED 0.005
# define MINIMAP_SCALE 10

# define BUTTON_PRESS 4
# define DESTROY_NOTIFY 17
# define ESCAPE 65307
# define SHIFT 65505

# define ERR_WITH_FILE_FORMAT "Error\nInvalid file extension.\n"
# define ERR_WITH_FILE "Error\nCan´t open this file.\n"
# define ERR_EMPTY_FILE "Error\nEmpty scene.\n"
# define ERR_WITH_SKY_COLOR "Error\nInvalid ceiling color format.\n"
# define ERR_WITH_FLOOR_COLOR "Error\nInvalid floor color format.\n"
# define ERR_WITH_TEXTURE_FILE "Error\nThere´s a texture that can´t be open.\n"
# define ERR_MAP_WRONG_POS "Map wrong position\n"
# define ERR_MISSING_MAP "Error\nMissing map\n"

# define ERR_DUP_NO_TEXTURE "Error\nThere are more than one NO texture\n"
# define ERR_DUP_WE_TEXTURE "Error\nThere are more than one WE texture\n"
# define ERR_DUP_SO_TEXTURE "Error\nThere are more than one SO texture\n"
# define ERR_DUP_EA_TEXTURE "Error\nThere are more than one EA texture\n"

# define ERR_DUP_CEIL_COLOR "Error\nThere are more than one color for ceil\n"
# define ERR_DUP_FLOOR_COLOR "Error\nThere are more than one color for floors\n"

# define ERR_MAP_SYMBOL "Error\nInvalid map symbol.\n"
# define ERR_FEW_PLAYERS "Error\nThere must be at least one player.\n"
# define ERR_MANY_PLAYERS "Error\nThere must be only one player.\n"
# define ERR_MAP_WITH_BLANK_LINE "Error\nThere is some blank line at map.\n"
# define ERR_NOT_SURROUNDED_BY_WALLS "Error\nThe map is \
not surrounded by walls.\n"

typedef struct s_vec
{
	double	x;
	double	y;
}	t_vec;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_map
{
	int		fd;
	char	ply_sybl;
	char	**matriz;
	char	**copy;
	int		maxl;
	int		maxc;
	int		maxl_with_nl;
	int		px;
	int		py;
}	t_map;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_length;
	int		endian;
}	t_texture;

typedef struct s_scene
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*sky;
	char		*floor;
	char		*error;
	int			floor_color;
	int			sky_color;
	bool		dup_color;
	bool		dup_texture;
	bool		show_minimap;
	int			has_map;
	t_map		*map;
	t_texture	texture[4];
}	t_scene;

typedef struct s_ply
{
	t_vec	pos;
	t_vec	dir;
	t_vec	plane;
}	t_ply;

typedef struct s_ray
{
	double	multiplier;
	double	delta_x;
	double	delta_y;
	double	side_x;
	double	side_y;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	t_vec	dir;
}	t_ray;

typedef struct s_dda
{
	int		hit;
	int		side;
	int		draw_start;
	int		draw_end;
	int		line_height;
	double	perp_dist;
}	t_dda;

typedef struct s_mlx
{
	void	*cnt;
	void	*wnd;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	t_ray	*ray;
	t_ply	*ply;
	t_dda	*dda;
	t_scene	*scene;
	bool	keys[6];
}	t_mlx;

typedef struct s_tex
{
	int		text_num;
	int		text_x;
	int		y;
	int		text_y;
	int		color;
	double	wallx;
	double	step;
	double	text_pos;
}	t_tex;

t_mlx	*get_mlx(void);
void	put_pixel(int x, int y, int color);
void	draw_vertical_line(int x, int start, int end, int color);
void	clear_img(void);
int		set_wall_colors(int side, int step_x, int step_y);
void	init_image(t_mlx *mlx);

void	initialize(t_mlx *mlx, char *map_src);
void	draw_height(t_mlx *mlx, t_vec ray);
void	render(t_mlx *mlx);
void	move_up(t_ply *ply, t_map *map, bool key);
void	move_down(t_ply *ply, t_map *map, bool key);
void	move_left(t_ply *ply, t_map *map, t_vec perp, bool key);
void	move_right(t_ply *ply, t_map *map, t_vec perp, bool key);
int		update(t_mlx *mlx);
int		close_game(void);
void	perfom_rotate(t_mlx *mlx);
int		key_press(int kc, t_mlx *mlx);
int		key_release(int kc, t_mlx *mlx);
void	increase_line_counter(int *val, int *data, char *line);
void	get_map_loop(int fd, char *line, int *i, t_map *map);
t_map	*get_map(char *filename);
void	dup_map(char **map);
char	map_at(int x, int y);
char	move_on(double x, double y);

void	print_map(char **matriz);
void	print_scene(t_scene *scene);
void	fill_scene(char	*filename);
void	fill_data(t_mlx *mlx, char *line, int len);
void	close_if_duplicated(t_mlx *mlx, char *line);

bool	missing_texture(t_scene *scene);
bool	missing_color(t_scene *scene);
bool	missing_map(t_scene *scene);
bool	is_missing(t_scene *scene);
bool	is_invisible_line(char *line);

bool	is_texture_or_color(char *line);
bool	has_duplicated_texture(t_scene *scene, char *elem);
bool	has_duplicated_color(t_scene *scene, char *elem);
void	load_all_texts(t_mlx *mlx);
int		get_texture_color(t_texture *texture, int x, int y);
void	draw_textured_line(t_mlx *mlx, int x, t_vec *ray);

int		ft_rgb(int r, int g, int b);
int		get_longest_line(char **matriz);
char	*ft_strcspn(char *str, char c);
void	paint_sky_and_floor(t_scene *scene);
void	free_matriz(char **matriz);

void	go_top(int x, int y, int height);
void	go_down(int x, int y, int height);
void	go_left(int x, int y, int width);
void	go_right(int x, int y, int width);

bool	valid_color_range(int value, char *color);
bool	valid_color_format(char *color);
void	validate_scene(t_scene *scene, char *src);
bool	valid_file_format(char *src);
bool	valid_file_existence(char *src);
void	validate_textures(t_scene *scene);

bool	valid_file_format(char *src);
void	validate_map(t_scene *scene);
void	vertical_top_lines(int x, int y);
void	vertical_down_lines(int x, int y);
void	horizontal_left_lines(int x, int y);
void	horizontal_right_lines(int x, int y);
size_t	ft_strlen_line(char *s);

void	put_error(char *error);
void	exit_clean(void);

void	draw_minimap(t_mlx *mlx);

#endif
