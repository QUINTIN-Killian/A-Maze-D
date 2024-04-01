/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** printword array
** print_word_array
*/

#include "my.h"

void print_word_array(char **word_array)
{
    for (int i = 0; i < my_strlen_array(word_array); i++) {
        mini_printf("%s\n", word_array[i]);
    }
}
