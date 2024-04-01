/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** end management
** end
*/

#include "../include/amazed.h"

static void print_start_room(char **tab)
{
    for (int i = 0; i < my_strlen_array(tab); i++) {
        if (my_strcmp(tab[i], "##start") == 0) {
            mini_printf("%s\n", tab[i + 1]);
            return;
        }
    }
}

static int get_end_ind(char **tab)
{
    for (int i = 0; i < my_strlen_array(tab); i++) {
        if (my_strcmp(tab[i], "##end") == 0) {
            return i;
        }
    }
    return -1;
}

static void print_end_rooms(char **tab)
{
    for (int i = get_end_ind(tab) + 1; i < my_strlen_array(tab); i++) {
        if (is_room(tab[i])) {
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
    mini_printf("#number_of_robots\n%d\n#rooms\n##start\n", amazed->nb_robot);
    print_start_room(amazed->file);
    mini_printf("##end\n");
    print_end_rooms(amazed->file);
    mini_printf("#tunnels\n");
    print_tunnels(amazed->file);
    mini_printf("#moves\n");
    mini_printf("COMING SOON !\n");
}
