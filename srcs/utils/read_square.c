/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:07:35 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/20 19:49:42 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	add_square(t_square **squares, t_square *new_square)
{
	t_square	*last;

	if (!squares || !new_square)
		return ;
	if (!*squares)
	{
		*squares = new_square;
		return ;
	}
	last = *squares;
	while (last->next)
		last = last->next;
	last->next = new_square;
}

t_square	*create_square(char **line, t_scene *scene)
{
	t_square	*square;

	square = malloc(sizeof(t_square));
	if (!square)
		exit_error_msg(DEFAULT_ERR, scene);
	square->center = get_vec3(line, scene);
	square->n_dir = get_vec3(line, scene);
	if (range_vec3(square->n_dir, -1.0, 1.0))
		exit_error_msg(VEC_RANGE_ERR, scene);
	square->side = get_double(line, scene);
	square->color = get_color_vec3(line, scene);
	if (**line != EMPTY_LINE_GNL)
		exit_error_msg(SCENE_FORMAT_ERR, scene);
	square->next = NULL;
	return (square);
}

void	read_square(char **line, t_scene *scene)
{
	t_square	*new_square;

	*line += 3;
	new_square = create_square(line, scene);
	add_square(&scene->squares, new_square);
	return ;
}

void	delete_squares(t_square **squares)
{
	t_square	*current;
	t_square	*node;

	if (!squares || !*squares)
		return ;
	current = *squares;
	while (current)
	{
		node = current->next;
		free(current);
		current = node;
	}
	*squares = NULL;
}
