/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyPress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solympe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 13:23:41 by solympe           #+#    #+#             */
/*   Updated: 2019/11/23 13:23:42 by solympe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_rules(int keycode, void *ptr)
{
	t_common *new_ptr;

	new_ptr = (t_common *)ptr;
	if (keycode == 83)
		ne_vlezlo(ptr);
	if (keycode == 84)
	{
		new_ptr->fractol.now_is = 2;
		new_ptr->fractol.move_x = -0.5;
		new_ptr->fractol.move_y = 0;
		new_ptr->fractol.zoom = 1;
	}
	if (keycode == 85)
	{
		new_ptr->fractol.now_is = 3;
		new_ptr->fractol.move_y = -0.5;
		new_ptr->fractol.move_x = -0.5;
		new_ptr->fractol.zoom = 1;
	}
}

void	go_slide(int keycode, void *ptr)
{
	t_common *new_ptr;

	new_ptr = (t_common *)ptr;
	if (keycode == 124)
		new_ptr->fractol.move_x -= 0.1 / new_ptr->fractol.zoom;
	if (keycode == 123)
		new_ptr->fractol.move_x += 0.1 / new_ptr->fractol.zoom;
	if (keycode == 126)
		new_ptr->fractol.move_y += 0.1 / new_ptr->fractol.zoom;
	if (keycode == 125)
		new_ptr->fractol.move_y -= 0.1 / new_ptr->fractol.zoom;
	if (keycode == 18)
		new_ptr->fractol.color_blue += 10;
	if (keycode == 19)
		new_ptr->fractol.color_red += 10;
	if (keycode == 20)
		new_ptr->fractol.color_green += 10;
	key_rules(keycode, new_ptr);
}

int		mouse_press(int button, int x, int y, void *ptr)
{
	t_common	*new_ptr;

	new_ptr = (t_common *)ptr;
	if (button == 5)
	{
		new_ptr->fractol.zoom *= 1.5;
		new_ptr->fractol.move_x -= ((double)x - (WW / 2)) * -0.0045 / new_ptr->
				fractol.zoom;
		new_ptr->fractol.move_y -= ((double)y - (WH / 2)) * -0.0045 / new_ptr->
				fractol.zoom;
	}
	if (button == 4)
	{
		new_ptr->fractol.zoom /= 1.5;
	}
	if (button == 1 && new_ptr->fractol.now_is == 1)
	{
		if (new_ptr->fractol.status == 0)
			new_ptr->fractol.status = 1;
		else
			new_ptr->fractol.status = 0;
	}
	mlx_clear_window(new_ptr->mlx_ptr, new_ptr->win_ptr);
	fractol(new_ptr, &(new_ptr->fractol));
	return (0);
}

int		mouse_transform(int x, int y, void *ptr)
{
	t_common	*new_ptr;

	new_ptr = (t_common *)ptr;
	if (x > 0 && x <= WW && y > 0 && y <= WH && new_ptr->fractol.status == 0)
	{
		new_ptr->fractol.curr_re = ((double)x - (WW / 2)) / (WW / 2);
		new_ptr->fractol.curr_im = ((double)y - (WH / 2)) / (WH / 2);
	}
	mlx_clear_window(new_ptr->mlx_ptr, new_ptr->win_ptr);
	fractol(new_ptr, &(new_ptr->fractol));
	return (0);
}

int		slide_to_side(int keycode, void *ptr)
{
	t_common *new_ptr;

	new_ptr = (t_common *)ptr;
	go_slide(keycode, ptr);
	if (keycode == 53)
		exit(0);
	mlx_clear_window(new_ptr->mlx_ptr, new_ptr->win_ptr);
	fractol(new_ptr, &(new_ptr->fractol));
	return (0);
}
