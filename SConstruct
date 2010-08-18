import glob

# create build environment
env = Environment()

env.ParseConfig('sdl-config --cflags')
env.ParseConfig('sdl-config --libs')

env.ParseConfig('guile-config compile')
env.ParseConfig('guile-config link')

# gather a list of source files
SOURCES = ['vs.cc', 'drawing.cc', 'vs.i']

# add additional compiler flags
env.AppendUnique(CCFLAGS = ['-g'])
# add additional libraries to link against
env.AppendUnique(LIBS = [])

env.AppendUnique(SWIGFLAGS = ['-c++', '-guile', '-scm'])

# build target
# output executable will be "game"
env.SharedLibrary(target = 'vs', source = SOURCES)
