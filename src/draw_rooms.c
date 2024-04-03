/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** Drawing rooms
** draw_rooms
*/

#include "../include/amazed.h"

int draw_rooms(amazed_t *amazed)
{
    room_t **parse_rooms = amazed->tab_room;
    int *connected;

    for (int i = 0; i < amazed->nb_room; i++) {
        my_putstr("ID:");
        my_put_nbr(parse_rooms[i]->id);
        my_putstr(" NAME:");
        my_putstr(parse_rooms[i]->name);
        my_putstr(" COST:");
        my_put_nbr(parse_rooms[i]->cost);
        my_putstr(" | ");
        connected = parse_rooms[i]->close_rooms;
        for (int i = 0; connected[i] != -1; i++) {
            my_putstr(" -> ");
            my_put_nbr(connected[i]);
        }
        my_putchar('\n');
    }
    return 0;
}
