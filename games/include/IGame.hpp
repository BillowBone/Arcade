/*
** EPITECH PROJECT, 2019
** OOP - Arcade
** File description:
** IGame.hpp
*/

#ifndef IGAME_HPP_
    #define IGAME_HPP_

#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <iostream>

namespace game {
    enum Direction {
        UP,
        RIGHT,
        DOWN,
        LEFT
    };

    class IGame {
	    public:
		    virtual ~IGame() = default;
            virtual int getScore() const = 0;
            virtual std::vector<std::vector<int>> getMap() const = 0;
            virtual std::vector<std::string> getAsciiRes() const = 0;
            virtual std::vector<std::string> getTextrRes() const = 0;
            virtual std::vector<std::string> getColorRes() const = 0;
            virtual void loadRes() = 0;
            virtual void moveUp() = 0;
            virtual void moveRight() = 0;
            virtual void moveLeft() = 0;
            virtual void moveDown() = 0;
            virtual void automaticMove() = 0;
            virtual bool isGameOver() const = 0;
    };
}

#endif /* !IGAME_HPP_ */
