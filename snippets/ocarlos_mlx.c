/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocarlos_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:15:19 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/08 20:57:27 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// AUTHOR: ocarlos- | Osni

// clang -I ../includes ocarlos_mlx.c -lm -lbsd -lmlx -lXext -lX11 && ./a.out
// gcc -I ../includes ocarlos_mlx.c -lm -lbsd -lmlx -lXext -lX11 && ./a.out

#include <mlx.h>
#include <stdlib.h>

#define W_SCR 1024
#define H_SCR 768

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

typedef struct s_game
{
	void *mlx;
	void *mlx_win;
	t_data image;
	int x;
	int y;
} t_game;

int ft_close(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
}

void pixel_junor(t_game *game, int x, int y, int color)
{
	char *dst;

	dst = game->image.addr + ((y * game->image.line_length) + (x * (game->image.bits_per_pixel / 8)));
	*(unsigned int *)dst = color;
}

int main(void)
{
	t_game game;

	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, W_SCR, H_SCR, "joguinho");
	game.image.img = mlx_new_image(game.mlx, W_SCR, H_SCR);
	game.image.addr = mlx_get_data_addr(game.image.img,
										&game.image.bits_per_pixel,
										&game.image.line_length,
										&game.image.endian);
	game.y = 0;
	while (game.y <= H_SCR)
	{
		game.x = 0;
		while (game.x <= W_SCR)
		{
			// mlx_pixel_put(game.mlx, game.mlx_win, game.x, game.y, 0x00006600); // TRGB
			pixel_junor(&game, game.x, game.y, 0x00006600);
			game.x++;
		}
		game.y++;
	}
	mlx_put_image_to_window(game.mlx, game.mlx_win, game.image.img, 0, 0);
	mlx_hook(game.mlx_win, 17, 10001, ft_close, &game);
	mlx_loop(game.mlx);
	return (0);
}
