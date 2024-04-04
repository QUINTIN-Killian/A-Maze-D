/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** interpret the line of the file
** line_getter
*/

#include "../include/amazed.h"

bool line_getter3(amazed_t *amazed, char *line, int n)
{
    if (n >= 0 && is_flag(amazed->file[n]) && !is_room(line))
        return False;
    if (is_room(line)) {
        if (is_unique_room(amazed->file, line)) {
            amazed->nb_room++;
            return True;
        } else
            return False;
    }
    if (is_tunnel(line) && (amazed->nb_room < 2 || !amazed->one_start ||
    !amazed->one_end))
        return False;
    if (is_tunnel(line)) {
        if (check_correct_tunnel(amazed->file, line)) {
            amazed->nb_tunnel++;
            return True;
        } else
            return False;
    }
    return True;
}

bool line_getter2(amazed_t *amazed, char *line, int n)
{
    if (my_strcmp(line, "##start") == 0) {
        if (!amazed->one_start) {
            amazed->one_start = True;
            return True;
        } else
            return False;
    }
    if (my_strcmp(line, "##end") == 0) {
        if (!amazed->one_end) {
            amazed->one_end = True;
            return True;
        } else
            return False;
    }
    return line_getter3(amazed, line, n);
}

bool line_getter1(amazed_t *amazed, char *line, int n)
{
    int nb_robot;

    if (!is_flag(line) && !is_nb_robot(line) && !is_room(line) &&
    !is_tunnel(line))
        return False;
    if ((n != -1 && is_nb_robot(line)) || (n == -1 && !is_nb_robot(line)))
        return False;
    if (is_nb_robot(line) && n == -1) {
        nb_robot = convert_str_in_int(line);
        if (amazed->nb_robot == -1 && nb_robot > 0) {
            amazed->nb_robot = nb_robot;
            return True;
        } else
            return False;
    }
    return line_getter2(amazed, line, n);
}
