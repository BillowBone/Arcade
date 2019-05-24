/*
** EPITECH PROJECT, 2019
** OOP - Arcade
** File description:
** Nibbler.hpp
*/

#ifndef NIBBLER_HPP_
# define NIBBLER_HPP_

# define NIBBLER_MAP_SIZE 20
# define EMPTY 0
# define OBSTACLE 1
# define SNAKE_BODY 2
# define SNAKE_HEAD 3
# define FOOD 4

# include <cstdlib>
# include <ctime>
# include "AGame.hpp"
#include "Errors.hpp"

namespace game {
    namespace nibbler {
        class Nibbler : public AGame {
            public:
                Nibbler();
                ~Nibbler();
                void loadRes();
                void initMap();
                void moveUp();
                void moveRight();
                void moveLeft();
                void moveDown();
                void generateFood(int nbFood);
                void moveSnake(int forward);
            protected:
                std::vector<std::pair<int, int>> _snake;
            private:
                bool _move;
        };
    }
}

#endif /* !NIBBLER_HPP_ */
