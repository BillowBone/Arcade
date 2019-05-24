/*
** EPITECH PROJECT, 2019
** OOP - Arcade
** File description:
** Core
*/

#include "Core.hpp"

Core::Core(int ac, char **av)
{
    this->checkArgs(ac, av);
}

Core::~Core()
{
    delete this->_parser;
    delete this->_graphic;
    delete this->_game;
}

void Core::helper() const
{
    std::cout << "USAGE:" << std::endl;
    std::cout << "\t\t./arcade dlibrary" << std::endl << std::endl;
    std::cout << "DESCRIPTION:" << std::endl;
    std::cout << "\t\tdlibrary\tdynamic library to load at first" << std::endl;
}

void Core::checkArgs(int ac, char **av)
{
    if (ac != 2) {
        this->helper();
        throw BadInputArgsError("Bad input argument(s).", "Core");
    }
    this->_parser = new Parser(LIBS, GAMES);
    this->_graphicTab = this->_parser->getTabGraph();
    this->_gameTab = this->_parser->getTabGame();
    this->_graphic = this->openGraphLib(av[1]);
    if (this->_graphic == nullptr) {
        throw OpeningGraphLibError("Opening graphical lib failed.", "Core");
    }
    this->updateGraphicIdx(av[1]);
    this->_game = this->openGameLib("./games/lib_arcade_nibbler.so");
    if (this->_game == nullptr)
        throw OpeningGameLibError("Opening game lib failed.", "Core");
    this->play();
}

graphic::IGraphic *Core::openGraphLib(const std::string &path)
{
    graphic::IGraphic *(*createSym)();
    graphic::IGraphic *graphic = nullptr;

    this->_graphicHdlr = dlopen(path.c_str(), RTLD_LAZY);
    if (this->_graphicHdlr == nullptr) {
        std::cerr << dlerror() << std::endl;
        throw DlOpenFailure("dlopen() failed.", "Core");
    }
    createSym = (graphic::IGraphic *(*)())dlsym(this->_graphicHdlr, "createIGraphic");
    if (createSym == nullptr)
        throw DlSymFailure("dlsym() failed.", "Core");
    try {
        graphic = (*createSym)();
    } catch (const std::bad_alloc &e) {
        throw DlSymFailure("dlsym() failed.", "Core");
    }
    return (graphic);
}

game::IGame *Core::openGameLib(const std::string &path)
{
    game::IGame *(*createSym)();
    game::IGame *game = nullptr;

    this->_gameHdlr = dlopen(path.c_str(), RTLD_LAZY);
    if (this->_gameHdlr == nullptr) {
        std::cerr << dlerror() << std::endl;
        throw DlOpenFailure("dlopen() failed.", "Core");
    }
    createSym = (game::IGame *(*)())dlsym(this->_gameHdlr, "createIGame");
    if (createSym == nullptr)
        throw DlSymFailure("dlsym() failed.", "Core");
    try {
        game = (*createSym)();
    } catch (const std::bad_alloc &e) {
        throw DlSymFailure("dlsym() failed.", "Core");
    }
    return (game);
}

bool Core::coreEvents()
{
    if (this->_graphic->getEvent() == KEYP) {
        if (this->_graphic->getKey() == KU) {
            this->changeGraphic(-1);
            return (true);
        } else if (this->_graphic->getKey() == KP) {
            this->changeGraphic(1);
            return (true);
        } else if (this->_graphic->getKey() == KJ) {
            this->changeGame(-1);
            return (true);
        } else if (this->_graphic->getKey() == KM) {
            this->changeGame(1);
            return (true);
        } else if (this->_graphic->getKey() == KR) {
            this->changeGame(2);
            return (true);
        } else if (this->_graphic->getKey() == KN) {
            this->myExit(0);
        }
    }
    return (false);
}

void Core::myExit(int nb)
{
    this->_graphic->stop();
    exit(nb);
}

void Core::updateGraphicIdx(const std::string &lib)
{
    for (int i = 0; i < (int)this->_graphicTab.size(); i++) {
        if (lib == this->_graphicTab[i]) {
            this->_graphicIdx = i;
            return;
        }
    }
}

void Core::play()
{
    gameAction_t action = EMPTY;
    time_t myTime;

    if (this->_graphic == nullptr || this->_game == nullptr)
        throw LibNotFoundError("Rather the graphical lib or the game lib wasn't initialized.", "Core");
    this->_graphic->setRes(this->_game->getTextrRes(), this->_game->getAsciiRes(), this->_game->getColorRes());
    this->_graphic->init();
    while (!this->_game->isGameOver()) {
        myTime = std::time(nullptr);
        this->displayGame();
        usleep(500);
        this->_graphic->readKey();
        if (this->coreEvents() == true)
            continue;
        action = this->_graphic->getGameAction();
        switch (action) {
        case UP:
            this->_game->moveUp();
            break;
        case RIGHT:
            this->_game->moveRight();
            break;
        case DOWN:
            this->_game->moveDown();
            break;
        case LEFT:
            this->_game->moveLeft();
            break;
        default:
            break;
        }
        if ((float)(std::time(nullptr) - myTime) > 0.5)
            this->_game->automaticMove();
    }
    this->_graphic->stop();
}

void Core::changeGame(int mode)
{
    this->_game->~IGame();
    dlclose(this->_gameHdlr);
    if (mode == 1) {
        this->_gameIdx += 1;
        if (this->_gameIdx >= (int)this->_gameTab.size())
            this->_gameIdx = 0;
    } else if (mode == -1) {
        this->_gameIdx -= 1;
        if (this->_gameIdx < 0)
            this->_gameIdx = (int)this->_gameTab.size() - 1;
    }
    this->_game = this->openGameLib(GAMES + this->_gameTab[this->_gameIdx]);
    if (this->_game == nullptr)
        throw LibNotFoundError("The new game library wasn't found.", "Core");
    this->_graphic->setRes(this->_game->getTextrRes(), this->_game->getAsciiRes(), this->_game->getColorRes());
}

void Core::changeGraphic(int mode)
{
    this->_graphic->stop();
    this->_graphic->~IGraphic();
    dlclose(this->_graphicHdlr);
    if (mode == 1) {
        this->_graphicIdx += 1;
        if (this->_graphicIdx >= (int)this->_graphicTab.size())
            this->_graphicIdx = 0;
    } else if (mode == -1) {
        this->_graphicIdx -= 1;
        if (this->_graphicIdx < 0)
            this->_graphicIdx = (int)this->_graphicTab.size() - 1;
    }
    this->_graphic = this->openGraphLib(LIBS + this->_graphicTab[this->_graphicIdx]);
    if (this->_graphic == nullptr)
        throw LibNotFoundError("The new graphic library wasn't found.", "Core");
    this->_graphic->setRes(this->_game->getTextrRes(), this->_game->getAsciiRes(), this->_game->getColorRes());
    this->_graphic->init();
}

void Core::displayGame() const
{
    std::vector<std::vector<int>> map = this->_game->getMap();

    this->_graphic->clearScreen();
    for (int i = 0; i < (int)map.size(); i++) {
        for (int j = 0; j < (int)map[i].size(); j++)
            this->_graphic->display(map[i][j]);
        this->_graphic->display(-1);
    }
}
