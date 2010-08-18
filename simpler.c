#include <stdio.h>
#include <stdlib.h>

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

#define FAIL(...) {                             \
    fprintf(stderr, __VA_ARGS__);               \
    exit(1);                                    \
  }  

void init() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    FAIL("Unable to init sdl: %s\n", SDL_GetError());
  }

  atexit(end);

  screen = SDL_SetVideoMode(swidth, sheigth, 32, SDL_SWSURFACE);
  if (screen == NULL) {
    FAIL("Cant get screen: ", SDL_GetError());
  }

  int gridbytes = gridsize*gridsize*sizeof(Uint32);
  grid = (Uint32*)malloc(gridbytes);
  memset((void*)grid, 0x00, gridbytes);
}
