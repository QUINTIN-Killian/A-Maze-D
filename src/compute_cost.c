/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** main file
** compute_cost
*/

#include "../include/amazed.h"

int compute_recursive(int cost, int pos, amazed_t *params, int error)
{
    room_t **rooms = params->tab_room;
    int *adjacent_rooms = rooms[pos]->close_rooms;

    my_put_nbr(error);
    my_putchar('\n');
    if (pos == params->id_start && error == 1)
        error = 0;
    if (rooms[pos]->cost == -1 || cost < rooms[pos]->cost) {
        rooms[pos]->cost = cost;
    }
    for (int i = 0; adjacent_rooms[i] != -1; i++) {
        if (rooms[adjacent_rooms[i]]->cost == -1 ||
        rooms[adjacent_rooms[i]]->cost > cost) {
            error = compute_recursive(cost + 1, adjacent_rooms[i], rooms, error);
        }
    }
    return error;
}

int compute_cost(amazed_t *amazed)
{
    int error = compute_recursive(0, amazed->id_end, amazed->tab_room, 1);

    if (error == 1) {
        write(2, "Error : unreachable end room\n", 29);
        return 84;
    }
    return 0;
}
