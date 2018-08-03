/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_fractols.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 14:44:13 by etugoluk          #+#    #+#             */
/*   Updated: 2018/08/03 14:44:14 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			z4(t_fractol *f, double x)
{
	double		tmp;
	t_complex	z;
	t_complex	c;

	f->deep = 0;
	z.re = (x + f->mvx - 400) / 200 / f->inc;
	z.im = (f->y + f->mvy - 400) / (-200) / f->inc;
	c.re = z.re;
	c.im = z.im;
	while (f->deep < 256 && fabs(z.re * z.re + z.im * z.im) < 16)
	{
		tmp = z.re;
		z.re = pow(z.re, 4) - 6 * pow(z.re, 2) *
		pow(z.im, 2) + pow(z.im, 4) + c.re;
		z.im = 4 * pow(tmp, 3) * z.im - 4 * tmp * pow(z.im, 3) + c.im;
		f->deep++;
	}
}

void			z3(t_fractol *f, double x)
{
	double		tmp;
	t_complex	z;
	t_complex	c;

	f->deep = 0;
	z.re = (x + f->mvx - 400) / 200 / f->inc;
	z.im = (f->y + f->mvy - 400) / (-200) / f->inc;
	c.re = z.re;
	c.im = z.im;
	while (f->deep < 256 && fabs(z.re * z.re + z.im * z.im) < 4)
	{
		tmp = z.re;
		z.re = pow(z.re, 3) - 3 * z.re * z.im * z.im + c.re;
		z.im = 3 * tmp * tmp * z.im - pow(z.im, 3) + c.im;
		f->deep++;
	}
}

void			f_sin(t_fractol *f, double x)
{
	double		tmp;
	t_complex	z;

	f->deep = 0;
	z.re = (x + f->mvx - 400) / 200 / f->inc;
	z.im = (f->y + f->mvy - 400) / (-200) / f->inc;
	while (f->deep < 50 && fabs(z.re * z.re + z.im * z.im) < 40)
	{
		tmp = z.re;
		z.re = sin(z.re) * cosh(z.im) * 1.5;
		z.im = cos(tmp) * sinh(z.im) * 1.5;
		f->deep++;
	}
}

void			f_cos(t_fractol *f, double x)
{
	double		tmp;
	t_complex	z;

	f->deep = 0;
	z.re = (x + f->mvx - 400) / 200 / f->inc;
	z.im = (f->y + f->mvy - 400) / (-200) / f->inc;
	while (f->deep < 50 && fabs(z.re * z.re + z.im * z.im) < 40)
	{
		tmp = z.re;
		z.re = cos(z.re) * cosh(z.im) * 1.5;
		z.im = sin(tmp) * sinh(z.im) * (-1.5);
		f->deep++;
	}
}

void			flower(t_fractol *f, double x)
{
	double		tmp;
	t_complex	z;

	f->deep = 0;
	z.re = (x + f->mvx - 400) / 200 / f->inc;
	z.im = (f->y + f->mvy - 400) / (-200) / f->inc;
	while (f->deep < 256 && fabs(z.re * z.re + z.im * z.im) < 2)
	{
		tmp = z.re;
		z.re = pow(z.re, 4) - 6 * pow(z.re, 2) *
		pow(z.im, 2) + pow(z.im, 4) + 0.6;
		z.im = 4 * pow(tmp, 3) * z.im - 4 * tmp * pow(z.im, 3) + 0.55;
		f->deep++;
	}
}
