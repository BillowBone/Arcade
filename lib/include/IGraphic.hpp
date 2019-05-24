/*
** EPITECH PROJECT, 2019
** OOP - Arcade
** File description:
** IGraphic.hpp
*/

#ifndef IGRAPHIC_HPP_
# define IGRAPHIC_HPP_

# define KA 0
# define KB 1
# define KC 2
# define KD 3
# define KE 4
# define KF 5
# define KG 6
# define KH 7
# define KI 8
# define KJ 9
# define KK 10
# define KL 11
# define KM 12
# define KN 13
# define KO 14
# define KP 15
# define KQ 16
# define KR 17
# define KS 18
# define KT 19
# define KU 20
# define KV 21
# define KW 22
# define KX 23
# define KY 24
# define KZ 25
# define KSPACE 26
# define KUP 27
# define KDOWN 28
# define KLEFT 29
# define KRIGHT 30

# include <vector>
# include <utility>
# include <iostream>

typedef enum pEvent_e {
    NONE,
    KEYP,
    KEYR,
    CLICR,
    CLICL
} pEvent_t;

typedef enum gameAction_e {
    UP,
    RIGHT,
    DOWN,
    LEFT,
    EMPTY
} gameAction_t;

namespace graphic {
    class IGraphic {
        public:
            virtual ~IGraphic() = default;
            virtual pEvent_t getEvent() const = 0;
            virtual int getKey() const = 0;
            virtual void setRes(std::vector<std::string> textrRes, std::vector<std::string> asciiRes, std::vector<std::string> colorRes) = 0;
            virtual gameAction_t getGameAction() const = 0;
            virtual void init() = 0;
            virtual void stop() = 0;
            virtual void display(int nb) = 0;
            virtual void displayBox(std::vector<std::string> &tab, int pos) = 0;
            virtual void displayMenu(std::vector<std::vector<std::string>> &tab) = 0;
            virtual void readKey() = 0;
            virtual void clearScreen() = 0;
    };
}

#endif /* !IGRAPHIC_HPP_ */
