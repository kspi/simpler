#include <iostream>
#include <cstdlib>
#include <string>

#include <SDL.h>

#include "drawing.h"

extern Uint32* grid;
extern SDL_Surface *screen;

void end() {
	SDL_Quit();

	if (grid != NULL) {
		free(grid);
		grid = NULL;
	}
}

void init() {
	if ( SDL_Init(SDL_INIT_VIDEO) < 0 ) {
		std::cerr << "Unable to init sdl: " << SDL_GetError() << std::endl;
		exit(1);
	}

	atexit(end);

	screen = SDL_SetVideoMode(swidth, sheigth, 32, SDL_SWSURFACE);
	if ( screen == NULL ) {
		std::cerr << "Cant get screen: " << SDL_GetError() << std::endl;
		exit(1);
	}

	int gridbytes = gridsize*gridsize*sizeof(Uint32);
	grid = (Uint32*)malloc(gridbytes);
	memset((void*)grid, 0x00, gridbytes);
}
