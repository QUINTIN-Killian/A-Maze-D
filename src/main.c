/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** main file
** main
*/
/*
NOTES ET OBJECTIFS :
    - vérifier que le parcours est réalisable (cant reach end)
    - afficher avec la bonne mise en forme à la fin (voir
    maps/labyrinth_error2)
*/

#include "../include/amazed.h"

static bool error_handling_struct(amazed_t *amazed)
{
    if (amazed->nb_robot == 0 || amazed->nb_room < 2 || amazed->nb_tunnel == 0
    || multiple_flags(amazed->file) || !check_room_after_flag(amazed->file) ||
    !is_unique_room(amazed->tab_room) || !check_correct_tunnel(amazed))
        return False;
    return True;
}

static bool init_struct(amazed_t *amazed)
{
    amazed->file = NULL;
    amazed->tab_robot = NULL;
    amazed->tab_room = NULL;
    get_file(amazed);
    if (amazed->file == NULL || amazed->file[0] == NULL) {
        mini_fdprintf(2, "The file is empty after deleting useless lines.\n");
        return False;
    }
    del_blank_lines(amazed->file);
    if (amazed->file == NULL || amazed->file[0] == NULL) {
        mini_fdprintf(2, "The file is empty after deleting useless lines.\n");
        return False;
    }
    amazed->nb_robot = get_nb_robot(amazed->file);
    amazed->nb_room = get_nb_room(amazed->file);
    amazed->nb_tunnel = get_nb_tunnel(amazed->file);
    create_tab_room(amazed);
    return error_handling_struct(amazed);
}

static void destroy_struct(amazed_t *amazed)
{
    if (amazed->file != NULL)
        free_word_array(amazed->file);
    if (amazed->tab_robot != NULL) {
        for (int i = 0; amazed->tab_robot[i] != NULL; i++)
            free(amazed->tab_robot[i]);
        free(amazed->tab_robot);
    }
    if (amazed->tab_room != NULL) {
        for (int i = 0; amazed->tab_room[i] != NULL; i++) {
            free(amazed->tab_room[i]->name);
            free(amazed->tab_room[i]->close_rooms);
            free(amazed->tab_room[i]);
        }
        free(amazed->tab_room);
    }
}

int main(void)
{
    amazed_t amazed;

    if (!init_struct(&amazed)) {
        print_error_file(&amazed);
        destroy_struct(&amazed);
        return 84;
    }
    create_tab_robot(&amazed);
    add_close_rooms(&amazed);
    if (compute_cost(&amazed) == 84) {
        destroy_struct(&amazed);
        return 84;
    }
    draw_rooms(&amazed);
    print_end(&amazed);
    move_robots(&amazed);
    destroy_struct(&amazed);
    return 0;
}
