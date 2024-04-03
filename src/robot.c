/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** robot management
** robot
*/

#include "../include/amazed.h"

robot_t *create_robot(int id, int room_id)
{
    robot_t *robot = malloc(sizeof(robot_t));

    robot->robot_id = id;
    robot->current_room = room_id;
    return robot;
}

void create_tab_robot(amazed_t *amazed)
{
    amazed->tab_robot = malloc(sizeof(robot_t *) * (amazed->nb_robot + 1));
    amazed->tab_robot[amazed->nb_robot] = NULL;
    for (int i = 0; i < amazed->nb_robot; i++)
        amazed->tab_robot[i] = create_robot(i, amazed->id_start);
}
