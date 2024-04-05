/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** file management
** file
*/

#include "../include/amazed.h"

static void add_line_in_tab(amazed_t *amazed, char **tmp, char *line)
{
    free_word_array(amazed->file);
    amazed->file = malloc(sizeof(char *) * (my_strlen_array(tmp) + 2));
    for (int i = 0; i < my_strlen_array(tmp); i++)
        amazed->file[i] = my_strdup(tmp[i]);
    amazed->file[my_strlen_array(tmp)] = my_strdup(line);
    amazed->file[my_strlen_array(tmp) + 1] = NULL;
}

static int get_ind_comment(char *line)
{
    int ind = 0;

    for (int i = 0; i < my_strlen(line); i++) {
        if (line[i] != ' ' && line[i] != '\t' && line[i] != '#')
            ind = i;
        if (line[i] == '#')
            return ind;
    }
    return -1;
}

static char *get_start_end_flags(char *line)
{
    if (my_strncmp(line, "##start", 7) == 0) {
        free(line);
        return my_strdup("##start");
    }
    if (my_strncmp(line, "##end", 5) == 0) {
        free(line);
        return my_strdup("##end");
    }
    return NULL;
}

char *del_comments(char *line)
{
    int ind;
    char *tmp = get_start_end_flags(line);

    if (tmp != NULL)
        return tmp;
    ind = get_ind_comment(line);
    if (ind == 0) {
        free(line);
        return NULL;
    }
    if (ind != -1 && ind != 0) {
        tmp = parse_str(line, 0, ind + 1);
        free(line);
        return tmp;
    }
    tmp = my_strdup(line);
    free(line);
    return tmp;
}

static char *edit_line(char *line)
{
    char *ans;
    char **tmp = separate_words(line, " \t\n");

    if (tmp == NULL) {
        free(line);
        return NULL;
    }
    free_word_array(tmp);
    ans = del_comments(line);
    if (ans == NULL)
        return my_strdup(" ");
    if (!is_flag(ans) && !is_nb_robot(ans) && !is_room(ans) && !is_tunnel(ans))
        return NULL;
    return ans;
}

void get_file(amazed_t *amazed)
{
    char **tmp = NULL;
    char *line = my_scanf();

    line = edit_line(line);
    while (line != NULL) {
        tmp = my_tabdup(amazed->file);
        add_line_in_tab(amazed, tmp, line);
        free_word_array(tmp);
        free(line);
        line = my_scanf();
        line = edit_line(line);
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
