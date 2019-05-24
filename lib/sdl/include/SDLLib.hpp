/*
** EPITECH PROJECT, 2019
** Tek2
** File description:
** SDLLIB
*/

#ifndef SDLLib_HPP_
    #define SDLLib_HPP_

#include <unistd.h>
#include "SDL2/SDL.h"
#include "AGraphic.hpp"
#include "Errors.hpp"

# define T_SIZE 40
# define T_NWIDTH 19
# define T_NHEIGHT 21
# define SCR_WIDTH (T_SIZE * T_NWIDTH)
# define SCR_HEIGHT (T_SIZE * T_NHEIGHT)

namespace graphic {
	namespace sdl {

		typedef struct s_print {
			SDL_Rect rect;
			int color[3];
					
			s_print()
            {
				color[0] = 0;
				color[1] = 0;
				color[2] = 0;
				rect.x = 0;
				rect.y = 0;
				rect.h = T_SIZE;
				rect.w = T_SIZE;
            }
            
			~s_print()
            {
            }

		} t_print;

		class SDLLib : public AGraphic {
			public:
			SDLLib();
			~SDLLib();
			void init();
			void stop();
			void display(int nb);
			void displayBox(std::vector<std::string> &tab, int pos);
			void displayMenu(std::vector<std::vector<std::string>> &tab);
			void setRes(std::vector<std::string> textrRes, std::vector<std::string> asciiRes, std::vector<std::string> colorRes);
			void readKey();
			void clearScreen();
			protected:
			private:
			SDL_Window *_window;
			SDL_Renderer *_renderer;
			SDL_Event _event;
			std::vector<t_print *> _printables;
			std::pair<int, int> _pPos = {0, 0};
		};
	}
}

#endif /* !SDLLib_HPP_ */
