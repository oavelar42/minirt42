/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:07:35 by oavelar           #+#    #+#             */
/*   Updated: 2021/04/10 14:47:38 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	skip_blanks(char **str)
{
	while (ft_isblank(**str))
		(*str)++;
}

void	skip_digits(char **str)
{
	while (ft_isdigit(**str))
		(*str)++;
}

void	skip_char(char **str, int c)
{
	if (**str == c)
		(*str)++;
}

int		get_int(char **line, t_scene *scene)
{
	int	a;

	skip_blanks(line);
	if (**line == '-' || ft_isdigit(**line))
	{
		a = ft_atoi(*line);
		skip_char(line, '-');
		skip_digits(line);
	}
	else
		exit_error_msg(SCENE_FORMAT_ERR, scene);
	return (a);
}

double	get_double(char **line, t_scene *scene)
{
	double	a;

	skip_blanks(line);
	if (**line == '-' || **line == '.' || ft_isdigit(**line))
	{
		a = ft_atod(*line);
		skip_char(line, '-');
		skip_digits(line);
		skip_char(line, '.');
		skip_digits(line);
	}
	else
		exit_error_msg(SCENE_FORMAT_ERR, scene);
	return (a);
}
