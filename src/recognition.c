/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** recognize things
** recognition
*/

#include "../include/amazed.h"

bool is_flag(char *str)
{
    if (my_strcmp(str, "##start") == 0 || my_strcmp(str, "##end") == 0)
        return true;
    return false;
}

bool is_nb_robot(char *str)
{
    char **tmp;

    if (str == NULL)
        return false;
    tmp = separate_words_on_spaces(str);
    if (tmp == NULL || my_strlen_array(tmp) != 1) {
        free_word_array(tmp);
        return false;
    }
    free_word_array(tmp);
    if (my_str_isnum(str))
        return true;
    return false;
}

bool is_room(char *str)
{
    char **tab;

    if (str == NULL)
        return false;
    tab = separate_words_on_spaces(str);
    if (tab == NULL || my_strlen_array(tab) != 3 || !my_str_isnum(tab[1]) ||
    !my_str_isnum(tab[2])) {
        free_word_array(tab);
        return false;
    }
    free_word_array(tab);
    return true;
}

bool is_tunnel(char *str)
{
    char **tmp;

    if (str == NULL)
        return false;
    tmp = separate_words_on_spaces(str);
    if (my_strlen_array(tmp) != 1) {
        free_word_array(tmp);
        return false;
    }
    free_word_array(tmp);
    tmp = separate_words(str, "-");
    if (my_strlen_array(tmp) != 2) {
        free_word_array(tmp);
        return false;
    }
    free_word_array(tmp);
    for (int i = 0; i < my_strlen(str); i++)
        if (str[i] == '-')
            return true;
    return false;
}
