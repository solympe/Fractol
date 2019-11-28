/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solympe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:50:05 by solympe           #+#    #+#             */
/*   Updated: 2019/11/22 15:50:06 by solympe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol(t_common *ptr, t_fractol *fractol)
{
	fractol->y = 0;
	while (fractol->y < WH)
	{
		fractol->x = 0;
		while (fractol->x < WW)
		{
			initial_rules(fractol);
			kostil(fractol);
			if (fractol->figure == fractol->max_iterations)
				fractol->color = mlx_get_color_value(ptr->mlx_ptr, 0x000000);
			else
				fractol->color = ((((fractol->color_red + fractol->figure)
				% 256) << 16) | (((fractol->color_green + fractol->figure)
				% 256) << 8) | ((fractol->color_blue + fractol->figure) % 256));
			fractol->index = fractol->x * (ptr->bits_per_pixel) / 8 + fractol->y
					* (ptr->size_line);
			ptr->image[fractol->index] = fractol->color & 0xFF;
			ptr->image[fractol->index + 1] = (fractol->color & 0xFF00) >> 8;
			ptr->image[fractol->index + 2] = (fractol->color & 0xFF0000) >> 16;
			fractol->x++;
		}
		fractol->y++;
	}
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
}

int		check_input(int ac, char **av)
{
	if (ac != 2)
		ferror();
	if (av[1][0] == 'j' && av[1][1] == '\0')
		return (1);
	else if (av[1][0] == 'm' && av[1][1] == '\0')
		return (2);
	else if (av[1][0] == 'b' && av[1][1] == '\0')
		return (3);
	else
		ferror();
	return (0);
}

void	ferror(void)
{
	write(1, "********************\nError! Use this keys for calling your"
"fractal:\nj - julia fractal\nm - mandelbrot fractal\nb - burning"
"ship fractal\n********************\n", 153);
	exit(0);
}

int		main(int ac, char **av)
{
	t_common	ptr;
	int			saver_input;

	saver_input = check_input(ac, av);
	ptr.fractol.now_is = saver_input;
	ptr.mlx_ptr = mlx_init();
	ptr.win_ptr = mlx_new_window(ptr.mlx_ptr, WW, WH, "Apocalypse");
	ptr.img_ptr = mlx_new_image(ptr.mlx_ptr, WW, WH);
	ptr.image = mlx_get_data_addr(ptr.img_ptr, &(ptr.bits_per_pixel),
			&(ptr.size_line), &ptr.endian);
	fractol_init(&(ptr.fractol));
	fractol(&ptr, &(ptr.fractol));
	mlx_hook(ptr.win_ptr, 2, 2, &slide_to_side, (void *)&ptr);
	mlx_hook(ptr.win_ptr, 4, 4, &mouse_press, (void *)&ptr);
	mlx_hook(ptr.win_ptr, 6, 6, &mouse_transform, (void *)&ptr);
	mlx_hook(ptr.win_ptr, 17, 17, &close_panel, (void *)&ptr);
	fractol(&ptr, &(ptr.fractol));
	mlx_loop(ptr.mlx_ptr);
}
