# Makefile for Deep Impact: Freefall
# (C) 2013 Daniel Gibson, do whatever you want with it
#
# needs GNU make, tested on Linux, should work on other unix-like systems as well
# also needs SDL2, SDL2 image and SDL2 ttf + development headers etc
# and a C++11 and GCC compatible C++ compiler (tested g++ 4.7 and clang++ 3.3)

# CC := clang
# CXX := clang++

# more or less custom flags for the compiler
CFLAGS := -std=c++11 -Wall

# add all flags needed for the libs..
CFLAGS += $(shell sdl2-config --cflags)
CFLAGS += $(shell pkg-config --cflags SDL2_image)
CFLAGS += $(shell pkg-config --cflags SDL2_ttf)

# flags for the linker
LDFLAGS := $(shell sdl2-config --libs)
LDFLAGS += $(shell pkg-config --libs SDL2_image)
LDFLAGS += $(shell pkg-config --libs SDL2_ttf)

# get the sources
SOURCES = $(wildcard FreeSpace/*.cpp)

# generate the names for the corresponding object files,
# will be in build/*.o
OBJS = $(patsubst FreeSpace/%.cpp,build/%.o,$(SOURCES))

# when building with "make VERBOSE=1" it'll output the commands, else not
ifdef VERBOSE
Q :=
else
Q := @
endif

# the default target: create FreeSpace/freespace binary
all: FreeSpace/freespace

# before we can compile the object files (*.o), we need the build/ directory,
# where they'll be put, so they get a dependency on that
$(OBJS): | build

# target for the build dir.. just creating it
build:
	${@}mkdir build

# how to build an object file
build/%.o: FreeSpace/%.cpp
	@echo "Compiling $< to $@"
	${Q}$(CXX) -c $(CFLAGS) -o $@ $<

# the freespace binary will be in FreeSpace/ (so it can use res/ directly)
# and depends on the object files
# (=> they will be built first. make even detects when they're outdated because the
#  corresponding source file changed and rebuilds them)
FreeSpace/freespace: $(OBJS)
	@echo "Linking FreeSpace/freespace ..."
	${Q}${CXX} ${CFLAGS} ${LDFLAGS} $(OBJS) -o $@

clean:
	@echo "cleaning up!"
	rm -r build
	rm FreeSpace/freespace
