/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** file management
** file
*/

#include "../include/amazed.h"

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

static bool check_start_end_flags(char **tab, int i)
{
    char *tmp;

    if (my_strncmp(tab[i], "##start", 7) == 0) {
        tmp = parse_str(tab[i], 0, 7);
        free(tab[i]);
        tab[i] = my_strdup(tmp);
        free(tmp);
        return True;
    }
    if (my_strncmp(tab[i], "##end", 5) == 0) {
        tmp = parse_str(tab[i], 0, 5);
        free(tab[i]);
        tab[i] = my_strdup(tmp);
        free(tmp);
        return True;
    }
    return False;
}

static int get_ind_comment(char *line)
{
    for (int i = 0; i < my_strlen(line); i++)
        if (line[i] == '#')
            return i;
    return -1;
}

void del_comments(char **tab)
{
    int ind;
    char *line_tmp;

    for (int i = 0; i < my_strlen_array(tab); i++) {
        if (check_start_end_flags(tab, i))
            continue;
        ind = get_ind_comment(tab[i]);
        if (ind == 0) {
            backward_each_line(tab, i);
            i--;
        }
        if (ind != -1 && ind != 0) {
            line_tmp = parse_str(tab[i], 0, ind);
            free(tab[i]);
            tab[i] = my_strdup(line_tmp);
            free(line_tmp);
        }
    }
}

bool multiple_flags(char **tab)
{
    int count_start = 0;
    int count_end = 0;

    for (int i = 0; i < my_strlen_array(tab); i++) {
        if (my_strcmp(tab[i], "##start") == 0) {
            count_start++;
            continue;
        }
        if (my_strcmp(tab[i], "##end") == 0) {
            count_end++;
            continue;
        }
    }
    if (count_start != 1 || count_end != 1)
        return True;
    return False;
}
