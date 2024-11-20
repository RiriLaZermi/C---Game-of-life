all:
	g++ -I include -L lib -o game_of_life src/gamelife.cpp -lmingw32 -lSDL2main -lSDL2
	.\main.exe

