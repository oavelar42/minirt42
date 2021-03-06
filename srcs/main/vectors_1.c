/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:07:35 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/20 19:48:58 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	cross_vec3(t_vec3 u, t_vec3 v)
{
	t_vec3		t;

	t.x = u.y * v.z - u.z * v.y;
	t.y = u.z * v.x - u.x * v.z;
	t.z = u.x * v.y - u.y * v.x;
	return (t);
}

double	mod_vec3(t_vec3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

double	det_mat3x3(t_mat3x3 m)
{
	double		det;

	det = m.v1.x * m.v2.y * m.v3.z + m.v2.x * m.v3.y * m.v1.z
		+ m.v1.y * m.v2.z * m.v3.x - m.v1.z * m.v2.y * m.v3.x
		- m.v1.y * m.v2.x * m.v3.z - m.v2.z * m.v3.y * m.v1.x;
	return (det);
}

t_mat3x3	invert_mat3x3(t_mat3x3 m)
{
	t_mat3x3	inv;
	double		det;

	det = det_mat3x3(m);
	inv.v1.x = (m.v2.y * m.v3.z - m.v2.z * m.v3.y) / det;
	inv.v2.x = -1 * (m.v1.y * m.v3.z - m.v1.z * m.v3.y) / det;
	inv.v3.x = (m.v1.y * m.v2.z - m.v1.z * m.v2.y) / det;
	inv.v1.y = -1 * (m.v2.x * m.v3.z - m.v2.z * m.v3.x) / det;
	inv.v2.y = (m.v1.x * m.v3.z - m.v1.z * m.v3.x) / det;
	inv.v3.y = -1 * (m.v1.x * m.v2.z - m.v1.z * m.v2.x) / det;
	inv.v1.z = (m.v2.x * m.v3.y - m.v2.y * m.v3.x) / det;
	inv.v2.z = -1 * (m.v1.x * m.v3.y - m.v1.y * m.v3.x) / det;
	inv.v3.z = (m.v1.x * m.v2.y - m.v1.y * m.v2.x) / det;
	return (inv);
}

t_vec3	mult_vec3_mat3x3(t_vec3 v, t_mat3x3 m)
{
	t_vec3		t;

	t.x = v.x * m.v1.x + v.y * m.v2.x + v.z * m.v3.x;
	t.y = v.x * m.v1.y + v.y * m.v2.y + v.z * m.v3.y;
	t.z = v.x * m.v1.z + v.y * m.v2.z + v.z * m.v3.z;
	return (t);
}
