/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** manage robots movements
** movements
*/

#include "../include/amazed.h"

int are_all_robots_arrived(amazed_t *amazed)
{
    for (int i = 0; amazed->tab_robot[i] != NULL; i++)
        if (amazed->tab_robot[i]->current_room != amazed->id_end)
            return 0;
    return 1;
}

int get_optimal_room_id(amazed_t *amazed, int *close_room)
{
    room_t *room;
    room_t *room_ref = NULL;

    if (close_room[0] == -1) {
        mini_fdprintf(2, "Error get_optimal_room_id function : no way out.\n");
        return -1;
    }
    for (int i = 0; close_room[i] != -1; i++) {
        room = get_room_by_id(amazed, close_room[i]);
        if (room->cost < 0 || room->occupied)
            continue;
        if (room->id == amazed->id_end)
            return room->id;
        if (room_ref == NULL || room->cost < room_ref->cost)
            room_ref = room;
    }
    if (room_ref == NULL)
        return -1;
    return room_ref->id;
}

static void switch_room(amazed_t *amazed, room_t *room_ref, room_t *room_tmp)
{
    if (room_ref->id != amazed->id_start) {
        room_ref->cost--;
        room_ref->occupied = 0;
    }
    if (room_tmp->id != amazed->id_end) {
        room_tmp->cost++;
        room_tmp->occupied = 1;
    }
}

static void move_robots_aux(amazed_t *amazed)
{
    room_t *room_ref;
    room_t *room_tmp;
    int next_id;
    int print_space = 0;

    for (int i = 0; amazed->tab_robot[i] != NULL; i++) {
        if (amazed->tab_robot[i]->current_room == amazed->id_end)
            continue;
        room_ref = get_room_by_id(amazed, amazed->tab_robot[i]->current_room);
        next_id = get_optimal_room_id(amazed, room_ref->close_rooms);
        if (next_id == -1)
            continue;
        room_tmp = get_room_by_id(amazed, next_id);
        amazed->tab_robot[i]->current_room = next_id;
        switch_room(amazed, room_ref, room_tmp);
        print_robots_moves(i, room_tmp->name, &print_space);
    }
}

void move_robots(amazed_t *amazed)
{
    while (!are_all_robots_arrived(amazed)) {
        move_robots_aux(amazed);
        mini_printf("\n");
    }
}
