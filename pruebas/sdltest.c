#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MARGIN 25
#define FONT_SIZE 16

int selected_index = -1;

char texto1[] = "esto es una prueba para ver que pasa cuando el texto es muy largo";
char texto2[] = "esta es otra frase que va a continuacion";

int InitializeSDL() {
  int result = 0;
  result = SDL_Init(SDL_INIT_VIDEO);
  if (result >= 0) {
    result = TTF_Init();
  }
  return result;
}

void DrawRectangle(SDL_Window *window, int x, int y, int w, int h, int r, int g, int b) 
{
  SDL_Surface *screen = SDL_GetWindowSurface(window);
  SDL_Rect rect;
  rect.x = x;
  rect.y = y;
  rect.w = w;
  rect.h = h;
  SDL_FillRect(screen, &rect, SDL_MapRGB(screen->format, r, g, b));
}

void SetBackgroundColor(SDL_Window *window, int r, int g, int b)
{
  SDL_Surface *screen = SDL_GetWindowSurface(window);
  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, r, g, b));
}

void BlitText(SDL_Surface *text_surface, SDL_Surface *screen, SDL_Rect *position)
{
  SDL_BlitSurface( text_surface, NULL, screen, position );
}

void BlitSelectedText(SDL_Surface *text_surface, SDL_Surface *inverted_text_surface, SDL_Surface *screen, SDL_Rect *position)
{
  SDL_Rect selection;
  
  /* Generamos un marco alrededor */
  selection.x = position->x - 1;
  selection.y = position->y - 1;
  SDL_BlitSurface( inverted_text_surface, NULL, screen, &selection );
  selection.x = position->x + 1;
  selection.y = position->y + 1;
  SDL_BlitSurface( inverted_text_surface, NULL, screen, &selection );
  selection.x = position->x - 1;
  selection.y = position->y + 1;
  SDL_BlitSurface( inverted_text_surface, NULL, screen, &selection );
  selection.x = position->x + 1;
  selection.y = position->y - 1;
  SDL_BlitSurface( inverted_text_surface, NULL, screen, &selection );

  /* Ponemos el texto en el medio */
  SDL_BlitSurface( text_surface, NULL, screen, position );
}

int CalculateTextHeight(SDL_Window *window, char* text, int font_size, int x)
{
  int width = 0;
  int height = 0;
  SDL_Surface *screen = SDL_GetWindowSurface(window);
  TTF_Font *font = TTF_OpenFont( "DejaVuSansMono.ttf", font_size );
  SDL_Color color = {0, 0, 0};
  SDL_Surface *text_surface;
  int available_width = SCREEN_WIDTH - (x + MARGIN);

  text_surface = TTF_RenderText_Blended_Wrapped(font, text, color, available_width);

  return text_surface->h;
}

int PrintText(SDL_Window *window, char* text, int font_size, int selected, int x, int y, int r, int g, int b)
{
  int width = 0;
  int height = 0;
  SDL_Surface *screen = SDL_GetWindowSurface(window);
  TTF_Font *font = TTF_OpenFont( "DejaVuSansMono.ttf", font_size );
  SDL_Color color = {r, g, b};
  SDL_Surface *text_surface;
  int available_width = SCREEN_WIDTH - (x + MARGIN);

  text_surface = TTF_RenderText_Blended_Wrapped(font, text, color, available_width);
  if (text_surface != NULL)
  {
      width = text_surface->w;
      height = text_surface->h;
      SDL_Rect position;
      position.x = x;
      position.y = y;
      if (selected == 0) 
      {
        BlitText(text_surface, screen, &position);
      }
      else 
      {
        SDL_Color inverted_color = {0xFF - r, 0xFF - g,  0xFF - b};
        SDL_Surface *inverted_text_surface = TTF_RenderText_Blended_Wrapped(font, text, inverted_color, available_width);
        BlitSelectedText(text_surface, inverted_text_surface, screen, &position);
      }
      SDL_FreeSurface(text_surface);
      return height;
  }
  else
  {
      // report error
      return -1;
  }
}

int IsMouseOver(int mouse_x, int mouse_y, int x, int y, int w, int h)
{
  /* Devolvemos si la posición del ratón se solapa sobre el rectángulo */
  return (!(mouse_x < x || mouse_x > (x + w)) &&
          !(mouse_y < y || mouse_y > (y + h)));
}

int Render(SDL_Window *window, int mouse_x, int mouse_y)
{
  
  int previous_line_height = 0;
  int line_height = 0;
  int selected = 0;
  selected_index = -1;

  SetBackgroundColor(window, 0x80, 0x80, 0x80);

  /* Mido la altura del texto, compruebo si el ratón está encima y lo pinto */
  line_height = CalculateTextHeight(window, texto1, FONT_SIZE, MARGIN);
  selected = IsMouseOver(mouse_x, mouse_y, MARGIN, MARGIN, SCREEN_WIDTH - (MARGIN * 2), line_height);
  PrintText(window, texto1, FONT_SIZE, selected, MARGIN, MARGIN, 0xFF, 0xFF, 0xFF);  

  if (selected)
  {
    selected_index = 0;
  }

  previous_line_height = line_height;
  
  /* Mido la altura del texto, compruebo si el ratón está encima y lo pinto */
  line_height = CalculateTextHeight(window, texto2, FONT_SIZE, MARGIN); 
  selected = IsMouseOver(mouse_x, mouse_y, MARGIN, (MARGIN * 2) + previous_line_height, SCREEN_WIDTH - (MARGIN * 2), line_height);
  PrintText(window, texto2, FONT_SIZE, selected, MARGIN, (MARGIN * 2) + previous_line_height, 0xFF, 0xFF, 0xFF);
  
  if (selected)
  {
    selected_index = 1;
  }

  return 0;

}

void OptionSelected() {
  if ( selected_index >= 0 ) {
    char *msg;
    switch(selected_index)
    {
      case 0:
        msg = texto1;
        break;
      default:
        msg = texto2;
        break;
    }
    SDL_ShowSimpleMessageBox( SDL_MESSAGEBOX_INFORMATION, "Has seleccionado", msg, NULL );
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
			    "sdltest",
			    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			    SCREEN_WIDTH, SCREEN_HEIGHT,
			    SDL_WINDOW_SHOWN
			    );
  
  if (window == NULL) {
    fprintf(stderr, "could not create window: %s\n", SDL_GetError());
    return 1;
  }

  Render(window, 0, 0);

  while (!quit)
  {
      SDL_WaitEvent(&event);
      switch (event.type)
      {
          case SDL_QUIT:
            quit++;
            break;
          case SDL_MOUSEMOTION:
            Render(window, event.motion.x, event.motion.y);
            SDL_UpdateWindowSurface(window);
            break;
          case SDL_MOUSEBUTTONUP:
            OptionSelected();
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