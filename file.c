/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** file management
** file
*/

#include "include/my.h"
#include "include/amazed.h"

void get_file(amazed_t *amazed)
{
    char *line = "";
    char **tmp = NULL;

    amazed->file = NULL;
    while (line != NULL) {
        line = my_scanf();
        tmp = my_tabdup(amazed->file);
        free_word_array(amazed->file);
        amazed->file = malloc(sizeof(char *) * (my_strlen_array(tmp) + 2));
        for (int i = 0; i < my_strlen_array(tmp); i++)
            amazed->file[i] = my_strdup(tmp[i]);
        amazed->file[my_strlen_array(tmp)] = my_strdup(line);
        amazed->file[my_strlen_array(tmp) + 1] = NULL;
        free_word_array(tmp);
        free(line);
    }
}
