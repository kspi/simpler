#include <stdlib.h>
#include <SDL.h>

#include "util.h"
#include "drawing.h"

Uint32* grid;
SDL_Surface *screen;

void point(int c, int x, int y) {
  x = x % GRID_SIZE;
  y = y % GRID_SIZE;
  grid[x + y * GRID_SIZE] = SDL_MapRGB(screen->format, c, c, c);
}

void box(int c, int x, int y, int w, int h) {
  for (int i = x; i < x+w; i++)
    for (int j = y; j < y+h; j++)
      point(c, i, j);
}

void nap(int t) {
  SDL_Delay(t);

  SDL_Event event;
  while(SDL_PollEvent(&event)) {
    switch(event.type){
    case SDL_KEYUP:
      if (event.key.keysym.sym == SDLK_ESCAPE) {
        exit(0);
      }
      break;
    case SDL_QUIT:
      exit(0);
      break;
    }
  }
}

void render() {
  if (SDL_MUSTLOCK(screen))
    if(SDL_LockSurface(screen) < 0)
      return;

  for (int y = 0; y < GRID_SIZE * SQUARE_SIZE; y++)
    for (int x = 0; x < GRID_SIZE * SQUARE_SIZE; x++) {
      Uint32 c = grid[ ((int) x / SQUARE_SIZE) +
                       ((int) y / SQUARE_SIZE) * GRID_SIZE ];
      c = ((x % SQUARE_SIZE) && (y % SQUARE_SIZE)) ? c : 0;
      ((Uint32*)screen->pixels)[(x+10) + (y+10)*screen->w] = c;
    }

  if (SDL_MUSTLOCK(screen)) 
    SDL_UnlockSurface(screen);

  SDL_UpdateRect(screen, 0, 0, screen->w, screen->h);
}

void init() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    FAIL("Unable to init sdl: %s\n", SDL_GetError());
  }

  screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE);
  if (screen == NULL) {
    FAIL("Cant get screen: ", SDL_GetError());
  }

  grid = calloc(GRID_SIZE * GRID_SIZE, sizeof *grid);
}
