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

typedef struct robot_s {
    int robot_id;
    int current_room;
} robot_t;

typedef struct room_s {
    int occupied;
    int cost;
    int id;
    char *name;
    int x;
    int y;
    int *close_rooms;
} room_t;

typedef struct amazed_s {
    int nb_robot;
    int nb_room;
    int nb_tunnel;
    char **file;
    int id_start;
    int id_end;
    room_t **tab_room;
    robot_t **tab_robot;
} amazed_t;

//my_scanf :
char *my_scanf(void);

//file.c :
void get_file(amazed_t *amazed);
void del_blank_lines(char **tab);

//getter.c :
int get_nb_robot(char **tab);
int get_nb_room(char **tab);
int get_nb_tunnel(char **tab);
room_t *get_room_by_id(amazed_t *amazed, int id);

//error_handling.c :
int multiple_flags(char **tab);
int check_room_after_flag(char **tab);
int check_correct_tunnel(amazed_t *amazed);
int is_unique_room(room_t **tab_room);

//draw_rooms.c :
int draw_rooms(amazed_t *amazed);

//draw_robots.c :
int draw_robots(amazed_t *amazed);

//recognition.c :
int is_flag(char *str);
int is_nb_robot(char *str);
int is_room(char *str);
int is_tunnel(char *str);

//end.c :
void print_end(amazed_t *amazed);
void print_error_file(amazed_t *amazed);
void print_robots_moves(int id, char *name, int *print_space);

//room.c :
room_t *create_room(int id, char *name, int x, int y);
void create_tab_room(amazed_t *amazed);
void add_close_rooms(amazed_t *amazed);

//robot.c :
robot_t *create_robot(int id, int room_id);
void create_tab_robot(amazed_t *amazed);

//compute_cost.c :
int compute_cost(amazed_t *amazed);

//movements.c :
void move_robots(amazed_t *amazed);

#endif
