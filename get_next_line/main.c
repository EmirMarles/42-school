/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:22:46 by emarles           #+#    #+#             */
/*   Updated: 2025/01/12 14:51:20 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
    char *string;
    char *string2;
    char *string3;
    int i;

    i = 0;
    int fd = open("read_from.txt", O_RDONLY);
    // printf("original fd %d\n\n\n", fd);
    if (fd < 0)
    {
        perror("Error");
        return 1;
    }
    while (i < 10)
    {
        string = get_next_line(fd);
        printf("Result : %s\n", string);
        i++;
    }
    close(fd);
    return (0);
}