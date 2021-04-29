/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:07:35 by oavelar           #+#    #+#             */
/*   Updated: 2021/04/10 14:47:38 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	cross_vec3(t_vec3 u, t_vec3 v)
{
	t_vec3	t;

	t.x = u.y * v.z - u.z * v.y;
	t.y = u.z * v.x - u.x * v.z;
	t.z = u.x * v.y - u.y * v.x;
	return (t);
}

double		mod_vec3(t_vec3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_vec3	mult_vec3_mat3x3(t_vec3 v, t_mat3x3 m )
{
	t_vec3	t;

	t.x = v.x * m.v1.x + v.y * m.v2.x + v.z * m.v3.x;
	t.y = v.x * m.v1.y + v.y * m.v2.y + v.z * m.v3.y;
	t.z = v.x * m.v1.z + v.y * m.v2.z + v.z * m.v3.z;
	return (t);
}

t_vec3	ft_vec_mult_d(double a, t_vec3 v)
{
	t_vec3	vfinal;

	vfinal.x = v.x * a;
	vfinal.y = v.y * a;
	vfinal.z = v.z * a;
	return (vfinal);
}