/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** main file
** main
*/
/*
NOTES ET OBJECTIFS :
    - vérifier s'il y a une seule room après ##start, plusieurs
    après ##end et aucune autre room à un autre endroit
*/

#include "../include/amazed.h"

static bool init_struct(amazed_t *amazed)
{
    amazed->file = NULL;
    amazed->file_ref = NULL;
    amazed->tab_robot = NULL;
    amazed->room = NULL;
    get_file(amazed);
    if (amazed->file == NULL)
        return False;
    amazed->file_ref = my_tabdup(amazed->file);
    del_comments(amazed->file);
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
    if (amazed->file_ref != NULL)
        free_word_array(amazed->file_ref);
    if (amazed->tab_robot != NULL) {
        for (int i = 0; amazed->tab_robot[i] != NULL; i++)
            free(amazed->tab_robot[i]);
        free(amazed->tab_robot);
    }
    if (amazed->room != NULL)
        free_linked_room(amazed->room);
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
