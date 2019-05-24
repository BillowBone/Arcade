 /*
** EPITECH PROJECT, 2019
** OOP - Arcade
** File description:
** SFMLlib.hpp
*/

#ifndef SFMLLIB_HPP_
# define SFMLLIB_HPP_

# define T_SIZE 40
# define T_NWIDTH 20
# define T_NHEIGHT 20
# define SCR_WIDTH (T_SIZE * T_NWIDTH)
# define SCR_HEIGHT (T_SIZE * T_NHEIGHT)

# include <SFML/Graphics.hpp>
# include "AGraphic.hpp"
#include "Errors.hpp"

namespace graphic {
    namespace sfml {
        typedef struct s_print {
            sf::Sprite sprt;
            sf::Texture textr;
            s_print()
                {
                }
            ~s_print()
                {
                }
        } t_print;

        class SFMLLib : public AGraphic {
        public:
            SFMLLib();
            ~SFMLLib();
            void setRes(std::vector<std::string> textrRes, std::vector<std::string> asciiRes, std::vector<std::string> colorRes);
            void init();
            void stop();
            void display(int nb);
            void readKey();
            void clearScreen();
        private:
            sf::RenderWindow *_window;
            sf::Event _event;
            sf::Clock clock;
            std::vector<t_print *> _printables;
            std::pair<int, int> _pPos = {0, 0};
        };
    }
}

#endif /* !SFMLLIB_HPP_ */
