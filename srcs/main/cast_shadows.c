/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_shadows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:07:35 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/20 19:48:08 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cast_ray_2(t_ray *ray, t_scene *scene)
{
	void	*objs;

	objs = scene->cyls;
	while (objs)
	{
		render_cyl(ray, scene, (t_cyl *)objs);
		objs = ((t_cyl *)objs)->next;
	}
	objs = scene->squares;
	while (objs)
	{
		render_square(ray, scene, (t_square *)objs);
		objs = ((t_square *)objs)->next;
	}
	objs = scene->triangles;
	while (objs)
	{
		render_triangle(ray, scene, (t_triangle *)objs);
		objs = ((t_triangle *)objs)->next;
	}
}

int	shadows_2(t_scene *scene, t_ray *shadow_ray,
t_vec3 light_pos, void *obj)
{
	obj = scene->cyls;
	while (obj)
	{
		if (shadow_ray->t)
			shadow_ray->t = intersect_cyl(shadow_ray, (t_cyl *)obj);
		if (block_light(shadow_ray, light_pos))
			return (1);
		obj = ((t_cyl *)obj)->next;
	}
	obj = scene->squares;
	while (obj)
	{
		if (shadow_ray->t)
			shadow_ray->t = intersect_square(shadow_ray, (t_square *)obj);
		if (block_light(shadow_ray, light_pos))
			return (1);
		obj = ((t_square *)obj)->next;
	}
	return (shadows_3(scene, shadow_ray, light_pos, obj));
}

int	shadows_3(t_scene *scene, t_ray *shadow_ray,
t_vec3 light_pos, void *obj)
{
	obj = scene->triangles;
	while (obj)
	{
		if (shadow_ray->t)
			shadow_ray->t = intersect_triangle(shadow_ray, (t_triangle *)obj);
		if (block_light(shadow_ray, light_pos))
			return (1);
		obj = ((t_triangle *)obj)->next;
	}
	return (0);
}
