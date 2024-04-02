/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** main file
** compute_cost
*/

#include "../include/amazed.h"

int compute_recursive(int cost, int pos, linked_room_t **rooms, int number_of_rooms)
{
    int *adjacent_rooms = rooms[pos]->close_rooms;

    cost++;
    for (int i = 0; adjacent_rooms[i] != -1; i++) {
        if (rooms[i]->cost == -1 || rooms[i]->cost > cost) {
            rooms[i]->cost = cost;
            compute_recursive(cost, adjacent_rooms[i], rooms, number_of_rooms);
        }
    }
    return 0;
}

int compute_cost(amazed_t *amazed)
{
    int *values = malloc(sizeof(int) * 2);
    values[0] = -1;
    values[1] = amazed->final_room;

    compute_recursive(-1, 0, amazed->room, amazed->n_rooms);
    return 0;
}
