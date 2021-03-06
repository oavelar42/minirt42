/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:07:35 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/20 19:49:18 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	add_cyl(t_cyl **cyls, t_cyl *new_cyl)
{
	t_cyl	*last;

	if (!cyls || !new_cyl)
		return ;
	if (!*cyls)
	{
		*cyls = new_cyl;
		return ;
	}
	last = *cyls;
	while (last->next)
		last = last->next;
	last->next = new_cyl;
}

t_cyl	*create_cyl(char **line, t_scene *scene)
{
	t_cyl	*cyl;

	cyl = malloc(sizeof(t_cyl));
	if (!cyl)
		exit_error_msg(DEFAULT_ERR, scene);
	cyl->point = get_vec3(line, scene);
	cyl->n_vec = get_vec3(line, scene);
	if (range_vec3(cyl->n_vec, -1.0, 1.0))
		exit_error_msg(VEC_RANGE_ERR, scene);
	normalize_vec3(&cyl->n_vec);
	cyl->radius = get_double(line, scene) / 2;
	cyl->h = get_double(line, scene);
	cyl->color = get_color_vec3(line, scene);
	skip_blanks(line);
	if (**line != EMPTY_LINE_GNL)
		exit_error_msg(SCENE_FORMAT_ERR, scene);
	cyl->next = NULL;
	return (cyl);
}

void	read_cyl(char **line, t_scene *scene)
{
	t_cyl	*new_cyl;

	*line += 3;
	new_cyl = create_cyl(line, scene);
	add_cyl(&scene->cyls, new_cyl);
	return ;
}

void	delete_cyls(t_cyl **cyls)
{
	t_cyl	*current;
	t_cyl	*node;

	if (!*cyls || !cyls)
		return ;
	current = *cyls;
	while (current)
	{
		node = current->next;
		free(current);
		current = node;
	}
	*cyls = NULL;
}
