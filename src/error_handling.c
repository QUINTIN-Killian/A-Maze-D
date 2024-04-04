/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** error handling
** error_handling
*/

#include "../include/amazed.h"

bool check_room_after_flag(char **tab)
{
    for (int i = 0; i < my_strlen_array(tab); i++) {
        if (my_strcmp(tab[i], "##start") == 0 && !is_room(tab[i + 1])) {
            mini_fdprintf(2, "There must be a room after '##start'.\n");
            return False;
        }
        if (my_strcmp(tab[i], "##end") == 0 && !is_room(tab[i + 1])) {
            mini_fdprintf(2, "There must be a room after '##end'.\n");
            return False;
        }
    }
    return True;
}

static void check_correct_tunnel_aux(char **file, int i, char **tunnel_rooms,
    int *ans)
{
    char **room = separate_words_on_spaces(file[i]);

    if (my_strcmp(room[0], tunnel_rooms[0]) == 0) {
        free_word_array(room);
        *ans += 1;
        return;
    }
    if (my_strcmp(room[0], tunnel_rooms[1]) == 0) {
        free_word_array(room);
        *ans += 1;
        return;
    }
    free_word_array(room);
}

bool check_correct_tunnel(char **file, char *tunnel)
{
    char **tunnel_rooms = separate_words(tunnel, "-");
    int ans = 0;

    if (my_strcmp(tunnel_rooms[0], tunnel_rooms[1]) == 0) {
        free_word_array(tunnel_rooms);
        return False;
    }
    for (int i = 0; i < my_strlen_array(file); i++) {
        if (is_room(file[i])) {
            check_correct_tunnel_aux(file, i, tunnel_rooms, &ans);
        }
        if (ans == 2) {
            free_word_array(tunnel_rooms);
            return True;
        }
    }
    free_word_array(tunnel_rooms);
    return False;
}

static bool is_unique_room_aux(char *room1, char *room2)
{
    char **room_src = separate_words_on_spaces(room1);
    char **room_comp = separate_words_on_spaces(room2);

    if (my_strcmp(room_src[0], room_comp[0]) == 0) {
        free_word_array(room_src);
        free_word_array(room_comp);
        return False;
    }
    free_word_array(room_src);
    free_word_array(room_comp);
    return True;
}

bool is_unique_room(char **file, char *room)
{
    for (int i = 0; i < my_strlen_array(file); i++)
        if (is_room(file[i]) && !is_unique_room_aux(room, file[i]))
            return False;
    return True;
}
