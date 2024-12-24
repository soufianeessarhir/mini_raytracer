/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:16:40 by sessarhi          #+#    #+#             */
/*   Updated: 2024/12/24 14:09:50 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H


# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <fcntl.h>
#include <string.h>
#include <stdint.h>
#include "./includes/objects.h"
#include "./includes/tmpobjects.h"





#define BUFFER_SIZE 1000000
#define WIDTH 800
#define HEIGHT 800
#define FLOAT double


// Parsing
bool  parse_crd(const char *str,FLOAT *x ,FLOAT *y ,FLOAT *z);
bool	parse_rgb(const char *str ,int *r ,int *g ,int *b);


// Utils
char    **ft_split(char const *s, char c);
FLOAT	ft_atof(char *str);
int	Rgb_value(const char *str);
void   process_flie( char **av , t_scene *scene);


#endif