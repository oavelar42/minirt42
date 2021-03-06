/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_triangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:07:35 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/20 19:49:45 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	add_triangle(t_triangle **triangles, t_triangle *new_triangle)
{
	t_triangle	*last;

	if (!triangles || !new_triangle)
		return ;
	if (!*triangles)
	{
		*triangles = new_triangle;
		return ;
	}
	last = *triangles;
	while (last->next)
		last = last->next;
	last->next = new_triangle;
}

t_triangle	*create_triangle(char **line, t_scene *scene)
{
	t_triangle	*triangle;

	triangle = malloc(sizeof(t_triangle));
	if (!triangle)
		exit_error_msg(DEFAULT_ERR, scene);
	triangle->a = get_vec3(line, scene);
	triangle->b = get_vec3(line, scene);
	triangle->c = get_vec3(line, scene);
	triangle->color = get_color_vec3(line, scene);
	if (**line != EMPTY_LINE_GNL)
		exit_error_msg(SCENE_FORMAT_ERR, scene);
	triangle->next = NULL;
	return (triangle);
}

void	read_triangle(char **line, t_scene *scene)
{
	t_triangle	*new_triangle;

	*line += 3;
	new_triangle = create_triangle(line, scene);
	add_triangle(&scene->triangles, new_triangle);
	return ;
}

void	delete_triangles(t_triangle **triangles)
{
	t_triangle	*current;
	t_triangle	*node;

	if (!triangles || !*triangles)
		return ;
	current = *triangles;
	while (current)
	{
		node = current->next;
		free(current);
		current = node;
	}
	*triangles = NULL;
}
