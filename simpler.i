%module vs
%{
#include "drawing.h"
void init();
void end();
%}

%include drawing.h
void init();
void end();
