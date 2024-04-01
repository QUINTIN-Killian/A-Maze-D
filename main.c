/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** main file
** main
*/

#include "include/my.h"
#include "include/amazed.h"

int main(void)
{
    amazed_t amazed;

    get_file(&amazed);
    print_word_array(amazed.file);
    free_word_array(amazed.file);
    return 0;
}
