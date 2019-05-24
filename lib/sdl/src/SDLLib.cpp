/*
** EPITECH PROJECT, 2019
** OOP - Arcade
** File description:
** SDLLIB
*/

#include "SDLLib.hpp"
#include <fstream>
#include <sstream>


namespace graphic {
    namespace sdl {
        SDLLib::SDLLib()
        {
            if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
                throw SDLInitError("Failed loading SDL", "SDL Lib");
            }
        }

        void SDLLib::init()
        {
            this->_window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_UNDEFINED,
                                                           SDL_WINDOWPOS_UNDEFINED,
                                                           SCR_WIDTH + 40,
                                                           SCR_HEIGHT,
                                                           0);
            if (!this->_window)
                throw WindowCreationError("Failed to create a window", "SDL Lib");
            this->_renderer = SDL_CreateRenderer(this->_window, -1, 0);
            if (!this->_renderer)
                throw RendererCreationError("Failed to create a renderer", "SDL Lib");
        }

        void SDLLib::stop()
        {
            SDL_DestroyWindow(this->_window);
        }

        void SDLLib::display(int nb)
        {
            t_print *tmp = nullptr;
            if (nb == -1) {
                this->_pPos.first = 0;
                this->_pPos.second = this->_pPos.second + T_SIZE;
            } else {
                _printables[nb]->rect.x = this->_pPos.first;
                _printables[nb]->rect.y = this->_pPos.second;
                this->_pPos.first += T_SIZE;
                SDL_SetRenderDrawColor(this->_renderer, _printables[nb]->color[0], _printables[nb]->color[1], _printables[nb]->color[2], 0);
                SDL_RenderFillRect(this->_renderer, &_printables[nb]->rect);
                SDL_RenderPresent(this->_renderer);
            }
        }

        void SDLLib::displayBox(std::vector<std::string> &tab, int pos)
        {
        }

        void SDLLib::displayMenu(std::vector<std::vector<std::string>> &tab)
        {
        }

        void SDLLib::setRes(std::vector<std::string> textrRes, std::vector<std::string> asciiRes, std::vector<std::string> colorRes)
        {
            std::vector<std::string> splited;
            std::string str;
            t_print *tmp;

            _res = colorRes;
            _printables.reserve(_res.size());
            for (int i = 0; i < _res.size(); i++) {
                tmp = new t_print();

                std::stringstream temp(_res[i]);
                if (!temp)
                    throw ResourceNotFoundError("Failed to load one of the resources needed to display the game", "SDL Lib");
                splited.reserve(3);
                while(std::getline(temp, str, '/'))
                    splited.push_back(str);

                tmp->color[0] = atoi(splited[0].c_str());
                tmp->color[1] = atoi(splited[1].c_str());
                tmp->color[2] = atoi(splited[2].c_str());

                _printables.push_back(tmp);
                splited.clear();
                temp.clear();
            }
        }

        void SDLLib::readKey()
        {
            this->_key = 0;
            this->_pEvent = NONE;

            while (SDL_PollEvent(&this->_event)) {
                if (this->_event.type == SDL_WINDOWEVENT) {
                    if (this->_event.window.event == SDL_WINDOWEVENT_CLOSE) {
                        this->stop();
                        this->_pEvent = KEYP;
                        this->_key = KN;
                    }
                    return;
                }
                if (this->_event.type == SDL_KEYUP) {
                    switch (this->_event.key.keysym.sym) {
                        case SDLK_a:
                            this->_pEvent = KEYP;
                            this->_key = KA;
                            break;
                        case SDLK_b:
                            this->_pEvent = KEYP;
                            this->_key = KB;
                            break;
                        case SDLK_c:
                            this->_pEvent = KEYP;
                            this->_key = KC;
                            break;
                        case SDLK_d:
                            this->_pEvent = KEYP;
                            this->_key = KD;
                            break;
                        case SDLK_e:
                            this->_pEvent = KEYP;
                            this->_key = KE;
                            break;
                        case SDLK_f:
                            this->_pEvent = KEYP;
                            this->_key = KF;
                            break;
                        case SDLK_g:
                            this->_pEvent = KEYP;
                            this->_key = KG;
                            break;
                        case SDLK_h:
                            this->_pEvent = KEYP;
                            this->_key = KH;
                            break;
                        case SDLK_i:
                            this->_pEvent = KEYP;
                            this->_key = KI;
                            break;
                        case SDLK_j:
                            this->_pEvent = KEYP;
                            this->_key = KJ;
                            break;
                        case SDLK_k:
                            this->_pEvent = KEYP;
                            this->_key = KK;
                            break;
                        case SDLK_l:
                            this->_pEvent = KEYP;
                            this->_key = KL;
                            break;
                        case SDLK_m:
                            this->_pEvent = KEYP;
                            this->_key = KM;
                            break;
                        case SDLK_n:
                            this->_pEvent = KEYP;
                            this->_key = KN;
                            break;
                        case SDLK_o:
                            this->_pEvent = KEYP;
                            this->_key = KO;
                            break;
                        case SDLK_p:
                            this->_pEvent = KEYP;
                            this->_key = KP;
                            break;
                        case SDLK_q:
                            this->_pEvent = KEYP;
                            this->_key = KQ;
                            break;
                        case SDLK_r:
                            this->_pEvent = KEYP;
                            this->_key = KR;
                            break;
                        case SDLK_s:
                            this->_pEvent = KEYP;
                            this->_key = KS;
                            break;
                        case SDLK_t:
                            this->_pEvent = KEYP;
                            this->_key = KT;
                            break;
                        case SDLK_u:
                            this->_pEvent = KEYP;
                            this->_key = KU;
                            break;
                        case SDLK_v:
                            this->_pEvent = KEYP;
                            this->_key = KV;
                            break;
                        case SDLK_w:
                            this->_pEvent = KEYP;
                            this->_key = KW;
                            break;
                        case SDLK_x:
                            this->_pEvent = KEYP;
                            this->_key = KX;
                            break;
                        case SDLK_y:
                            this->_pEvent = KEYP;
                            this->_key = KY;
                            break;
                        case SDLK_z:
                            this->_pEvent = KEYP;
                            this->_key = KZ;
                            break;
                        case SDLK_SPACE:
                            this->_pEvent = KEYP;
                            this->_key = KSPACE;
                            break;
                        case SDLK_DOWN:
                            this->_pEvent = KEYP;
                            this->_key = KDOWN;
                            break;
                        case SDLK_UP:
                            this->_pEvent = KEYP;
                            this->_key = KUP;
                            break;
                        case SDLK_LEFT:
                            this->_pEvent = KEYP;
                            this->_key = KLEFT;
                            break;
                        case SDLK_RIGHT:
                            this->_pEvent = KEYP;
                            this->_key = KRIGHT;
                            break;
                    }
                }
            }
        }

        void SDLLib::clearScreen()
        {
            this->_pPos.first = 0;
            this->_pPos.second = 0;
        }

        SDLLib::~SDLLib()
        {
            SDL_Quit();
        }
    }
}

extern "C" {
    graphic::IGraphic* createIGraphic(void)
    {
        return (new graphic::sdl::SDLLib);
    }
}
