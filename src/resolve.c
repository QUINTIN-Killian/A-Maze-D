/*
** EPITECH PROJECT, 2024
** B-CPE-200-LYN-2-1-amazed-killian.quintin
** File description:
** resolve
*/
#include "include/amazed.h"

void save_best_room(room_t **tab_room, int i, int tempid, int tempval)
{
    int close_room_id = tab_room[i]->close_rooms[i];

    if (tab_room[i]->id == close_room_id) {
        if (tempval == 0) {
            tempval = tab_room[i]->cost;
            tempid = tab_room[i]->id;
        }
        if (tab_room[i]->cost < tempval) {
            tempval = tab_room[i]->cost;
            tempid = tab_room[i]->id;
        }
    }
}

int check_close_rooms_costs(room_t **tab_room, robot_t *robot)
{
    int close_room_id = 0;
    int tempid = 0;
    int tempval = 0;

    for (int i = 0; tab_room[i] != NULL; i++) {
        for (int i = 0; tab_room[i]->close_rooms[i] != -1; i++) {
            save_best_room(tab_room, i, tempid, tempval);
        }
    }
    return tempid;
}

int next_room_finder(amazed_t *amazed)
{
    int robot_at_end = 0;
    int next_room_id = 0;

    while (robot_at_end < amazed->nb_robot) {
        for (int i = 0; amazed->tab_robot[i] != NULL; i++) {
            next_room_id = check_close_rooms_costs(amazed->tab_room,
                &amazed->tab_robot[i]->current_room);
            amazed->tab_robot[i]->current_room = next_room_id;
        }
    }
}
