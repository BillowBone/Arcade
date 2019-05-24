/*
** EPITECH PROJECT, 2019
** OOP - Arcade
** File description:
** core.hpp
*/

#ifndef CORE_HPP_
# define CORE_HPP_

# define SUCCESS 0
# define ERROR 84
# define FPS 32
# define LIBS "./lib/"
# define GAMES "./games/"

#include <dlfcn.h>
#include <unistd.h>
#include <ctime>
#include <cstring>
#include <memory>
#include "Errors.hpp"
#include "Parser.hpp"
#include "IGraphic.hpp"
#include "IGame.hpp"

class Core {
    public:
        Core(int ac, char **av);
        ~Core();
    private:
        void checkArgs(int ac, char **av);
        void helper() const;
        void play();
        void displayGame() const;
        bool coreEvents();
        void myExit(int nb);
        void changeGraphic(int mode);
        void changeGame(int mode);
        void updateGraphicIdx(const std::string &lib);
        graphic::IGraphic *openGraphLib(const std::string &path);
        game::IGame *openGameLib(const std::string &path);
    private:
        Parser *_parser;
        graphic::IGraphic *_graphic;
        game::IGame *_game;
        void *_graphicHdlr;
        void *_gameHdlr;
        std::vector<std::string> _graphicTab;
        std::vector<std::string> _gameTab;
        int _graphicIdx = 0;
        int _gameIdx = 0;
};

#endif /* !CORE_HPP_ */
