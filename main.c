#include "cub3D.h"

t_mlx	*get_mlx()
{
	static t_mlx *mlx;
	if(!mlx)
		mlx = (t_mlx *)ft_calloc(sizeof(t_mlx), 1);
	return (mlx);
}

void    put_pixel(int x, int y, int color)
{
    char    *dst;
	t_mlx	*mlx;

	mlx = get_mlx();

    dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void	draw_map_pixel(int x, int y) {
	int i;
	int j;
	t_mlx	*mlx;

	mlx = get_mlx();
	i = 0;
	while (mlx->cnt && i < 30)
	{
		j = 0;
		while (j < 30)
		{
			if (mlx->map->matriz[y][x] == '1')
				put_pixel((x * 30) + j, (y * 30) + i,
					0x338dff);
			else if (ft_strchr("NSEW0", mlx->map->matriz[y][x]))
				put_pixel((x * 30) + j, (y * 30) + i,
				0xFFFFFF);			
			j++;
		}
		i++;
	}
	
}
void	draw_player()
{
	int i;
	int j;
	t_mlx	*mlx;

	mlx = get_mlx();
	i = 0;
	while (mlx->cnt && i < 30)
	{
		j = 0;
		while (j < 30)
		{
			put_pixel((mlx->map->px * 30) + j, (mlx->map->py * 30) + i,
				0xff5233);			
			j++;
		}
		i++;
	}
}

int	draw_map()
{
	int i;
	int	j;
	t_mlx	*mlx;

	mlx = get_mlx();
	i = 0;
	j = 0;
	while (mlx->map->matriz[i])
	{
		j = 0;
		while (mlx->map->matriz[i][j])
		{
			if(mlx->map->px == j && mlx->map->py == i)
				draw_player();
			else
				draw_map_pixel(j, i);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->cnt, mlx->wnd, mlx->img, 0, 0);
	return (EXIT_SUCCESS);
}
int count_line (char *filename) 
{
	int	i;
	char	*line;

	int fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	
	i = 0;
	line = NULL;
	while (1) {
		line = get_next_line(fd);
		if (!line || !*line)
			break;
		free(line);
		i++;
	}
	free(line);
	return(i);
}
void	findp(t_map *map, int y)
{
	int i  = 0;
	int	len = ft_strlen(map->matriz[y]);
	while (i < len)
	{
		if(ft_strchr("NSEW", map->matriz[y][i]))
		{
			map->px = i;
			map->py = y;
			return ;
		}
		i++;
	}
}
t_map	*get_map(char *filename)
{
	char *line;
	t_map *map;

	int	i;
	int	fd;
	int	maxc;

	fd = -1;
	map = ft_calloc(sizeof(t_map),  1);
	map->maxl = count_line(filename);
	map->matriz = ft_calloc(sizeof(char *), map->maxl + 1);
	fd = open(filename, O_RDONLY);
	if (!map)
		return (NULL);
	line = NULL;
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if(!line || !*line)
			break;
		map->matriz[i] = ft_strdup(line);
		maxc = ft_strlen(map->matriz[i]);
		findp(map, i);
		if (maxc > map->maxc)
			map->maxc = maxc;
		free(line);
		i++;
	}
	close(fd);
	return (map);
}

void	close_app()
{
	t_mlx *mlx = get_mlx();
	mlx_destroy_window(mlx->cnt, mlx->wnd);
	mlx_destroy_image(mlx->cnt, mlx->img);
	mlx_destroy_display(mlx->cnt);
	free(mlx->cnt);
	free(mlx);
}

void	m_up()
{
	t_mlx *mlx = get_mlx();
	char p = mlx->map->matriz[mlx->map->py - 1][mlx->map->px];
	if (mlx->map->py - 1 >= 0 && ft_strchr("NSWE0", p))
		mlx->map->py--;
}
void	m_down()
{
	t_mlx *_mlx = get_mlx();
	char p = _mlx->map->matriz[_mlx->map->py + 1][_mlx->map->px];
	if (_mlx->map->py + 1 <= _mlx->map->maxl && ft_strchr("NSWE0", p))
	_mlx->map->py++;
}
void	m_left()
{
	t_mlx *mlx = get_mlx();
	char p = mlx->map->matriz[mlx->map->py][mlx->map->px - 1];
	if (mlx->map->px - 1 >= 0 && ft_strchr("NSWE0", p))
		mlx->map->px--;
}
void	m_right()
{
	t_mlx *mlx = get_mlx();
	char p = mlx->map->matriz[mlx->map->py][mlx->map->px + 1];
	if (mlx->map->px + 1 <= mlx->map->maxc && ft_strchr("NSWE0", p))
		mlx->map->px++;
}
int key_press_event(int key)
{
	if (key == 65307)
		close_app();
	else if (key == 119)
		m_up();
	else if (key == 115)
		m_down();
	else if (key == 97)
		m_left();
	else if (key == 100)
		m_right();
	return (EXIT_SUCCESS);
}

int main(int argc, char **argv) {
	
	if (argc != 2)
		return (EXIT_FAILURE);

	t_mlx *mlx = get_mlx();
    mlx->cnt = mlx_init();
	if (!mlx->cnt)
		ft_printf("failed mlx init");
	mlx->map = get_map(argv[1]);
	mlx->width = mlx->map->maxc * 30;
	mlx->height = mlx->map->maxl * 30;
	ft_printf("Width: %d, Height: %d\n", mlx->width, mlx->height);
	mlx->wnd = mlx_new_window(mlx->cnt, mlx->width, mlx->height, "MAP");
	if (!mlx->wnd)
        ft_printf("failed new window ");
	mlx->img = mlx_new_image(mlx->cnt,  mlx->map->maxc * 30, mlx->map->maxl * 30);
	if (!mlx->img)
        ft_printf("failed new image window ");
	mlx->addr = mlx_get_data_addr(mlx->img,
			&mlx->bits_per_pixel, &mlx->line_length,
			&mlx->endian);
	
	 
	mlx_loop_hook(mlx->cnt, &draw_map, NULL);
	mlx_hook(mlx->wnd, 2, 1L << 0, key_press_event, NULL);
	mlx_loop(mlx->cnt);

}