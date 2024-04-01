/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** useful functions
** functions
*/

#include "include/my.h"
#include "include/amazed.h"

void free_linked_room(linked_room_t *node)
{
    linked_room_t *tmp;

    while (node != NULL) {
        tmp = node;
        node = node->next;
        free(tmp->name);
        free_word_array(tmp->close_rooms);
        free(tmp);
    }
}
