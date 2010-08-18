#ifndef drawing_h_INCLUDED
#define drawing_h_INCLUDED

#include <SDL.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define GRID_SIZE 92
#define SQUARE_SIZE 5

extern Uint32* grid;
extern SDL_Surface *screen;

void point(int, int, int);
void box(int, int, int, int, int);
void wait(int);

void render();
void init();
void end();

#endif

