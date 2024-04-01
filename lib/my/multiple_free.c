/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** free multiple pointers
** mini_printf
*/

#include "my.h"

void multiple_free(int nb_free, ...)
{
    va_list args;
    void *ptr;

    va_start(args, nb_free);
    for (int i = 0; i < nb_free; i++) {
        ptr = va_arg(args, void *);
        if (ptr != NULL) {
            free(ptr);
        }
    }
    va_end(args);
}
