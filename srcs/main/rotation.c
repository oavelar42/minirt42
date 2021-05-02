/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:07:35 by oavelar           #+#    #+#             */
/*   Updated: 2021/04/10 14:47:38 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3		rotation_x(t_vec3 vec, double x)
{
	t_vec3	new_vec;

	x = x * PI / 180;
	new_vec.x = vec.x;
	new_vec.y = vec.y * cos(x) - vec.z * sin(x);
	new_vec.z = vec.y * sin(x) + vec.z * cos(x);
	return (new_vec);
}

t_vec3		rotation_y(t_vec3 vec, double y)
{
	t_vec3	new_vec;

	y = y * PI / 180;
	new_vec.x = vec.x * cos(y) + vec.z * sin(y);
	new_vec.y = vec.y;
	new_vec.z = vec.x * -sin(y) + vec.z * cos(y);
	return (new_vec);
}

t_vec3		rotation_z(t_vec3 vec, double z)
{
	t_vec3	new_vec;

	z = z * PI / 180;
	new_vec.x = vec.x * cos(z) - vec.y * sin(z);
	new_vec.y = vec.x * sin(z) + vec.y * cos(z);
	new_vec.z = vec.z;
	return (new_vec);
}

t_vec3		rotation(t_vec3 vec, t_vec3 angle)
{
	t_vec3 new_vec;

	new_vec = rotation_x(vec, angle.x);
	new_vec = rotation_y(new_vec, angle.y);
	new_vec = rotation_z(new_vec, angle.z);
	return (new_vec);
}