# Project: OOPPROJECTFILEGAME
# Makefile created by Embarcadero Dev-C++ 6.3

CPP      = g++.exe -D__DEBUG__
CC       = gcc.exe -D__DEBUG__
WINDRES  = windres.exe
OBJ      = mainfileforgame.o
LINKOBJ  = mainfileforgame.o
LIBS     = -L"D:/DevC++ Setup/Dev-Cpp/TDM-GCC-64/lib" -L"D:/DevC++ Setup/Dev-Cpp/TDM-GCC-64/x86_64-w64-mingw32/lib" -static-libgcc -lwinmm -g3
INCS     = -I"D:/DevC++ Setup/Dev-Cpp/TDM-GCC-64/include" -I"D:/DevC++ Setup/Dev-Cpp/TDM-GCC-64/x86_64-w64-mingw32/include" -I"D:/DevC++ Setup/Dev-Cpp/TDM-GCC-64/lib/gcc/x86_64-w64-mingw32/9.2.0/include"
CXXINCS  = -I"D:/DevC++ Setup/Dev-Cpp/TDM-GCC-64/include" -I"D:/DevC++ Setup/Dev-Cpp/TDM-GCC-64/x86_64-w64-mingw32/include" -I"D:/DevC++ Setup/Dev-Cpp/TDM-GCC-64/lib/gcc/x86_64-w64-mingw32/9.2.0/include" -I"D:/DevC++ Setup/Dev-Cpp/TDM-GCC-64/lib/gcc/x86_64-w64-mingw32/9.2.0/include/c++"
BIN      = PACMAN-SABIH_ANAS_ARHAMOOP.exe
CXXFLAGS = $(CXXINCS) -ansi -std=gnu++14 -g3
CFLAGS   = $(INCS) -ansi -std=gnu++14 -g3
DEL      = D:\DevC++ Setup\Dev-Cpp\DevCpp.exe INTERNAL_DEL

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${DEL} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o $(BIN) $(LIBS)

mainfileforgame.o: mainfileforgame.cpp
	$(CPP) -c mainfileforgame.cpp -o mainfileforgame.o $(CXXFLAGS)
