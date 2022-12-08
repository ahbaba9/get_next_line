/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:59:08 by amine             #+#    #+#             */
/*   Updated: 2022/12/08 17:09:51 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
    int fd;
    char *line;
    int fd2;
    char *line2;

    fd = open("text", O_RDONLY);
    fd2 = open("text2", O_RDONLY);

    line = get_next_line(fd);
    line2 = get_next_line(fd2);
        printf("line1 : %s", line);
        line = get_next_line(fd);
        printf("line2 : %s", line2);
        line2 = get_next_line(fd2);
}