#include <stdio.h>
#include <SDL2/SDL.h>
  
int main(int argc, char *argv[]) {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *imageDeFond;
 
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(640,480,SDL_WINDOW_SHOWN,&window,&renderer);
    imageDeFond = SDL_LoadBMP("world.bmp");
    if(imageDeFond) {
        SDL_Texture *pTextureImage;
        pTextureImage=SDL_CreateTextureFromSurface(renderer,imageDeFond);
        SDL_FreeSurface(imageDeFond);
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,pTextureImage,NULL,NULL);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(pTextureImage);
        SDL_Delay(10000);
    }
    else
        printf("erreur hello_world.bmp: %s\n,",SDL_GetError());
  
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
  
    return 0;
}
