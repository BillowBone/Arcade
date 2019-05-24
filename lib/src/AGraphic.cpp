/*
** EPITECH PROJECT, 2019
** OOP - Arcade
** File description:
** AGraphic
*/

#include "AGraphic.hpp"
#include <ncurses.h>

namespace graphic {
    AGraphic::AGraphic()
    {
    }

    AGraphic::~AGraphic()
    {
    }

    pEvent_t AGraphic::getEvent() const
    {
        return (this->_pEvent);
    }

    int AGraphic::getKey() const
    {
        return (this->_key);
    }

    gameAction_t AGraphic::getGameAction() const
    {
        if (this->_pEvent == KEYP) {
            if (this->_key == KZ)
                return (UP);
            else if (this->_key == KS)
                return (DOWN);
            else if (this->_key == KD)
                return (RIGHT);
            else if (this->_key == KQ)
                return (LEFT);
        }
        return (EMPTY);
    }
}
