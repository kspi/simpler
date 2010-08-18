cmake_minimum_required(VERSION 2.8)
project(turtler)

include(FindPkgConfig)
pkg_check_modules(SDL REQUIRED sdl)
pkg_check_modules(GUILE REQUIRED guile-1.8)

find_package(SWIG)

add_definitions(
  -std=c99
  ${SDL_CFLAGS}
  ${GUILE_CFLAGS}
  )

link_libraries(
  ${SDL_LIBRARIES}
  ${GUILE_LIBRARIES}
  )

include(UseSWIG)
swig_add_module(simpler guile
  simpler.i
  simpler.c
  drawing.c
  drawing.h
  )
