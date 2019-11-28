/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solympe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:44:46 by solympe           #+#    #+#             */
/*   Updated: 2019/11/22 15:49:40 by solympe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>

# define WW 750
# define WH 500

typedef struct	s_fractol
{
	int			max_iter;
	int			x;
	int			y;
	int			index;
	int			figure;
	int			color;
	int			color_red;
	int			color_green;
	int			color_blue;
	double		curr_re;
	double		curr_im;
	double		new_re;
	double		new_im;
	double		old_re;
	double		old_im;
	double		zoom;
	double		move_x;
	double		move_y;
	int			max_iterations;
	int			status;
	int			now_is;
}				t_fractol;

typedef struct	s_common
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*image;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	t_fractol	fractol;
}				t_common;

void			fractol(t_common *ptr, t_fractol *fractol);
void			fractol_init(t_fractol *fractol);
void			initial_rules(t_fractol *fractol);
void			kostil(t_fractol *fractol);
void			ne_vlezlo(void *ptr);
void			key_rules(int keycode, void *ptr);
void			go_slide(int keycode, void *ptr);
void			ferror ();
int				close_panel(void);

int				check_input(int ac, char **av);
int				slide_to_side (int keycode, void *common);
int				mouse_press(int button, int x, int y, void *ptr);
int				mouse_transform(int x, int y, void *ptr);

#endif
