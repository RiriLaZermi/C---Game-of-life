all:
	g++ -I src/include -L src/lib -o main gamelife.cpp -lmingw32 -lSDL2main -lSDL2
	.\main.exe

