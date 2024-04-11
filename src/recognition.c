/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** recognize things
** recognition
*/

#include "../include/amazed.h"

int is_flag(char *str)
{
    if (my_strcmp(str, "##start") == 0 || my_strcmp(str, "##end") == 0)
        return 1;
    return 0;
}

int is_nb_robot(char *str)
{
    char **tmp;

    if (str == NULL)
        return 0;
    tmp = separate_words_on_spaces(str);
    if (tmp == NULL || my_strlen_array(tmp) != 1) {
        free_word_array(tmp);
        return 0;
    }
    free_word_array(tmp);
    if (my_str_isnum(str))
        return 1;
    return 0;
}

int is_room(char *str)
{
    char **tab;

    if (str == NULL)
        return 0;
    tab = separate_words_on_spaces(str);
    if (tab == NULL || my_strlen_array(tab) != 3 || !my_str_isnum(tab[1]) ||
    !my_str_isnum(tab[2])) {
        free_word_array(tab);
        return 0;
    }
    free_word_array(tab);
    return 1;
}

int is_tunnel(char *str)
{
    char **tmp;

    if (str == NULL)
        return 0;
    tmp = separate_words_on_spaces(str);
    if (my_strlen_array(tmp) != 1) {
        free_word_array(tmp);
        return 0;
    }
    free_word_array(tmp);
    tmp = separate_words(str, "-");
    if (my_strlen_array(tmp) != 2) {
        free_word_array(tmp);
        return 0;
    }
    free_word_array(tmp);
    for (int i = 0; i < my_strlen(str); i++)
        if (str[i] == '-')
            return 1;
    return 0;
}
