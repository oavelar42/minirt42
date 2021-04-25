/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:07:35 by oavelar           #+#    #+#             */
/*   Updated: 2021/04/10 14:47:38 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	delete_cameras(t_cam **cams)
{
	t_cam	*current;
	t_cam	*node;

	if (!*cams || !cams)
		return ;
	current = *cams;
	while (current)
	{
		node = current->next;
		free(current);
		current = node;
	}
	*cams = NULL;
}

void	next_camera(t_scene *scene)
{
	t_cam	*current;

	if (scene->cams->next == NULL)
	{
		printf("\r\nNo more cameras, lets close your program\n");
		close_program(scene);
	}
	current = scene->cams->next;
	free(scene->cams);
	scene->cams = current;
}
