#include <iostream>
#include <cstdlib>
#include <libguile.h>
#include <SDL.h>

#include "drawing.h"

Uint32* grid;
SDL_Surface *screen;

void point(int c, int x, int y) {
	x = x%gridsize;
	y = y%gridsize;
	grid[x+y*gridsize] = SDL_MapRGB(screen->format, c, c, c);
}

void box(int c, int x, int y, int w, int h) {
	for (int i = x; i < x+w; i++)
		for (int j = y; j < y+h; j++)
			point(c, i, j);
}

void wait(int t) {
	SDL_Delay(t);
}

void render() {
	if ( SDL_MUSTLOCK(screen) )
		if( SDL_LockSurface(screen < 0) )
			return;

	for (int y = 0; y < gridsize*squaresize; y++)
		for (int x = 0; x < gridsize*squaresize; x++) {
			Uint32 c = grid[ ((int)x/squaresize) + ((int)y/squaresize)*gridsize ];
			c = ((x%squaresize) && (y%squaresize)) ? c : 0;
			((unsigned int*)screen->pixels)[(x+10)+(y+10)*screen->w] = c;
		}

	if ( SDL_MUSTLOCK(screen) ) 
		SDL_UnlockSurface(screen);

	SDL_UpdateRect(screen, 0, 0, swidth, sheigth);    
}
