/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** manage rooms
** room
*/

#include "../include/amazed.h"

room_t *create_room(int id, char *name, int x, int y)
{
    room_t *room = malloc(sizeof(room_t));

    room->cost = -1;
    room->id = id;
    room->name = my_strdup(name);
    room->x = x;
    room->y = y;
    room->close_rooms = malloc(sizeof(int));
    room->close_rooms[0] = -1;
    return room;
}

static void set_id_start_end_rooms(amazed_t *amazed, int i, int id)
{
    if (i - 1 >= 0 && my_strcmp(amazed->file[i - 1], "##start") == 0) {
        amazed->id_start = id;
        return;
    }
    if (i - 1 >= 0 && my_strcmp(amazed->file[i - 1], "##end") == 0) {
        amazed->id_end = id;
        return;
    }
}

void create_tab_room(amazed_t *amazed)
{
    int id = 0;
    char **line;

    amazed->tab_room = malloc(sizeof(room_t *) * (amazed->nb_room + 1));
    amazed->tab_room[amazed->nb_room] = NULL;
    for (int i = 0; i < my_strlen_array(amazed->file); i++) {
        if (is_room(amazed->file[i])) {
            set_id_start_end_rooms(amazed, i, id);
            line = separate_words_on_spaces(amazed->file[i]);
            amazed->tab_room[id] = create_room(id, line[0],
            convert_str_in_int(line[1]), convert_str_in_int(line[2]));
            free_word_array(line);
            id++;
        }
    }
}
