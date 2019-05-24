/*
** EPITECH PROJECT, 2019
** OOP - Arcade
** File description:
** AGraphic.hpp
*/

#ifndef AGRAPHIC_HPP_
# define AGRAPHIC_HPP_

#include "IGraphic.hpp"

namespace graphic {
    class AGraphic : public IGraphic {
        public:
            AGraphic();
            ~AGraphic();
            pEvent_t getEvent() const;
            int getKey() const;
            virtual void setRes(std::vector<std::string> textrRes, std::vector<std::string> asciiRes, std::vector<std::string> colorRes) = 0;
            virtual gameAction_t getGameAction() const;
            virtual void init() = 0;
            virtual void stop() = 0;
            virtual void display(int nb) = 0;
            virtual void displayBox(std::vector<std::string> &tab, int pos) = 0;
            virtual void displayMenu(std::vector<std::vector<std::string>> &tab) = 0;
            virtual void readKey() = 0;
            virtual void clearScreen() = 0;
        protected:
            std::vector<std::string> _res;
            pEvent_t _pEvent;
            int _key;
    };
}

#endif /* !AGRAPHIC_HPP_ */
