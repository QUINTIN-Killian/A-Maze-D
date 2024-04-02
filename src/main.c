/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** main file
** main
*/
/*
NOTES ET OBJECTIFS :
    - vérifier si chaque room est unique
*/

#include "../include/amazed.h"

static bool init_struct(amazed_t *amazed)
{
    amazed->file = NULL;
    amazed->tab_robot = NULL;
    amazed->tab_room = NULL;
    get_file(amazed);
    if (amazed->file == NULL)
        return False;
    del_blank_lines(amazed->file);
    amazed->nb_robot = get_nb_robot(amazed->file);
    amazed->nb_room = get_nb_room(amazed->file);
    create_tab_room(amazed);
    if (amazed->file == NULL || amazed->file[0] == NULL || amazed->nb_robot
    == 0 || amazed->nb_room < 2 || multiple_flags(amazed->file) ||
    !check_room_after_flag(amazed->file) || !check_file_content(amazed->file)
    || !is_unique_room(amazed->tab_room) || !check_correct_tunnel(amazed))
        return False;
    return True;
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
        destroy_struct(&amazed);
        return 84;
    }
    print_end(&amazed);
    destroy_struct(&amazed);
    return 0;
}
