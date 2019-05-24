/*
** EPITECH PROJECT, 2019
** OOP - Arcade
** File description:
** SFMLLib
*/

#include "SFMLLib.hpp"

namespace graphic {
    namespace sfml{
        SFMLLib::SFMLLib()
        {

        }

        SFMLLib::~SFMLLib()
        {

        }

        void SFMLLib::setRes(std::vector<std::string> textrRes, std::vector<std::string> asciiRes, std::vector<std::string> colorRes)
        {
            t_print *tmp;

            _res = textrRes;
            _printables.reserve(_res.size());
            for (int i = 0; i < _res.size(); i++) {
                tmp = new t_print();
                if (tmp->textr.loadFromFile(_res[i]) == false)
                    throw ResourceNotFoundError("Failed to load one of the resources needed to display the game", "SFML Lib");
                tmp->sprt.setTexture(tmp->textr);
                _printables.push_back(tmp);
            }
        }

        void SFMLLib::init()
        {
            this->_window = new sf::RenderWindow(sf::VideoMode(SCR_WIDTH, SCR_HEIGHT), "SFML window");
        }

        void SFMLLib::stop()
        {
            this->_window->close();
        }

        void SFMLLib::display(int nb)
        {
            t_print *tmp = nullptr;

            if (nb == -1) {
                this->_pPos.first = 0;
                this->_pPos.second = this->_pPos.second + T_SIZE;
            }
            if (this->_pPos.second >= SCR_HEIGHT) {
                this->_window->display();
            }
            if (nb != -1) {
                _printables[nb]->sprt.setPosition(this->_pPos.first, this->_pPos.second);
                this->_window->draw(_printables[nb]->sprt);
                this->_pPos.first = this->_pPos.first + T_SIZE;
            }
        }

        void SFMLLib::readKey()
        {
            this->_key = 0;
            this->_pEvent = NONE;
            while (this->_window->pollEvent(this->_event)) {
                if (this->_event.type == sf::Event::Closed) {
                    _window->close();
                    this->_pEvent = KEYP;
                    this->_key = KN;
                }
                if (this->_event.type == sf::Event::KeyPressed) {
                    this->_pEvent = KEYP;
                    switch (this->_event.key.code) {
                    case sf::Keyboard::A:
                        this->_key = KA;
                        break;
                    case sf::Keyboard::B:
                        this->_key = KB;
                        break;
                    case sf::Keyboard::C:
                        this->_key = KC;
                        break;
                    case sf::Keyboard::D:
                        this->_key = KD;
                        break;
                    case sf::Keyboard::E:
                        this->_key = KE;
                        break;
                    case sf::Keyboard::F:
                        this->_key = KF;
                        break;
                    case sf::Keyboard::G:
                        this->_key = KG;
                        break;
                    case sf::Keyboard::H:
                        this->_key = KH;
                        break;
                    case sf::Keyboard::I:
                        this->_key = KI;
                        break;
                    case sf::Keyboard::J:
                        this->_key = KJ;
                        break;
                    case sf::Keyboard::K:
                        this->_key = KK;
                        break;
                    case sf::Keyboard::L:
                        this->_key = KL;
                        break;
                    case sf::Keyboard::M:
                        this->_key = KM;
                        break;
                    case sf::Keyboard::N:
                        this->_key = KN;
                        break;
                    case sf::Keyboard::O:
                        this->_key = KO;
                        break;
                    case sf::Keyboard::P:
                        this->_key = KP;
                        break;
                    case sf::Keyboard::Q:
                        this->_key = KQ;
                        break;
                    case sf::Keyboard::R:
                        this->_key = KR;
                        break;
                    case (sf::Keyboard::S):
                        this->_key = KS;
                        break;
                    case sf::Keyboard::T:
                        this->_key = KT;
                        break;
                    case sf::Keyboard::U:
                        this->_key = KU;
                        break;
                    case sf::Keyboard::V:
                        this->_key = KV;
                        break;
                    case sf::Keyboard::W:
                        this->_key = KW;
                        break;
                    case sf::Keyboard::X:
                        this->_key = KX;
                        break;
                    case sf::Keyboard::Y:
                        this->_key = KY;
                        break;
                    case sf::Keyboard::Z:
                        this->_key = KZ;
                        break;
                    case sf::Keyboard::Space:
                        this->_key = KSPACE;
                        break;
                    case sf::Keyboard::Down:
                        this->_key = KDOWN;
                        break;
                    case sf::Keyboard::Up:
                        this->_key = KUP;
                        break;
                    case sf::Keyboard::Left:
                        this->_key = KLEFT;
                        break;
                    case sf::Keyboard::Right:
                        this->_key = KRIGHT;
                        break;
                    }
                }
            }
        }

        void SFMLLib::clearScreen()
        {
            this->_window->clear();
            this->_pPos.first = 0;
            this->_pPos.second = 0;
        }
    }
}

extern "C" {
    graphic::IGraphic* createIGraphic(void)
    {
        return (new graphic::sfml::SFMLLib);
    }
}
