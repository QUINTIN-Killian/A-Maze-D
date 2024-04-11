##
## EPITECH PROJECT, 2023
## generator
## File description:
## maze generator for the A-Maze-D project
## generator
##

import sys
from random import randint

class Infos:
    def __init__(self):
        self.nb_robot = 3
        self.nb_room = 5
        self.nb_tunnels = 3

def help():
    print("Map generator for A-Maze-D :\n")
    print("USAGE")
    print("    -h : to get help")
    print("    -b [nbr -> type:int] : to generate 'nbr' robot (default : 3)")
    print("    -r [nbr -> type:int] : to generate 'nbr' room (default : 5)")
    print("    -t [nbr -> type:int] : to generate 'nbr' tunnels (default : 3)")
    print("\nCreated by Killian QUINTIN, Elie CHARDIN and Noé GEBERT")

def is_number(str):
    my_list = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]
    for i in range(len(str)):
        if str[i] not in my_list:
            print("Incorrect argument(s) : './<bin> -h' to get help.")
            sys.exit(84)
    return True

def generator(infos):
    file = open(f"./scripts/maze", "w")
    file.write(f"{infos.nb_robot}\n")
    file.write("##start\n")
    for i in range(infos.nb_room - 1):
        file.write(f"{i} {randint(0, 1000)} {randint(0, 1000)}\n")
    file.write('##end\n')
    file.write(f"{infos.nb_room - 1} {randint(0, 1000)} {randint(0, 1000)}\n")
    for i in range(infos.nb_tunnels):
        file.write(f"{randint(0, infos.nb_room - 1)}-{randint(0, infos.nb_room - 1)}\n")
    file.close()

if __name__ == "__main__":
    args = sys.argv[1:]
    if len(args) == 1 and args[0] == "-h":
        help()
        sys.exit(0)
    infos = Infos()
    if len(args) % 2 != 0:
        print("Incorrect number of arguments : './<bin> -h' to get help.")
        sys.exit(84)
    for i in range(0, len(args), 2):
        if i < len(args) - 1:
            if args[i] == "-b" and is_number(args[i + 1]):
                infos.nb_robot = int(args[i + 1])
            elif args[i] == "-r" and is_number(args[i + 1]):
                infos.nb_room = int(args[i + 1])
            elif args[i] == "-t" and is_number(args[i + 1]):
                infos.nb_tunnels = int(args[i + 1])
            else:
                print("Incorrect argument(s) : './<bin> -h' to get help.")
                sys.exit(84)
        else:
            print("Incorrect number of arguments : './<bin> -h' to get help.")
            sys.exit(84)
    generator(infos)
    print(f"'maze' generated successfully !")
    sys.exit(0)