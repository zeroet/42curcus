/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 13:46:04 by seyun             #+#    #+#             */
/*   Updated: 2021/03/09 14:01:15 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"

typedef struct s_data
{
	void *mlx;
	void *win;
	void *img;
	char *addr;
	int	bits_per_pixel;
	int line_length;
	int endian;
}		t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int draw(t_data *data)
{
	int i;
	int j;

	j = 1;
	i = 1;
	while (i < 100)
	{
		my_mlx_pixel_put(data, i + j, i + j, 0x00FFFF00);
		i++;
		j++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int main(void)
{
	t_data data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 800, 600, "hello");
	data.img = mlx_new_image(data.mlx, 800, 600);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	my_mlx_pixel_put(&data,5,5,0x00FFFF00);
	mlx_loop_hook(data.mlx, draw, &data);
	mlx_loop(data.mlx);
}
