/*
 * Simplified SDL layer.
 */
#ifndef SDLBASE_H
#define SDLBASE_H 1

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MARGIN 25
#define FONT_SIZE 16

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

int CalculateTextHeight(SDL_Window *window, char *text, int font_size, int x)
{
  int width = 0;
  int height = 0;
  SDL_Surface *screen = SDL_GetWindowSurface(window);
  TTF_Font *font = TTF_OpenFont( "DejaVuSansMono.ttf", font_size );
  if (!font)
  {
    return -1;
  }
  SDL_Color color = {0, 0, 0};
  SDL_Surface *text_surface;
  int available_width = SCREEN_WIDTH - (x + MARGIN);
  text_surface = TTF_RenderUTF8_Blended_Wrapped(font, text, color, available_width);

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

  text_surface = TTF_RenderUTF8_Blended_Wrapped(font, text, color, available_width);
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
        SDL_Surface *inverted_text_surface = TTF_RenderUTF8_Blended_Wrapped(font, text, inverted_color, available_width);
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

int RefreshWindow()
{
  SDL_Event event;
  event.type = SDL_MOUSEMOTION;
  event.motion.x = 0;
  event.motion.y = 0;
  SDL_PushEvent(&event);
}

#endif