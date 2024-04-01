/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** amazed header
** amazed
*/

#ifndef AMAZED_H_
    #define AMAZED_H_
    #include "my.h"

typedef enum boolean_t {
    False,
    True
} boolean;

typedef struct robot_s {
    int robot_id;
    int current_room;
} robot_t;

typedef struct linked_room_s {
    char *name;
    int x;
    int y;
    struct linked_room_s *next;
    char **close_rooms;
} linked_room_t;

typedef struct amazed_s {
    int nb_robot;
    char **file;
    char **file_ref;
    robot_t **tab_robot;
    linked_room_t *room;
} amazed_t;

//my_scanf :
char *my_scanf(void);

//file.c :
void get_file(amazed_t *amazed);
void del_blank_lines(char **tab);

//functions.c :
void free_linked_room(linked_room_t *node);
int draw_rooms(amazed_t *amazed);
int draw_robots(amazed_t *amazed);

#endif
