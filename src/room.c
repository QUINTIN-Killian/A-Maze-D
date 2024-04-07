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

    room->occupied = False;
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

static int get_room_id(amazed_t *amazed, char *name)
{
    for (int i = 0; amazed->tab_room[i] != NULL; i++)
        if (my_strcmp(amazed->tab_room[i]->name, name) == 0)
            return i;
    mini_fdprintf(2, "Error get_room_id function : name not found.\n");
    return -1;
}

static bool is_id_present(int *tab, int id)
{
    for (int i = 0; tab[i] != -1; i++)
        if (tab[i] == id)
            return True;
    return False;
}

static int *add_id_in_close_rooms_aux(int *tab, int id)
{
    int *ans;
    int len = 0;

    for (int i = 0; tab[i] != -1; i++)
        len++;
    ans = malloc(sizeof(int) * (len + 2));
    for (int i = 0; tab[i] != -1; i++)
        ans[i] = tab[i];
    ans[len] = id;
    ans[len + 1] = -1;
    free(tab);
    return ans;
}

static void add_id_in_close_rooms(amazed_t *amazed, int dest_room_id,
    int src_room_id)
{
    if (dest_room_id == src_room_id)
        return;
    for (int i = 0; amazed->tab_room[i] != NULL; i++) {
        if (amazed->tab_room[i]->id == dest_room_id &&
        !is_id_present(amazed->tab_room[i]->close_rooms, src_room_id)) {
            amazed->tab_room[i]->close_rooms =
            add_id_in_close_rooms_aux(amazed->tab_room[i]->close_rooms,
            src_room_id);
            return;
        }
    }
}

void add_close_rooms(amazed_t *amazed)
{
    char **tmp;

    for (int i = 0; i < my_strlen_array(amazed->file); i++) {
        if (is_tunnel(amazed->file[i])) {
            tmp = separate_words(amazed->file[i], "-");
            add_id_in_close_rooms(amazed, get_room_id(amazed, tmp[0]),
            get_room_id(amazed, tmp[1]));
            add_id_in_close_rooms(amazed, get_room_id(amazed, tmp[1]),
            get_room_id(amazed, tmp[0]));
            free_word_array(tmp);
        }
    }
}
