/*
** EPITECH PROJECT, 2019
** OOP - Arcade
** File description:
** NCurseslib.hpp
*/

#ifndef NCURSELIB_HPP_
# define NCURSELIB_HPP_

#include <ncurses.h>
#include <unistd.h>
#include <memory>
#include <string>
#include "AGraphic.hpp"

namespace graphic {
    namespace ncurses {
        class NCursesLib : public AGraphic {
            public:
                NCursesLib();
                ~NCursesLib();
                void setRes(std::vector<std::string> textrRes, std::vector<std::string> asciiRes, std::vector<std::string> colorRes);
                void init();
                void stop();
                void display(int nb);
                void displayBox(std::vector<std::string> &tab, int pos);
                void displayMenu(std::vector<std::vector<std::string>> &tab);
                void readKey();
                void clearScreen();
        };
    }
}

#endif /* !NCURSELIB_HPP_ */
