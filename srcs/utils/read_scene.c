/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:07:35 by oavelar           #+#    #+#             */
/*   Updated: 2021/04/10 14:47:38 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_scene_values(t_scene *scene)
{
	if (!scene->res.declared)
		exit_error_msg(SCENE_FORMAT_ERR, scene);
	if (!scene->cam_count)
		exit_error_msg(NO_CAM_ERR, scene);
}



void	read_scene(char *file, t_scene *scene)
{
	int	fd;
	char	*line;
	char	*temp;
	int	bytes;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_error_msg(SCENE_FILE_ERR, scene);
	while ((bytes = get_next_line(fd, &line)) > 0)
	{
		temp = line;
		read_element(&line, scene);
		free(temp);
	}
	free(line)
	close(fd);
	check_scene_values(scene);
}
