#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "./get_next_line/get_next_line.h"

typedef struct	s_env
{
	void		*mlx;
	void		*win;
}				t_env;

void	ft_draw(void *mlx, void *win)
{
	int		x;
	int		y;
	y = 100;

	while (y < 200)
	{
		x = 100;
		while (x < 200)
		{
			mlx_pixel_put(mlx, win, x, y, x*y);
			x++;
		}
		y++;
	}
}

int		expose_hook(t_env *e)
{
	ft_draw(e->mlx, e->win);
	return (0);
}

int		key_hook(int keycode, t_env e)
{
	printf("key = %d\n", keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env e)
{
	printf("mouse button = %d(%d,%d)\n", button, x, y);
	return (0);
}

int		main(int ac, char **av)
{
	t_env	e;
	int		fd;
	char	*line;

	line = NULL;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		get_next_line(fd, &line);
	}
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 420, 420, "42");
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
