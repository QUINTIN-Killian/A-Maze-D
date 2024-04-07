/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** manage robots movements
** movements
*/

#include "../include/amazed.h"

bool are_all_robots_arrived(amazed_t *amazed)
{
    for (int i = 0; amazed->tab_robot[i] != NULL; i++)
        if (amazed->tab_robot[i]->current_room != amazed->id_end)
            return False;
    return True;
}

int get_optimal_room_id(amazed_t *amazed, int *close_room)
{
    room_t *room1 = get_room_by_id(amazed, close_room[0]);
    room_t *room2;
    int id_ref = -1;

    if (room1 == NULL) {
        mini_fdprintf(2, "IMPASSE\n");
        return -1;
    }
    if (room1->occupied == False)
        id_ref = room1->id;
    for (int i = 1; close_room[i] != -1; i++) {
        room2 = get_room_by_id(amazed, close_room[i]);
        if (room2->cost < room1->cost && room2->occupied == False)
            id_ref = room2->id;
    }
    return id_ref;
}

static void switch_room(amazed_t *amazed, room_t *room_ref, room_t *room_tmp)
{
    if (room_ref->id != amazed->id_start) {
        room_ref->cost--;
        room_ref->occupied = False;
    }
    if (room_tmp->id != amazed->id_end) {
        room_tmp->cost++;
        room_tmp->occupied = True;
    }
}

static void move_robots_aux(amazed_t *amazed)
{
    room_t *room_ref;
    room_t *room_tmp;
    int next_id;
    bool print_space = False;

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
