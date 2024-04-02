/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** error handling
** error_handling
*/

#include "../include/amazed.h"

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
    return count_start != 1 || count_end != 1 || count_nb_robot != 1;
}

bool check_room_after_flag(char **tab)
{
    for (int i = 0; i < my_strlen_array(tab); i++) {
        if (my_strcmp(tab[i], "##start") == 0 && !is_room(tab[i + 1])) {
            return False;
        }
        if (my_strcmp(tab[i], "##end") == 0 && !is_room(tab[i + 1])) {
            return False;
        }
    }
    return True;
}

bool check_file_content(char **tab)
{
    for (int i = 0; i < my_strlen_array(tab); i++) {
        if (!is_flag(tab[i]) && !is_nb_robot(tab[i]) && !is_room(tab[i]) &&
        !is_tunnel(tab[i])) {
            return False;
        }
    }
    return True;
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
    for (int i = 0; i < my_strlen_array(amazed->file); i++)
        if (is_tunnel(amazed->file[i]) && !check_correct_tunnel_aux(amazed, i))
            return False;
    return True;
}
