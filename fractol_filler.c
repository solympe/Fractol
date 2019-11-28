/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_filler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solympe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:48:16 by solympe           #+#    #+#             */
/*   Updated: 2019/11/27 16:48:26 by solympe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_init(t_fractol *fractol)
{
	fractol->max_iterations = 256;
	fractol->figure = 0;
	fractol->zoom = 1;
	fractol->move_x = 0;
	fractol->move_y = 0;
	fractol->curr_re = -0.7;
	fractol->curr_im = 0.27015;
	fractol->x = 0;
	fractol->y = 0;
	fractol->figure = 0;
	fractol->color_blue = 10;
	fractol->color_green = 10;
	fractol->color_red = 10;
	fractol->status = 1;
	if (fractol->now_is == 2 || fractol->now_is == 3)
		fractol->move_x = -0.5;
	if (fractol->now_is == 3)
		fractol->move_y = -0.5;
}

void	initial_rules(t_fractol *fractol)
{
	if (fractol->now_is == 1)
	{
		fractol->new_re = 1.5 * (fractol->x - WW / 2) / (0.5 * fractol->zoom *
				WW) + fractol->move_x;
		fractol->new_im = (fractol->y - WH / 2) / (0.5 * fractol->zoom * WH) +
				fractol->move_y;
	}
	if (fractol->now_is == 2 || fractol->now_is == 3)
	{
		fractol->curr_re = 1.5 * (fractol->x - WW / 2) / (0.5 * fractol->zoom *
				WW) + fractol->move_x;
		fractol->curr_im = (fractol->y - WH / 2) / (0.5 * fractol->zoom * WH) +
				fractol->move_y;
		fractol->new_re = 0;
		fractol->new_im = 0;
		fractol->old_re = 0;
		fractol->old_im = 0;
	}
	fractol->figure = 0;
}

void	kostil(t_fractol *fractol)
{
	while (fractol->figure < fractol->max_iterations)
	{
		fractol->old_re = fractol->new_re;
		fractol->old_im = fractol->new_im;
		fractol->new_re = fractol->old_re * fractol->old_re - fractol->old_im *
				fractol->old_im + fractol->curr_re;
		fractol->new_im = 2 * fractol->old_re * fractol->old_im + fractol->
				curr_im;
		if (fractol->now_is == 3)
		{
			fractol->new_re = fractol->old_re * fractol->old_re - fractol->
					old_im * fractol->old_im + fractol->curr_re;
			fractol->new_im = 2 * fabs(fractol->old_re * fractol->old_im) +
					fractol->curr_im;
		}
		if ((fractol->new_re * fractol->new_re + fractol->new_im * fractol->
		new_im) > 4)
			break ;
		fractol->figure++;
	}
}

void	ne_vlezlo(void *ptr)
{
	t_common *new_ptr;

	new_ptr = (t_common *)ptr;
	new_ptr->fractol.
	status = 1;
	new_ptr->fractol.
	now_is = 1;
	new_ptr->fractol.
	curr_re = -0.7;
	new_ptr->fractol.
	curr_im = 0.27015;
	new_ptr->fractol.
	move_x = 0;
	new_ptr->fractol.
	move_y = 0;
	new_ptr->fractol.
	zoom = 1;
}

int		close_panel(void)
{
	exit(0);
}
