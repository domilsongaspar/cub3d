#ifndef CUBE_BONUS_H
# define CUBE_BONUS_H

# include <stdlib.h> 
# include <unistd.h> 
# include <stdio.h> 
# include <string.h>
# include <sys/time.h> 
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>
# include <limits.h>
# include <mlx.h>
# include <mlx_int.h>

# include "libft/include/libft.h"



typedef struct s_map
{
	int		fd;
	char	**matriz;
	int		maxl;
	int 	maxc;
	int		px;
	int 	py;
}	t_map;

typedef struct s_mlx
{
	void	*cnt;
	void	*wnd;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	t_map	*map;
}	t_mlx;

#endif
