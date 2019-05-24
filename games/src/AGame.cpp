/*
11;rgb:0000/0000/0000** EPITECH PROJECT, 2019
** OOP - Arcade
** File description:
** AGame.cpp
*/

#include "AGame.hpp"

namespace game {
    AGame::AGame()
    {
        this->_score = 0;
        this->_automatic = false;
    }

    AGame::~AGame()
    {
    }

    int AGame::getScore() const
    {
        return (this->_score);
    }

    std::vector<std::vector<int>> AGame::getMap() const
    {
        return (_map);
    }

    std::vector<std::string> AGame::getAsciiRes() const
    {
        return (_asciiRes);
    }

    std::vector<std::string> AGame::getTextrRes() const
    {
        return (_textrRes);
    }

    std::vector<std::string> AGame::getColorRes() const
    {
        return (_colorRes);
    }

    void AGame::automaticMove()
    {
        this->_automatic = true;
        if (this->_direction == UP)
            this->moveUp();
        else if (this->_direction == RIGHT)
            this->moveRight();
        else if (this->_direction == DOWN)
            this->moveDown();
        else
            this->moveLeft();
        this->_automatic = false;
    }

    bool AGame::isGameOver() const
    {
        return (this->_gameOver);
    }
}
