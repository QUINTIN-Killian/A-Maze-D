/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** get things
** getter
*/

#include "../include/amazed.h"

int get_nb_robot(char **tab)
{
    int ans = -1;

    for (int i = 0; i < my_strlen_array(tab); i++) {
        if (is_nb_robot(tab[i])) {
            ans = convert_str_in_int(tab[i]);
            break;
        }
    }
    if (ans == -1 || ans == 0)
        mini_fdprintf(2, "There must be at least 1 robot.\n");
    return ans;
}

int get_nb_room(char **tab)
{
    int ans = 0;

    for (int i = 0; i < my_strlen_array(tab); i++)
        if (is_room(tab[i]))
            ans++;
    if (ans < 2)
        mini_fdprintf(2, "There must be at least 2 rooms.\n");
    return ans;
}

int get_nb_tunnel(char **tab)
{
    int ans = 0;

    for (int i = 0; i < my_strlen_array(tab); i++)
        if (is_tunnel(tab[i]))
            ans++;
    if (ans == 0)
        mini_fdprintf(2, "The end room can not be reached.\n");
    return ans;
}
