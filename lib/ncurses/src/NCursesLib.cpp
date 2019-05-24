/*
** EPITECH PROJECT, 2019
** OOP - Arcade
** File description:
** NCursesLib
*/

#include "NCursesLib.hpp"

namespace graphic {
    namespace ncurses {
        NCursesLib::NCursesLib()
        {
        }

        NCursesLib::~NCursesLib()
        {
        }

        void NCursesLib::setRes(std::vector<std::string> textrRes, std::vector<std::string> asciiRes, std::vector<std::string> colorRes)
        {
            _res = asciiRes;
        }

        void NCursesLib::init()
        {
            initscr();
        }

        void NCursesLib::stop()
        {
            endwin();
        }

        void NCursesLib::display(int nb)
        {
            if (nb == -1)
                printw("\n");
            else
                printw(_res[nb].c_str());
        }

        void NCursesLib::displayBox(std::vector<std::string> &tab, int pos)
        {
            printw("/******************************\\\n");
            for (int i = 0; i < 5; i++) {
                printw("|");
                if (i > 1 && (i - 2) < tab.size()) {
                    printw("     ");
                    printw(tab[i - 2].c_str());
                    for (int j = 0; j < (25 - tab[i - 2].length()); j++) {
                        printw(" ");
                    }
                } else if (i == 0 && pos == 0) {
                    printw("             Games            ");
                } else if (i == 0 && pos == 1) {
                    printw("            Graphics          ");
                } else if (i == 0 && pos == 2) {
                    printw("             Scores           ");
                } else if (i == 0 && pos == 3) {
                    printw("            Username          ");
                } else {
                    printw("                              ");
                }
                printw("|\n");
            }
            printw("\\******************************/\n");
        }

        void NCursesLib::displayMenu(std::vector<std::vector<std::string>> &tab)
        {
            for (int i = 0; i < tab.size(); i++) {
                this->displayBox(tab[i], i);
            }
        }

        void NCursesLib::readKey()
        {
            int key = 0;

            this->_key = 0;
            this->_pEvent = NONE;
            timeout(500);
            key = getch();
            if (key > 64) {
                this->_pEvent = KEYP;
                switch (key) {
                case 'a':
                    this->_key = KA;
                    break;
                case 'b':
                    this->_key = KB;
                    break;
                case 'c':
                    this->_key = KC;
                    break;
                case 'd':
                    this->_key = KD;
                    break;
                case 'e':
                    this->_key = KE;
                    break;
                case 'f':
                    this->_key = KF;
                    break;
                case 'g':
                    this->_key = KG;
                    break;
                case 'h':
                    this->_key = KH;
                    break;
                case 'i':
                    this->_key = KI;
                    break;
                case 'j':
                    this->_key = KJ;
                    break;
                case 'k':
                    this->_key = KK;
                    break;
                case 'l':
                    this->_key = KL;
                    break;
                case 'm':
                    this->_key = KM;
                    break;
                case 'n':
                    this->_key = KN;
                    break;
                case 'o':
                    this->_key = KO;
                    break;
                case 'p':
                    this->_key = KP;
                    break;
                case 'q':
                    this->_key = KQ;
                    break;
                case 'r':
                    this->_key = KR;
                    break;
                case 's':
                    this->_key = KS;
                    break;
                case 't':
                    this->_key = KT;
                    break;
                case 'u':
                    this->_key = KU;
                    break;
                case 'v':
                    this->_key = KV;
                    break;
                case 'w':
                    this->_key = KW;
                    break;
                case 'x':
                    this->_key = KX;
                    break;
                case 'y':
                    this->_key = KY;
                    break;
                case 'z':
                    this->_key = KZ;
                    break;
                case ' ':
                    this->_key = KSPACE;
                    break;
                case KEY_DOWN:
                    this->_key = KDOWN;
                    break;
                case KEY_UP:
                    this->_key = KUP;
                    break;
                case KEY_LEFT:
                    this->_key = KLEFT;
                    break;
                case KEY_RIGHT:
                    this->_key = KRIGHT;
                    break;
                }
            }
        }

        void NCursesLib::clearScreen()
        {
            clear();
        }
    }
}

extern "C" {
    graphic::IGraphic *createIGraphic(void) {
        graphic::IGraphic *tmp(new graphic::ncurses::NCursesLib());

        return (tmp);
    }
}
