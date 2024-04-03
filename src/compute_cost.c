/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** main file
** compute_cost
*/

#include "../include/amazed.h"

int compute_recursive(int cost, int pos, room_t **rooms)
{
    int *adjacent_rooms = rooms[pos]->close_rooms;

    if (rooms[pos]->cost == -1 || cost < rooms[pos]->cost) {
        rooms[pos]->cost = cost;
    }
    for (int i = 0; adjacent_rooms[i] != -1; i++) {
        if (rooms[adjacent_rooms[i]]->cost == -1 ||
        rooms[adjacent_rooms[i]]->cost > cost) {
            compute_recursive(cost + 1, adjacent_rooms[i], rooms);
        }
    }
    return 0;
}

int compute_cost(amazed_t *amazed)
{
    compute_recursive(0, amazed->id_end, amazed->tab_room);
    return 0;
}
