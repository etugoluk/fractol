/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 13:14:01 by etugoluk          #+#    #+#             */
/*   Updated: 2018/07/16 13:14:02 by etugoluk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"
# include <mlx.h>
# include <pthread.h>

typedef struct		s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct		s_fractol
{
	void			*mlx;
	void			*mlx_win;
	void			*mlx_img;
	int				*addr;
	double			inc;
	int				mvx;
	int				mvy;
	int				type;
	double			coef_x;
	double			coef_y;
	int				mouse_x;
	int				mouse_y;
	int				deep;
	int				color;
	double			y;
	double			y_max;
}					t_fractol;

int					type_fractol(t_fractol *f, char *type);
int					type2_fractol(t_fractol *f, char *type);
void				new_fractol(t_fractol *f);
void				mlx_pixel_put_image(t_fractol *f, int x, int y, int color);
int					key_codes(int n, t_fractol *f);
int					julia_codes(int x, int y, t_fractol *f);
int					mouse_codes(int n, int x, int y, t_fractol *f);
void				ft_threads(t_fractol *f);
void				mandelbort(t_fractol *f, double x);
void				julia(t_fractol *f, double x);
void				z4(t_fractol *f, double x);
void				z3(t_fractol *f, double x);
void				f_sin(t_fractol *f, double x);
void				f_cos(t_fractol *f, double x);
void				flower(t_fractol *f, double x);
void				*draw(void *v);

#endif
