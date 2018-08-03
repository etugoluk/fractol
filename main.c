/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 19:03:31 by etugoluk          #+#    #+#             */
/*   Updated: 2018/07/30 19:03:32 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				type2_fractol(t_fractol *f, char *type)
{
	if (!ft_strcmp(type, "Flower"))
	{
		f->type = 4;
		f->color = 16;
	}
	else if (!ft_strcmp(type, "sin"))
	{
		f->type = 5;
		f->color = 16;
	}
	else if (!ft_strcmp(type, "cos"))
	{
		f->type = 6;
		f->color = 4096;
	}
	else
		return (0);
	return (1);
}

int				type_fractol(t_fractol *f, char *type)
{
	if (!ft_strcmp(type, "Mandelbrot"))
	{
		f->type = 0;
		f->color = 1048576;
	}
	else if (!ft_strcmp(type, "Julia"))
	{
		f->type = 1;
		f->color = 4096;
	}
	else if (!ft_strcmp(type, "z4"))
	{
		f->type = 2;
		f->color = 16;
	}
	else if (!ft_strcmp(type, "z3"))
	{
		f->type = 3;
		f->color = 1048576;
	}
	else
		return (type2_fractol(f, type));
	return (1);
}

void			new_fractol(t_fractol *f)
{
	f->mlx = mlx_init();
	f->mlx_win = mlx_new_window(f->mlx, 800, 800, "fractol");
	f->mlx_img = mlx_new_image(f->mlx, 800, 800);
	f->inc = 1;
	f->mvx = 0;
	f->mvy = 0;
	f->y = 0;
	f->y_max = 800;
	f->coef_x = 0;
	f->coef_y = 0;
	f->mouse_x = 400;
	f->mouse_y = 400;
	f->deep = 0;
}

void			ft_threads(t_fractol *f)
{
	t_fractol	tab[8];
	pthread_t	t[8];
	int			i;

	i = 0;
	while (i < 8)
	{
		ft_memcpy((void*)&tab[i], (void*)f, sizeof(t_fractol));
		tab[i].y = 100 * i;
		tab[i].y_max = 100 * (i + 1);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		pthread_create(&t[i], NULL, draw, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(f->mlx, f->mlx_win, f->mlx_img, 0, 0);
}

int				main(int argc, char **argv)
{
	t_fractol	f;

	if (argc != 2 || !type_fractol(&f, argv[1]))
	{
		ft_putstr("Usage: ./fractol [Mandelbrot]|[Julia]|[z3]|");
		ft_putendl("[z4]|[Flower]|[sin]|[cos]");
		return (0);
	}
	new_fractol(&f);
	mlx_hook(f.mlx_win, 2, 1L << 0, key_codes, &f);
	if (f.type == 1)
		mlx_hook(f.mlx_win, 6, 1L < 6, julia_codes, &f);
	mlx_mouse_hook(f.mlx_win, mouse_codes, &f);
	ft_threads(&f);
	mlx_loop(f.mlx);
	return (0);
}
