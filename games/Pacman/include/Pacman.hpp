/*
** EPITECH PROJECT, 2019
** Tek2
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
# define PACMAN_HPP_

# define PACMAN_WIDTH_SIZE 19
# define PACMAN_HEIGHT_SIZE 21
# define EMPTY 0
# define COIN 1
# define PACMAN 2
# define GHOST 3
# define OBSTACLE 4
# define SUPERCOIN 5

# include "AGame.hpp"
#include "Errors.hpp"
# include <chrono>
# include <ctime>

namespace game {
    namespace pacman {

        class Ghost {
            public:
		        Ghost(std::pair<int, int>);
		        ~Ghost();
                std::pair<int, int> getCoordinate() const;
                bool isKillable() const;
                bool isAlive() const;
                bool isOut() const;
                bool isStarted() const;
                Direction getDirection() const;
                int getOldValue() const;
                void setCoordinate(int, int);
                void setKillable(bool);
                void setAlive(bool);
                void setOut(bool);
                void setDirection(Direction);
                void setOldValue(int);
                void setStart(bool);
                std::time_t startDie;
                std::time_t startWait;
    	    protected:
	        private:
                std::pair<int, int> _coordinate;
                bool _killable;
                bool _alive;
                bool _out;
                bool _started;
                Direction _direction;
                int _oldValue;
        };
        
        class Pacman : public AGame {
	        public:
		        Pacman();
		        ~Pacman();
                void initMap();
                void loadRes();
                void moveUp();
                void moveDown();
                void moveRight();
                void moveLeft();
                void MoveGhosts();
                void createGhost();
                void powerOn();
                void powerOut();
                void checkGhost(int, int);
                void gameOver();
                void moveGhost();
                void moveGhostUp(int index);
                void moveGhostDown(int index);
                void moveGhostLeft(int index);
                void moveGhostRight(int index);
                void changeDirection(int index, int y, int x);
                void checkTimes(int index);
                void goOut();
    	    protected:
	        private:
                std::pair<int, int> _coordinate;
                bool _power;
                std::time_t _startPower;
                std::vector<Ghost> _ghostArray;
        };
    }
}

#endif /* !PACMAN_HPP_ */
