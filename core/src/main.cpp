/*
** EPITECH PROJECT, 2019
** OOP - Arcade
** File description:
** main
*/

#include "Core.hpp"

int main(int ac, char **av)
{
    try {
        Core *core = new Core(ac, av);
    } catch (const ArcadeError &e) {
        return (84);
    }

    return (0);
}
