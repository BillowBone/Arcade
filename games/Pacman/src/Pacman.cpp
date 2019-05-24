/*
** EPITECH PROJECT, 2019
** Tek2
** File description:
** Pacman
*/

#include "Pacman.hpp"

namespace game {
    namespace pacman {
        Pacman::Pacman()
            : AGame()
        {
            this->initMap();
            this->_coordinate = std::make_pair(15, 9);
            this->_direction = UP;
            this->_power = false;
            this->_automatic = false;
            this->_score = 0;
            this->_gameOver = false;
            this->_ghostArray.reserve(4);
            this->createGhost();
            this->loadRes();
        }

        void Pacman::createGhost()
        {
            Ghost ghost1(std::make_pair(8, 9));
            Ghost ghost2(std::make_pair(9, 8));
            Ghost ghost3(std::make_pair(9, 9));
            Ghost ghost4(std::make_pair(9, 10));
            time(&ghost1.startWait);
            this->_ghostArray.push_back(ghost1);
            this->_ghostArray.push_back(ghost2);
            this->_ghostArray.push_back(ghost3);
            this->_ghostArray.push_back(ghost4);
        }

        void Pacman::initMap()
        {
            std::string line;

            std::ifstream file("./games/Pacman/map.txt");
            if (!file)
                throw PacmanMapNotFoundError("The Pacman map file wasn't found.", "Pacman");

            for (int i = 0; i < PACMAN_HEIGHT_SIZE; i = i + 1) {
                std::vector<int> mapLine;
                for (int j = 0; j < PACMAN_WIDTH_SIZE; j = j + 1)
                    mapLine.push_back(EMPTY);
                this->_map.push_back(mapLine);
            }

            for (int i = 0; std::getline(file, line); i = i + 1) {
                for (int j = 0; j < _map.size(); j = j + 1) {
                    if (line[j] == 49)
                        this->_map[i][j] = COIN;
                    if (line[j] == 50)
                        this->_map[i][j] = PACMAN;
                    if (line[j] == 51)
                        this->_map[i][j] = GHOST;
                    if (line[j] == 52)
                        this->_map[i][j] = OBSTACLE;
                    if (line[j] == 53)
                        this->_map[i][j] = SUPERCOIN;
                }
            }
        }

        void Pacman::loadRes()
        {
            _textrRes.push_back("res/textr/pacmanempty.jpg");
            _textrRes.push_back("res/textr/coin.png");
            _textrRes.push_back("res/textr/pacman.png");
            _textrRes.push_back("res/textr/ghost.png");
            _textrRes.push_back("res/textr/obstacle.png");
            _textrRes.push_back("res/textr/ruby.png");
            _asciiRes.push_back(" ");
            _asciiRes.push_back("*");
            _asciiRes.push_back("P");
            _asciiRes.push_back("O");
            _asciiRes.push_back("#");
            _asciiRes.push_back("S");
            _colorRes.push_back("0/0/0");
            _colorRes.push_back("233/109/20");
            _colorRes.push_back("255/255/0");
            _colorRes.push_back("255/0/0");
            _colorRes.push_back("88/41/0");
            _colorRes.push_back("253/108/158");
        }

        void Pacman::powerOn()
        {
            this->_power = true;
            for (int i = 0; i < this->_ghostArray.size(); i = i + 1)
                this->_ghostArray[i].setKillable(true);
            this->_score = this->_score + 500;
        }

        void Pacman::powerOut()
        {
            time_t end;

            time(&end);
            if (end - this->_startPower > 10) {
                this->_power = false;
                for (int i = 0; i < this->_ghostArray.size(); i = i + 1)
                    this->_ghostArray[i].setKillable(false);
            }
        }

        void Pacman::gameOver()
        {
            this->_gameOver = true;
        }

        void Pacman::checkGhost(int x, int y)
        {
            for (int i = 0; i < this->_ghostArray.size(); i = i + 1) {
                if (this->_ghostArray[i].getCoordinate().first == x &&
                    this->_ghostArray[i].getCoordinate().second == y) {
                        if (this->_ghostArray[i].isKillable() == false)
                            this->gameOver();
                        else {
                            this->_score = this->_score + 1000;
                            this->_ghostArray[i].setAlive(false);
                            this->_ghostArray[i].setCoordinate(8, 9);
                            this->_ghostArray[i].setDirection(RIGHT);
                            this->_ghostArray[i].setOut(false);
                            time(&(this->_ghostArray[i].startDie));
                        }
                    }
            }
        }

        void Pacman::checkTimes(int i)
        {
            std::time_t now;
            time(&now);
            this->powerOut();
            if (now - this->_ghostArray[i].startDie > 10) {
                this->_map[this->_ghostArray[i].getCoordinate().first][this->_ghostArray[i].getCoordinate().second] = EMPTY;
                this->_ghostArray[i].setCoordinate(7, 9);
                this->_ghostArray[i].setOut(true);
                this->_ghostArray[i].setAlive(true);
            }
        }

        void Pacman::goOut()
        {
            std::time_t now;
            time(&now);
            if (this->_ghostArray[0].isOut() == false && this->_ghostArray[0].isStarted() == false) {
                if (now - this->_ghostArray[0].startWait > 10) {
                    this->_ghostArray[0].setOut(true);
                    this->_ghostArray[0].setStart(true);
                }
            }
            for (int i = 1; i < this->_ghostArray.size(); i = i + 1) {
                if (this->_ghostArray[i - 1].isStarted() == true) {
                    if (this->_ghostArray[i].isStarted() == false && this->_ghostArray[i - 1].isOut() == true) {
                        this->_ghostArray[i].setStart(true);
                        time(&this->_ghostArray[i].startWait);
                    } else if (this->_ghostArray[i].isOut() == false && (now - this->_ghostArray[i].startWait > 10)) {
                        this->_ghostArray[i].setOut(true);
                        this->_ghostArray[i].setCoordinate(7, 9);
                    }
                }
            }
        }

        void Pacman::moveGhost()
        {
            this->goOut();
            for (int i = 0; i < this->_ghostArray.size(); i = i + 1) {
                this->checkTimes(i);
                if (this->_ghostArray[i].isOut() == false)
                    continue;
                else if (this->_ghostArray[i].getDirection() == UP)
                    this->moveGhostUp(i);
                else if (this->_ghostArray[i].getDirection() == DOWN)
                    this->moveGhostDown(i);
                else if (this->_ghostArray[i].getDirection() == LEFT)
                    this->moveGhostLeft(i);
                else
                    this->moveGhostRight(i);
            }
        }

        void Pacman::moveGhostUp(int i)
        {
            int y = this->_ghostArray[i].getCoordinate().first - 1;
            int x = this->_ghostArray[i].getCoordinate().second;
            if (y >= 0) {
                if (this->_map[y][x] == OBSTACLE) {
                    this->changeDirection(i, y + 1, x);
                    return;
                } if (this->_map[y][x] == PACMAN) {
                    if (this->_ghostArray[i].isKillable() == false) {
                        this->gameOver();
                        return;
                    } else {
                        this->_score = this->_score + 1000;
                        this->_ghostArray[i].setAlive(false);
                        this->_ghostArray[i].setCoordinate(8, 9);
                        this->_ghostArray[i].setDirection(RIGHT);
                        this->_ghostArray[i].setOut(false);
                        time(&(this->_ghostArray[i].startDie));
                    }
                }
                this->_map[y + 1][x] = this->_ghostArray[i].getOldValue();
                if (this->_map[y][x] == GHOST) {
                    for (int j = 0; j < this->_ghostArray.size(); j = j + 1) {
                        if (y == this->_ghostArray[j].getCoordinate().first && x == this->_ghostArray[j].getCoordinate().second)
                            this->_ghostArray[i].setOldValue(this->_ghostArray[j].getOldValue());
                    }
                } else
                    this->_ghostArray[i].setOldValue(this->_map[y][x]);
                this->_map[y][x] = GHOST;
                this->_ghostArray[i].setCoordinate(y, x);
            }
        }

        void Pacman::moveGhostDown(int i)
        {
            int y = this->_ghostArray[i].getCoordinate().first + 1;
            int x = this->_ghostArray[i].getCoordinate().second;
            if (y <= 20) {
                if (this->_map[y][x] == OBSTACLE) {
                    this->changeDirection(i, y - 1, x);
                    return;
                }
                if (this->_map[y][x] == PACMAN) {
                    if (this->_ghostArray[i].isKillable() == false) {
                        this->gameOver();
                        return;
                    } else {
                        this->_score = this->_score + 1000;
                        this->_ghostArray[i].setAlive(false);
                        this->_ghostArray[i].setCoordinate(8, 9);
                        this->_ghostArray[i].setDirection(RIGHT);
                        this->_ghostArray[i].setOut(false);
                        time(&(this->_ghostArray[i].startDie));
                    }
                }
                this->_map[y - 1][x] = this->_ghostArray[i].getOldValue();
                if (this->_map[y][x] == GHOST) {
                    for (int j = 0; j < this->_ghostArray.size(); j = j + 1) {
                        if (y == this->_ghostArray[j].getCoordinate().first && x == this->_ghostArray[j].getCoordinate().second)
                            this->_ghostArray[i].setOldValue(this->_ghostArray[j].getOldValue());
                    }
                } else
                    this->_ghostArray[i].setOldValue(this->_map[y][x]);
                this->_map[y][x] = GHOST;
                this->_ghostArray[i].setCoordinate(y, x);
            }
        }

        void Pacman::moveGhostLeft(int i)
        {
            int y = this->_ghostArray[i].getCoordinate().first;
            int x = this->_ghostArray[i].getCoordinate().second - 1;
            if (x >= 0) {
                if (this->_map[y][x] == OBSTACLE) {
                    this->changeDirection(i, y, x + 1);
                    return;
                }
                if (this->_map[y][x] == PACMAN) {
                    if (this->_ghostArray[i].isKillable() == false) {
                        this->gameOver();
                        return;
                    } else {
                        this->_score = this->_score + 1000;
                        this->_ghostArray[i].setAlive(false);
                        this->_ghostArray[i].setCoordinate(8, 9);
                        this->_ghostArray[i].setDirection(RIGHT);
                        this->_ghostArray[i].setOut(false);
                        time(&(this->_ghostArray[i].startDie));
                    }
                }
                this->_map[y][x + 1] = this->_ghostArray[i].getOldValue();
                if (this->_map[y][x] == GHOST) {
                    for (int j = 0; j < this->_ghostArray.size(); j = j + 1) {
                        if (y == this->_ghostArray[j].getCoordinate().first && x == this->_ghostArray[j].getCoordinate().second)
                            this->_ghostArray[i].setOldValue(this->_ghostArray[j].getOldValue());
                    }
                } else
                    this->_ghostArray[i].setOldValue(this->_map[y][x]);
                this->_map[y][x] = GHOST;
                this->_ghostArray[i].setCoordinate(y, x);
            }
        }

        void Pacman::moveGhostRight(int i)
        {
            int y = this->_ghostArray[i].getCoordinate().first;
            int x = this->_ghostArray[i].getCoordinate().second + 1;
            if (x <= 18) {
                if (this->_map[y][x] == OBSTACLE) {
                    this->changeDirection(i, y, x - 1);
                    return;
                }
                if (this->_map[y][x] == PACMAN) {
                    if (this->_ghostArray[i].isKillable() == false) {
                        this->gameOver();
                        return;
                    } else {
                        this->_score = this->_score + 1000;
                        this->_ghostArray[i].setAlive(false);
                        this->_ghostArray[i].setCoordinate(8, 9);
                        this->_ghostArray[i].setDirection(RIGHT);
                        this->_ghostArray[i].setOut(false);
                        time(&(this->_ghostArray[i].startDie));
                    }
                }
                this->_map[y][x - 1] = this->_ghostArray[i].getOldValue();
                if (this->_map[y][x] == GHOST) {
                    for (int j = 0; j < this->_ghostArray.size(); j = j + 1) {
                        if (y == this->_ghostArray[j].getCoordinate().first && x == this->_ghostArray[j].getCoordinate().second)
                            this->_ghostArray[i].setOldValue(this->_ghostArray[j].getOldValue());
                    }
                } else
                    this->_ghostArray[i].setOldValue(this->_map[y][x]);
                this->_map[y][x] = GHOST;
                this->_ghostArray[i].setCoordinate(y, x);
            }
        }

        void Pacman::changeDirection(int i, int y, int x)
        {
            std::vector<Direction> array;
            if (this->_map[y + 1][x] != OBSTACLE)
                array.push_back(DOWN);
            if (this->_map[y - 1][x] != OBSTACLE)
                array.push_back(UP);
            if (this->_map[y][x + 1] != OBSTACLE)
                array.push_back(RIGHT);
            if (this->_map[y][x - 1] != OBSTACLE)
                array.push_back(LEFT);
            this->_ghostArray[i].setDirection(array[rand() % array.size()]);
        }

        void Pacman::moveUp()
        {
            this->moveGhost();
            if (this->_direction != UP || this->_automatic) {
                if (this->_coordinate.first - 1 > 0) {
                    if (this->_map[this->_coordinate.first - 1][this->_coordinate.second] == OBSTACLE)
                        return;
                    if (this->_map[this->_coordinate.first - 1][this->_coordinate.second] == COIN)
                        this->_score = this->_score + 100;
                    if (this->_map[this->_coordinate.first - 1][this->_coordinate.second] == SUPERCOIN) {
                        this->powerOn();
                        time(&this->_startPower);
                    }
                    if (this->_map[this->_coordinate.first - 1][this->_coordinate.second] == GHOST)
                        this->checkGhost(this->_coordinate.first - 1, this->_coordinate.second);
                    this->_map[this->_coordinate.first][this->_coordinate.second] = EMPTY;
                    this->_map[this->_coordinate.first - 1][this->_coordinate.second] = PACMAN;
                    this->_coordinate.first -= 1;
                    this->_direction = UP;
                }
            }
        }

        void Pacman::moveLeft()
        {
            this->moveGhost();
            if (this->_direction != LEFT || this->_automatic) {
                if (this->_coordinate.second - 1 > 0) {
                    if (this->_map[this->_coordinate.first][this->_coordinate.second - 1] == OBSTACLE)
                        return;
                    if (this->_map[this->_coordinate.first][this->_coordinate.second - 1] == COIN)
                        this->_score = this->_score + 100;
                    if (this->_map[this->_coordinate.first][this->_coordinate.second - 1] == SUPERCOIN) {
                        this->powerOn();
                        time(&this->_startPower);
                    }
                    if (this->_map[this->_coordinate.first][this->_coordinate.second - 1] == GHOST)
                        this->checkGhost(this->_coordinate.first, this->_coordinate.second - 1);
                    this->_map[this->_coordinate.first][this->_coordinate.second] = EMPTY;
                    this->_map[this->_coordinate.first][this->_coordinate.second - 1] = PACMAN;
                    this->_coordinate.second -= 1;
                    this->_direction = LEFT;
                }
            }
        }

        void Pacman::moveRight()
        {
            this->moveGhost();
            if (this->_direction != RIGHT || this->_automatic) {
                if (this->_coordinate.second + 1 <= 18) {
                    if (this->_map[this->_coordinate.first][this->_coordinate.second + 1] == OBSTACLE)
                        return;
                    if (this->_map[this->_coordinate.first][this->_coordinate.second + 1] == COIN)
                        this->_score = this->_score + 100;
                    if (this->_map[this->_coordinate.first][this->_coordinate.second + 1] == SUPERCOIN) {
                        this->powerOn();
                        time(&this->_startPower);
                    }
                    if (this->_map[this->_coordinate.first][this->_coordinate.second + 1] == GHOST)
                        this->checkGhost(this->_coordinate.first, this->_coordinate.second + 1);
                    this->_map[this->_coordinate.first][this->_coordinate.second] = EMPTY;
                    this->_map[this->_coordinate.first][this->_coordinate.second + 1] = PACMAN;
                    this->_coordinate.second += 1;
                    this->_direction = RIGHT;
                }
            }
        }

        void Pacman::moveDown()
        {
            this->moveGhost();
            if (this->_direction != DOWN || this->_automatic) {
                if (this->_coordinate.first + 1 < 20) {
                    if (this->_map[this->_coordinate.first + 1][this->_coordinate.second] == OBSTACLE)
                        return;
                    if (this->_map[this->_coordinate.first + 1][this->_coordinate.second] == COIN)
                        this->_score = this->_score + 100;
                    if (this->_map[this->_coordinate.first + 1][this->_coordinate.second] == SUPERCOIN) {
                        this->powerOn();
                        time(&this->_startPower);
                    }
                    if (this->_map[this->_coordinate.first + 1][this->_coordinate.second] == GHOST)
                        this->checkGhost(this->_coordinate.first + 1, this->_coordinate.second);
                    this->_map[this->_coordinate.first][this->_coordinate.second] = EMPTY;
                    this->_map[this->_coordinate.first + 1][this->_coordinate.second] = PACMAN;
                    this->_coordinate.first += 1;
                    this->_direction = DOWN;
                }
            }
        }

        Pacman::~Pacman()
        {
        }

        Ghost::Ghost(std::pair<int, int> coordinate)
        {
            this->_alive = true;
            this->_out = false;
            this->_coordinate = coordinate;
            this->_killable = false;
            this->_direction = RIGHT;
            this->_oldValue = EMPTY;
            this->_started = false;
        }

        std::pair<int, int> Ghost::getCoordinate() const
        {
            return (this->_coordinate);
        }

        bool Ghost::isKillable() const
        {
            return (this->_killable);
        }

        bool Ghost::isAlive() const
        {
            return (this->_alive);
        }

        bool Ghost::isOut() const
        {
            return (this->_out);
        }

        bool Ghost::isStarted() const
        {
            return (this->_started);
        }

        Direction Ghost::getDirection() const
        {
            return (this->_direction);
        }

        int Ghost::getOldValue() const
        {
            return (this->_oldValue);
        }

        void Ghost::setAlive(bool alive)
        {
            this->_alive = alive;
        }

        void Ghost::setCoordinate(int x, int y)
        {
            this->_coordinate.first = x;
            this->_coordinate.second = y;
        }

        void Ghost::setDirection(Direction direction)
        {
            this->_direction = direction;
        }

        void Ghost::setKillable(bool killable)
        {
            this->_killable = killable;
        }

        void Ghost::setOldValue(int value)
        {
            this->_oldValue = value;
        }

        void Ghost::setOut(bool out)
        {
            this->_out = out;
        }

        void Ghost::setStart(bool start)
        {
            this->_started = start;
        }

        Ghost::~Ghost()
        {
        }
    }
}

extern "C" {
    game::IGame *createIGame(void) {
        game::IGame *tmp(new game::pacman::Pacman());

        return (tmp);
    }
}
