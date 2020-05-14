#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int InitializeSDL() {
  int result = 0;
  result = SDL_Init(SDL_INIT_VIDEO);
  if (result >= 0) {
    result = TTF_Init();
  }
  return result;
}

void SetBackgroundColor(SDL_Window *window, int r, int g, int b)
{
  SDL_Surface *screen = SDL_GetWindowSurface(window);
  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, r, g, b));
  SDL_UpdateWindowSurface(window);
}

int PrintText(SDL_Window *window, char* text, int r, int g, int b)
{
  SDL_Surface *screen = SDL_GetWindowSurface(window);
  TTF_Font *font = TTF_OpenFont( "DejaVuSansMono.ttf", 28 );
  SDL_Color color = {r, g, b};
  SDL_Surface *text_surface;

  text_surface = TTF_RenderText_Solid(font, text, color);
  if (text_surface != NULL)
  {
      SDL_BlitSurface(text_surface, NULL, screen, NULL);
      SDL_FreeSurface(text_surface);
      return 0;
  }
  else
  {
      // report error
      return -1;
  }
}

int main(int argc, char *argv[])
{

  int quit = 0;
  SDL_Window *window = NULL;
  SDL_Event event;

  if (InitializeSDL() < 0) {
    fprintf(stderr, "could not initialize sdl2: %s\n", SDL_GetError());
    return 1;
  }

  window = SDL_CreateWindow(
			    "hello_sdl2",
			    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			    SCREEN_WIDTH, SCREEN_HEIGHT,
			    SDL_WINDOW_SHOWN
			    );
  
  if (window == NULL) {
    fprintf(stderr, "could not create window: %s\n", SDL_GetError());
    return 1;
  }

  SetBackgroundColor(window, 0x55, 0x55, 0x55);
  
  //SDL_ShowSimpleMessageBox( SDL_MESSAGEBOX_INFORMATION, "Mensaje SDL2", "hola mundosss.", window );

  if(PrintText(window, "hola mundosss.", 0xFF, 0xFF, 0xFF) < 0)
  {
    fprintf(stderr, "could not write text: %s\n", SDL_GetError());
    return 1;
  }

  while (!quit)
  {
      SDL_WaitEvent(&event);
      switch (event.type)
      {
          case SDL_QUIT:
            quit++;
            break;
          default:
            SDL_UpdateWindowSurface(window);
            break;
      }
  }
    
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;

}