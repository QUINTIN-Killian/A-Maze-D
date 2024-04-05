/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** end management
** end
*/

#include "../include/amazed.h"

static void print_rooms(char **tab)
{
    for (int i = 0; i < my_strlen_array(tab); i++) {
        if (my_strcmp(tab[i], "##start") == 0 ||
        my_strcmp(tab[i], "##end") == 0 || is_room(tab[i])) {
            mini_printf("%s\n", tab[i]);
        }
    }
}

static void print_tunnels(char **tab)
{
    for (int i = 0; i < my_strlen_array(tab); i++) {
        if (is_tunnel(tab[i])) {
            mini_printf("%s\n", tab[i]);
        }
    }
}

void print_end(amazed_t *amazed)
{
    mini_printf("#number_of_robots\n%d\n#rooms\n", amazed->nb_robot);
    print_rooms(amazed->file);
    mini_printf("#tunnels\n");
    print_tunnels(amazed->file);
    mini_printf("#moves\n");
    mini_printf("COMING SOON !\n");
}

void print_error_file(amazed_t *amazed)
{
    mini_printf("#number_of_robots\n");
    if (amazed->nb_robot != -1)
        mini_printf("%d\n", amazed->nb_robot);
    mini_printf("#rooms\n");
    print_rooms(amazed->file);
}