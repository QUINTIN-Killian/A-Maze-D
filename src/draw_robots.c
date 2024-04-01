/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** Drawing robots
** draw_robots
*/

#include "../include/amazed.h"

int draw_robots(amazed_t *amazed)
{
    robot_t **robots = amazed->tab_robot;

    for (int i = 0; robots[i] != NULL; i++) {
        my_putstr("ROBOT ");
        my_put_nbr(robots[i]->robot_id);
        my_putstr(" | Current room : ");
        my_put_nbr(robots[i]->current_room);
        my_putchar('\n');
    }
    return 0;
}
