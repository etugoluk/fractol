/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 19:03:42 by etugoluk          #+#    #+#             */
/*   Updated: 2018/07/30 19:03:43 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mlx_pixel_put_image(t_fractol *f, int x, int y, int color)
{
	int size;
	int bits;
	int endian;

	f->addr = (int*)mlx_get_data_addr(f->mlx_img, &bits, &size, &endian);
	if (x >= 0 && x <= 800 && y >= 0 && y <= 800)
		f->addr[y * 800 + x] = color;
}

int			key_codes(int n, t_fractol *f)
{
	if (n == 53)
	{
		mlx_destroy_window((*f).mlx, (*f).mlx_win);
		exit(0);
	}
	else if (n == 24)
		(*f).inc *= 1.1;
	else if (n == 27 && f->inc >= 0)
		(*f).inc /= 1.1;
	else if (n == 124)
		(*f).mvx -= 10;
	else if (n == 123)
		(*f).mvx += 10;
	else if (n == 125)
		(*f).mvy -= 10;
	else if (n == 126)
		(*f).mvy += 10;
	else if (n == 15)
		(*f).color = 1048576;
	else if (n == 5)
		(*f).color = 4096;
	else if (n == 11)
		(*f).color = 16;
	ft_threads(f);
	return (0);
}

int			julia_codes(int x, int y, t_fractol *f)
{
	if (x >= 0 && x < 800 && y >= 0 && y < 800)
	{
		f->coef_x = x * 2;
		f->coef_y = y * 2 - 800;
	}
	ft_threads(f);
	return (0);
}

int			mouse_codes(int n, int x, int y, t_fractol *f)
{
	x = 0;
	y = 0;
	if (n == 4 && f->inc >= 0)
		f->inc /= 1.1;
	else if (n == 5)
		f->inc *= 1.1;
	ft_threads(f);
	return (0);
}
