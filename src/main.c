/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** main file
** main
*/
/*
NOTES ET OBJECTIFS :
    - vérifier si la map est faisable
    - afficher avec la bonne mise en forme à la fin (voir
    maps/labyrinth_error2)
*/

#include "../include/amazed.h"

static bool error_handling_struct(amazed_t *amazed)
{
    if (amazed->nb_robot == -1 || amazed->nb_robot == 0) {
        mini_fdprintf(2,
        "The number of robot is absent, negative or equal to 0.\n");
        return False;
    }
    if (amazed->nb_room < 2) {
        mini_fdprintf(2, "There must be minimum 2 rooms.\n");
        return False;
    }
    if (!check_room_after_flag(amazed->file))
        return False;
    if (amazed->nb_tunnel <= 0) {
        mini_fdprintf(2, "There must be at least one tunnel.\n");
        return False;
    }
    return True;
}

static bool init_struct(amazed_t *amazed)
{
    amazed->one_start = False;
    amazed->one_end = False;
    amazed->file = NULL;
    amazed->tab_robot = NULL;
    amazed->tab_room = NULL;
    amazed->nb_robot = -1;
    amazed->nb_room = 0;
    amazed->nb_tunnel = 0;
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
    compute_cost(&amazed);
    print_end(&amazed);
    destroy_struct(&amazed);
    return 0;
}
