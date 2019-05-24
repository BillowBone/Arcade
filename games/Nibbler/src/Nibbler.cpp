/*
** EPITECH PROJECT, 2019
** OOP - Arcade
** File description:
** Nibbler.cpp
*/

#include <unistd.h>
#include "Nibbler.hpp"

namespace game {
    namespace nibbler {
        Nibbler::Nibbler() : AGame()
        {
            std::srand(std::time(nullptr));
            this->_automatic = false;
            this->_score = 0;
            this->_gameOver = false;
            this->_move = false;
            this->initMap();
            this->generateFood(3);
            this->loadRes();
        }

        Nibbler::~Nibbler()
        {
        }

        void Nibbler::initMap()
        {
            int i = 0;
            std::ifstream file("./games/Nibbler/map");

            if (!file)
                throw NibblerMapNotFoundError("The Nibbler map file wasn't found.", "Nibbler");
            this->_map.reserve(NIBBLER_MAP_SIZE);
            for (int k = 0; k < NIBBLER_MAP_SIZE; k++) {
                std::vector<int> vect;
                for (int l = 0; l < NIBBLER_MAP_SIZE; l++) {
                    vect.push_back(EMPTY);
                }
                this->_map.push_back(vect);
            }
            for (std::string line; std::getline(file, line); i++) {
                for (int j = 0; j < NIBBLER_MAP_SIZE; j++) {
                    if (line[j] == 48)
                        this->_map[i][j] = EMPTY;
                    else if (line[j] == 49)
                        this->_map[i][j] = OBSTACLE;
                    else if (line[j] == 50)
                        this->_map[i][j] = SNAKE_BODY;
                    else
                        this->_map[i][j] = SNAKE_HEAD;
                }
            }
            this->_snake.push_back(std::make_pair(8, 9));
            this->_snake.push_back(std::make_pair(8, 8));
            this->_snake.push_back(std::make_pair(8, 7));
            this->_snake.push_back(std::make_pair(8, 6));
            this->_direction = RIGHT;
        }

        void Nibbler::loadRes()
        {
            _textrRes.push_back("res/textr/empty.png");
            _textrRes.push_back("res/textr/obstacle.png");
            _textrRes.push_back("res/textr/snkBody.png");
            _textrRes.push_back("res/textr/snkHead.png");
            _textrRes.push_back("res/textr/food.png");
            _asciiRes.push_back(" ");
            _asciiRes.push_back("*");
            _asciiRes.push_back("=");
            _asciiRes.push_back("O");
            _asciiRes.push_back("x");
            _colorRes.push_back("0/0/0");
            _colorRes.push_back("88/41/0");
            _colorRes.push_back("0/255/0");
            _colorRes.push_back("255/0/0");
            _colorRes.push_back("255/255/0");
        }

        void Nibbler::moveUp()
        {
            if ((this->_direction != DOWN && this->_direction != UP) || (this->_automatic)) {
                if (this->_snake[0].first - 1 >= 0) {
                    int forward = this->_map[this->_snake[0].first - 1][this->_snake[0].second];
                    if (forward != OBSTACLE && forward != SNAKE_BODY) {
                        this->moveSnake(forward);
                        this->_snake[0].first--;
                        this->_map[this->_snake[0].first][this->_snake[0].second] = SNAKE_HEAD;
                        this->_direction = UP;
                    } else {
                        this->_gameOver = true;
                    }
                } else {
                    this->_gameOver = true;
                }
            }
        }

        void Nibbler::moveRight()
        {
            if ((this->_direction != RIGHT && this->_direction != LEFT) || (this->_automatic)) {
                if (this->_snake[0].second + 1 < NIBBLER_MAP_SIZE) {
                    int forward = this->_map[this->_snake[0].first][this->_snake[0].second + 1];
                    if (forward != OBSTACLE && forward != SNAKE_BODY) {
                        this->moveSnake(forward);
                        this->_snake[0].second++;
                        this->_map[this->_snake[0].first][this->_snake[0].second] = SNAKE_HEAD;
                        this->_direction = RIGHT;
                    } else {
                        this->_gameOver = true;
                    }
                } else {
                    this->_gameOver = true;
                }
            }
        }

        void Nibbler::moveDown()
        {
            if ((this->_direction != DOWN && this->_direction != UP) || (this->_automatic)) {
                if (this->_snake[0].first + 1 < NIBBLER_MAP_SIZE) {
                    int forward = this->_map[this->_snake[0].first + 1][this->_snake[0].second];
                    if (forward != OBSTACLE && forward != SNAKE_BODY) {
                        this->moveSnake(forward);
                        this->_snake[0].first++;
                        this->_map[this->_snake[0].first][this->_snake[0].second] = SNAKE_HEAD;
                        this->_direction = DOWN;
                    } else {
                        this->_gameOver = true;
                    }
                } else {
                    this->_gameOver = true;
                }
            }
        }

        void Nibbler::moveLeft()
        {
            if ((this->_direction != RIGHT && this->_direction != LEFT) || (this->_automatic)) {
                if (this->_snake[0].second - 1 >= 0) {
                    int forward = this->_map[this->_snake[0].first][this->_snake[0].second - 1];
                    if (forward != OBSTACLE && forward != SNAKE_BODY) {
                        this->moveSnake(forward);
                        this->_snake[0].second--;
                        this->_map[this->_snake[0].first][this->_snake[0].second] = SNAKE_HEAD;
                        this->_direction = LEFT;
                    } else {
                        this->_gameOver = true;
                    }
                } else {
                    this->_gameOver = true;
                }
            }
        }

        void Nibbler::generateFood(int nbFood)
        {
            for (int i = 0; i < nbFood; i++) {
                int x = std::rand() % NIBBLER_MAP_SIZE;
                int y = std::rand() % NIBBLER_MAP_SIZE;
                while (this->_map[x][y] != EMPTY) {
                    x = std::rand() % NIBBLER_MAP_SIZE;
                    y = std::rand() % NIBBLER_MAP_SIZE;
                }
                this->_map[x][y] = FOOD;
            }
        }

        void Nibbler::moveSnake(int forward)
        {
            int size = this->_snake.size() - 1;

            if (forward != FOOD) {
                this->_map[this->_snake[size].first][this->_snake[size].second] = EMPTY;
            } else {
                this->_score += 100;
                this->_map[this->_snake[size].first][this->_snake[size].second] = SNAKE_BODY;
                this->_snake.push_back(std::make_pair(this->_snake[size].first, this->_snake[size].second));
            }
            for (int i = size; i > 0; i--) {
                this->_snake[i] = this->_snake[i - 1];
                this->_map[this->_snake[i - 1].first][this->_snake[i - 1].second] = SNAKE_BODY;
            }
            if (forward == FOOD)
                this->generateFood(1);
        }
    }
}

extern "C" {
    game::IGame *createIGame(void) {
        game::IGame *tmp(new game::nibbler::Nibbler());

        return (tmp);
    }
}
