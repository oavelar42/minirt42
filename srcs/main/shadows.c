
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:07:35 by oavelar           #+#    #+#             */
/*   Updated: 2021/04/10 14:47:38 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	block_light(t_ray *shadow_ray, t_vec3 light_pos)
{
	t_vec3	sh_point;
	double	point_dist;
	double	light_dist;

	sh_point = add_vec3(shadow_ray->origin,
		esc_vec3(shadow_ray->t, shadow_ray->origin));
	point_dist = mod_vec3(sub_vec3(sh_point, shadow_ray->origin));
	light_dist = mod_vec3(sub_vec3(light_pos, shadow_ray->origin));
	if (point_dist > 0.0001 && point_dist < light_dist)
		return (1);
	return (0);
}

int	shadows_1(t_scene *scene, t_ray *shadow_ray, t_vec3 light_pos)
{
	void	*obj;

	obj =scene->spheres;
	while (obj)
	{
		if ((shadow_ray->t = intersect_sphere(shadow_ray, (t_sphere *)obj)))
			if (block_light(shadow_ray, light_pos))
				return (1);
		obj = ((t_sphere *)obj)->next;
	}
	obj = scene->planes;
	while (obj)
	{
		if ((shadow_ray->t = intersect_plane(shadow_ray, (t_plane *)obj)))
			if (block_light(shadow_ray, light_pos))
				return (1);
		obj = ((t_plane *)obj)->next;
	}
	return (1);
}
