/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** error handling
** error_handling
*/

#include "../include/amazed.h"

static void error_multiple_flags(int count_start, int count_end,
    int count_nb_robot)
{
    if (count_start != 1)
        mini_fdprintf(2, "There must be one '##start' flag.\n");
    if (count_end != 1)
        mini_fdprintf(2, "There must be one '##end' flag.\n");
    if (count_nb_robot != 1)
        mini_fdprintf(2, "There must be one robot number.\n");
}

bool multiple_flags(char **tab)
{
    int count_start = 0;
    int count_end = 0;
    int count_nb_robot = 0;

    for (int i = 0; i < my_strlen_array(tab); i++) {
        if (my_strcmp(tab[i], "##start") == 0) {
            count_start++;
            continue;
        }
        if (my_strcmp(tab[i], "##end") == 0) {
            count_end++;
            continue;
        }
        if (is_nb_robot(tab[i]))
            count_nb_robot++;
    }
    error_multiple_flags(count_start, count_end, count_nb_robot);
    return count_start != 1 || count_end != 1 || count_nb_robot != 1;
}

bool check_room_after_flag(char **tab)
{
    for (int i = 0; i < my_strlen_array(tab); i++) {
        if (my_strcmp(tab[i], "##start") == 0 && !is_room(tab[i + 1])) {
            mini_fdprintf(2, "There must be a room after '##start'.\n");
            return false;
        }
        if (my_strcmp(tab[i], "##end") == 0 && !is_room(tab[i + 1])) {
            mini_fdprintf(2, "There must be a room after '##end'.\n");
            return false;
        }
    }
    return true;
}

static bool check_correct_tunnel_aux(amazed_t *amazed, int i)
{
    int ans = 0;
    char **line = separate_words(amazed->file[i], "-");

    for (int j = 0; j < amazed->nb_room; j++) {
        if (my_strcmp(line[0], amazed->tab_room[j]->name) == 0)
            ans++;
        if (my_strcmp(line[1], amazed->tab_room[j]->name) == 0)
            ans++;
    }
    free_word_array(line);
    return ans == 2;
}

bool check_correct_tunnel(amazed_t *amazed)
{
    for (int i = 0; i < my_strlen_array(amazed->file); i++) {
        if (is_tunnel(amazed->file[i]) &&
        !check_correct_tunnel_aux(amazed, i)) {
            mini_fdprintf(2, "A tunnel does not refer to an existing room.\n");
            return false;
        }
    }
    return true;
}

static bool is_unique_room_aux(room_t **tab_room, int i)
{
    for (int j = i + 1; tab_room[j] != NULL; j++)
        if (my_strcmp(tab_room[i]->name, tab_room[j]->name) == 0 ||
        (tab_room[i]->x == tab_room[j]->x && tab_room[i]->y == tab_room[j]->y))
            return false;
    return true;
}

bool is_unique_room(room_t **tab_room)
{
    for (int i = 0; tab_room[i] != NULL; i++) {
        if (!is_unique_room_aux(tab_room, i)) {
            mini_fdprintf(2,
            "Several rooms have the same name or coordinates.\n");
            return false;
        }
    }
    return true;
}
