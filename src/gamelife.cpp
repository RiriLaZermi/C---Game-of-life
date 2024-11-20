
#include <iostream>
#include <vector>
#include <algorithm>
#include "screen.h"


using namespace std;

const int GAME_WIDTH = 100;
const int GAME_HEIGHT = 100;
const int DELAY_ms = 50;
const int INITIALISATION_ALIVE_CELL = 10; //10% 

SDL_Color COLOR_BG={255,255,255,0};
SDL_Color COLOR_ALIVE={0,255,0,0};
SDL_Color COLOR_DEAD={70,70,70,0};



int ConwayRules(int row,int column,vector<vector<int>> &v ){
    int aliveCounter;
    aliveCounter=0;
    //voisin du haut
    if(row>0 && v[row-1][column]) aliveCounter++;
    //voisin du bas
    if(row<(GAME_HEIGHT-1) && v[row+1][column]) aliveCounter++;
    //voisin de gauche
    if(column>0 && v[row][column-1]) aliveCounter++;
    //voisin de droite
    if(column<(GAME_WIDTH-1) && v[row][column+1]) aliveCounter++;
    //voisin haut gauche
    if(row>0 && column>0 && v[row-1][column-1]) aliveCounter++;
    //voisin haut droite
    if(row>0 && column < (GAME_WIDTH-1) && v[row-1][column+1]) aliveCounter++;
    //voisin bas gauche
    if(row<(GAME_HEIGHT-1) && column>0 && v[row+1][column-1] ) aliveCounter++;
    //voisin bas droite
    if(row<(GAME_HEIGHT-1) && column<(GAME_WIDTH-1) && v[row+1][column+1]) aliveCounter++;


    if(aliveCounter==3) return 1;
    else if(aliveCounter==2 && v[row][column]) return 1;
    else if(aliveCounter==2 && !v[row][column]) return 0;
    else if(aliveCounter<2 || aliveCounter>3) return 0;
    else return 0; 
}

int main(int argv, char** args ) {
    srand(time(0));
    Screen_class screen;
    vector< vector<int> > oldState(GAME_HEIGHT, vector<int>(GAME_WIDTH,0));
    vector< vector<int> > newState(GAME_WIDTH, vector<int>(GAME_WIDTH,0));

    vector<int> test(10);
    SDL_Color color;
    for(auto &row: oldState) generate(row.begin(),row.end(),[](){return rand()%(100/INITIALISATION_ALIVE_CELL)==0? 1: 0;});

    while(true)
    {
		if (!screen.isGamePaused()) {
			for(int i=0;i<GAME_HEIGHT;i++){
				
				for(int j=0;j<GAME_WIDTH;j++){
					
				   newState[i][j]=ConwayRules(i,j,oldState);
				}

			}

			for(int i=0;i<GAME_HEIGHT;i++){
				
				for(int j=0;j<GAME_WIDTH;j++){
					
					if(oldState[i][j]) color=COLOR_ALIVE;else color=COLOR_DEAD;
					screen.drawRect(i,j,color); 
				}

			}
		oldState=newState;
		SDL_Delay(DELAY_ms);
		screen.update();
        }
   
        screen.input();
        

    }
    return 0;


}