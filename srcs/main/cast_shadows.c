/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_shadows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:07:35 by oavelar           #+#    #+#             */
/*   Updated: 2021/04/10 14:47:38 by oavelar          ###   ########.fr       */
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
}

int	shadows_2(t_scene *scene, t_ray *shadow_ray, t_vec3 light_pos, void *obj)
{
	obj = scene->cyls;
	while (obj)
	{
		if ((shadow_ray->t = intersect_cyl(shadow_ray, (t_cyl *)obj)))
			if (block_light(shadow_ray, light_pos))
				return (1);
		obj = ((t_cyl *)obj)->next;
	}
	return (0);
}
