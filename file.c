/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** file management
** file
*/

#include "include/amazed.h"

void get_file(amazed_t *amazed)
{
    char *line = "";
    char **tmp = NULL;

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

static void backward_each_line(char **tab, int i)
{
    while (tab[i + 1] != NULL) {
        free(tab[i]);
        tab[i] = my_strdup(tab[i + 1]);
        i++;
    }
    free(tab[i]);
    tab[i] = NULL;
    free(tab[i + 1]);
}

void del_blank_lines(char **tab)
{
    char **tmp;

    for (int i = 0; i < my_strlen_array(tab); i++) {
        tmp = separate_words(tab[i], " \t\n");
        if (tmp == NULL) {
            backward_each_line(tab, i);
            i--;
        }
        free_word_array(tmp);
    }
}
