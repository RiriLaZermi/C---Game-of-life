#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#pragma once 

using namespace std;

class Screen_class {

    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;
    public:
    Screen_class() 
    {
        SDL_Init(SDL_INIT_VIDEO); 
        SDL_CreateWindowAndRenderer(1000, 1000, SDL_WINDOW_ALLOW_HIGHDPI, &window, &renderer);
        //SDL_RenderSetScale(renderer,100,100);
        SDL_SetRenderDrawColor(renderer,0,0,0,0);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
	}

    void drawRect(int x,int y,SDL_Color color){
        SDL_Rect rect={x*10,y*10,10-1,10-1};
        SDL_SetRenderDrawColor(renderer,color.r,color.g,color.b,color.a);
        SDL_RenderFillRect(renderer,&rect);
    }
  

    void update() 
    {
        
        SDL_RenderPresent(renderer);
    }
	
    void input() {
        while( SDL_PollEvent( &event ) )
        {  
            switch( event.type )
            {
                /* SDL_QUIT event (window close) */
                case SDL_QUIT:
                    SDL_Quit();
                    exit(0);
                    break;

                default:
                    break;
            }
        }
    }

};