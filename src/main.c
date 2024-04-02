/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** main file
** main
*/
/*
NOTES ET OBJECTIFS :
    - vérifier si on retrouve le nom des rooms dans les rooms et les tunnels
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
    if (amazed->file == NULL || amazed->file[0] == NULL ||
    multiple_flags(amazed->file) || !check_room_after_flag(amazed->file) ||
    !check_file_content(amazed->file))
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
        for (int i = 0; amazed->tab_room[i] != NULL; i++)
            free(amazed->tab_room[i]);
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
    amazed.nb_robot = get_nb_robot(amazed.file);
    print_end(&amazed);
    destroy_struct(&amazed);
    return 0;
}
