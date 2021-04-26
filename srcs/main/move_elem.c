/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:07:35 by oavelar           #+#    #+#             */
/*   Updated: 2021/04/10 14:47:38 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	move_y_pos(t_scene *scene, int key)
{
	void	*obj;

	if (key == C)
	{
		obj = scene->cyls;
		((t_cyl *)obj)->point = add_vec3(((t_cyl *)obj)->point,
			new_vec3(0, 5, 0));
		push_image(scene);
	}
	if (key == S)
	{
		obj = scene->spheres;
		((t_sphere *)obj)->centre = add_vec3(((t_sphere *)obj)->centre,
			new_vec3(0, 5, 0));
		push_image(scene);
	}
}

void	move_y_neg(t_scene *scene, int key)
{
	void	*obj;

	if (key == C)
	{
		obj = scene->cyls;
		((t_cyl *)obj)->point = add_vec3(((t_cyl *)obj)->point,
			new_vec3(0, -5, 0));
		push_image(scene);
	}
	if (key == S)
	{
		obj = scene->spheres;
		((t_sphere *)obj)->centre = add_vec3(((t_sphere *)obj)->centre,
			new_vec3(0, -5, 0));
		push_image(scene);
	}
}

void	move_x_pos(t_scene *scene, int key)
{
	void	*obj;

	if (key == C)
	{
		obj = scene->cyls;
		((t_cyl *)obj)->point = add_vec3(((t_cyl *)obj)->point,
			new_vec3(5, 0, 0));
		push_image(scene);
	}
	if (key == S)
	{
		obj = scene->spheres;
		((t_sphere *)obj)->centre = add_vec3(((t_sphere *)obj)->centre,
			new_vec3(5, 0, 0));
		push_image(scene);
	}
}

void	move_x_neg(t_scene *scene, int key)
{
	void	*obj;

	if (key == C)
	{
		obj = scene->cyls;
		((t_cyl *)obj)->point = add_vec3(((t_cyl *)obj)->point,
			new_vec3(-5, 0, 0));
		push_image(scene);
	}
	if (key == S)
	{
		obj = scene->spheres;
		((t_sphere *)obj)->centre = add_vec3(((t_sphere *)obj)->centre,
			new_vec3(-5, 0, 0));
		push_image(scene);
	}
}

void	move_element(int keycode, t_scene *scene)
{
	if (keycode == UP)
		move_y_pos(scene, scene->obj_id);
	if (keycode == DOWN)
		move_y_neg(scene, scene->obj_id);
	if (keycode == LEFT)
		move_x_neg(scene, scene->obj_id);
	if (keycode == RIGHT)
		move_x_pos(scene, scene->obj_id);
}
