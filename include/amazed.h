/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** amazed header
** amazed
*/

#ifndef AMAZED_H_
    #define AMAZED_H_

typedef enum boolean {
    False,
    True
} bool;

typedef struct robot_s {
    int current_room;
} robot_t;

typedef struct linked_room_s {
    int id;
    struct linked_room_s *next;
    int *close_rooms;
} linked_room_t;

typedef struct amazed_s {
    int nb_robot;
    robot_t **tab_robot;
    linked_room_t *room;
} amazed_t;

#endif
