/*
** EPITECH PROJECT, 2019
** OOP - Arcade
** File description:
** AGame.hpp
*/

#ifndef AGAME_HPP_
    #define AGAME_HPP_

#include "IGame.hpp"

namespace game {
    class AGame : public IGame {
    public:
        AGame();
        ~AGame();
        int getScore() const;
        std::vector<std::vector<int>> getMap() const;
        std::vector<std::string> getAsciiRes() const;
        std::vector<std::string> getTextrRes() const;
        std::vector<std::string> getColorRes() const;
        virtual void loadRes() = 0;
        virtual void moveUp() = 0;
        virtual void moveRight() = 0;
        virtual void moveLeft() = 0;
        virtual void moveDown() = 0;
        void automaticMove();
        bool isGameOver() const;
    protected:
        std::vector<std::vector<int>> _map;
        std::vector<std::string> _asciiRes;
        std::vector<std::string> _textrRes;
        std::vector<std::string> _colorRes;
        int _score;
        Direction _direction;
        bool _automatic;
        bool _gameOver;
    };
}

#endif /* !AGAME_HPP_ */
