SRC = src/*.cpp
SRC += src/UI/*.cpp 
SRC += src/Objects/*.cpp

all:
	g++ -std=c++17 main.cpp $(SRC) -ISDL2/include -LSDL2/lib -Wall -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -o PhysicsSimulation

clean:
	del PhysicsSimulation.exe