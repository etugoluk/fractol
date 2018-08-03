/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 19:03:52 by etugoluk          #+#    #+#             */
/*   Updated: 2018/07/30 19:03:53 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			mandelbort(t_fractol *f, double x)
{
	double		tmp;
	t_complex	z;
	t_complex	c;

	f->deep = 0;
	z.re = (x - f->mvx - 400) / 200 / f->inc;
	z.im = (f->y - f->mvy - 400) / (-200) / f->inc;
	c.re = z.re;
	c.im = z.im;
	while (f->deep < 256 && fabs(z.re * z.re + z.im * z.im) < 16)
	{
		tmp = z.re;
		z.re = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * tmp * z.im + c.im;
		f->deep++;
	}
}

void			julia(t_fractol *f, double x)
{
	double		tmp;
	t_complex	z;

	f->deep = 0;
	z.re = (x - f->mvx - 400) / 200 / f->inc;
	z.im = (f->y - f->mvy - 400) / (-200) / f->inc;
	while (f->deep < 256 && fabs(z.re * z.re + z.im * z.im) < 16)
	{
		tmp = z.re;
		z.re = z.re * z.re - z.im * z.im - 0.8 + f->coef_x / 800;
		z.im = 2 * tmp * z.im + f->coef_y / 800;
		f->deep++;
	}
}

void			z4(t_fractol *f, double x)
{
	double		tmp;
	t_complex	z;

	f->deep = 0;
	z.re = (x - f->mvx - 400) / 200 / f->inc;
	z.im = (f->y - f->mvy - 400) / (-200) / f->inc;
	while (f->deep < 256 && fabs(z.re * z.re + z.im * z.im) < 16)
	{
		tmp = z.re;
		z.re = pow(z.re, 4) - 6 * pow(z.re, 2) * pow(z.im, 2) + pow(z.im, 4) + 0.6;
		z.im = 4 * pow(tmp, 3) * z.im - 4 * tmp * pow(z.im, 3) + 0.55;
		f->deep++;
	}
}

void			newton(t_fractol *f, double x)
{
	double		tmp;
	t_complex	z;

	f->deep = 0;
	z.re = (x - f->mvx - 400) / 200 / f->inc;
	z.im = (f->y - f->mvy - 400) / (-200) / f->inc;
	while (f->deep < 256 && fabs(z.re * z.re + z.im * z.im) < 16)
	{
		tmp = z.re;
		z.re = pow(z.re, 3) - 3 * z.re * z.im * z.im - 1;
		z.im = 3 * tmp * tmp * z.im - pow(z.im, 3);
		f->deep++;
	}
}

void			*draw(void *v)
{
	double		x;
	double		tmp_y;
	t_fractol	*f;
	void		(*ptr_func)(t_fractol *f, double x);

	x = 0;
	f = (t_fractol*)v;
	tmp_y = f->y;
	if (f->type == 0)
		ptr_func = mandelbort;
	else if (f->type == 1)
		ptr_func = julia;
	else if (f->type == 2)
		ptr_func = z4;
	else if (f->type == 3)
		ptr_func = newton;
	while (x < 800)
	{
		f->y = tmp_y;
		while (f->y < f->y_max)
		{
			ptr_func(f, x);
			mlx_pixel_put_image(f, x, f->y, f->deep * f->color);
			f->y++;
		}
		x++;
	}
	return (NULL);
}
