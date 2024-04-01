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
    linked_room_t *parse_rooms = amazed->room;
    int *connected;

    while (parse_rooms != NULL) {
        my_putstr("ID:");
        my_put_nbr(parse_rooms->room_id);
        my_putstr(" (");
        my_putstr(parse_rooms->name);
        my_putstr(")");
        connected = parse_rooms->close_rooms;
        for (int i = 0; connected[i] != -1; i++) {
            my_putstr(" -> ");
            my_put_nbr(connected[i]);
        }
        my_putchar('\n');
        parse_rooms = parse_rooms->next;
    }
    return 0;
}
