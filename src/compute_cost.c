/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** main file
** compute_cost
*/

#include "../include/amazed.h"

int is_dead_end(room_t **rooms, int *adjacent_rooms, int i, amazed_t *params)
{
    room_t *current = rooms[adjacent_rooms[i]];

    if ((current->close_rooms[1] == -1
    || (current->close_rooms[2] == -1 &&
    (rooms[current->close_rooms[0]]->cost == -2
    || rooms[current->close_rooms[1]]->cost == -2))
    ) && (rooms[adjacent_rooms[i]]->id != params->id_end
    && rooms[adjacent_rooms[i]]->id != params->id_start)) {
        rooms[adjacent_rooms[i]]->cost = -2;
        return 1;
    }
    return 0;
}

int recursive_cost(int cost, int pos, amazed_t *params, int error)
{
    room_t **rooms = params->tab_room;
    int *adjacent_rooms = rooms[pos]->close_rooms;

    if (pos == params->id_start && error == 1)
        error = 0;
    if (rooms[pos]->cost == -1 || cost < rooms[pos]->cost) {
        rooms[pos]->cost = cost;
    }
    for (int i = 0; adjacent_rooms[i] != -1; i++) {
        if (!is_dead_end(rooms, adjacent_rooms, i, params) &&
        (rooms[adjacent_rooms[i]]->cost == -1 ||
        rooms[adjacent_rooms[i]]->cost > cost)) {
            error = recursive_cost(cost + 1, adjacent_rooms[i], params, error);
        }
    }
    return error;
}

int compute_cost(amazed_t *amazed)
{
    int error = recursive_cost(0, amazed->id_end, amazed, 1);

    if (error == 1) {
        mini_fdprintf(2, "The end room can not be reached.\n");
        return 0;
    }
    return 1;
}
