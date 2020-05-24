/*
 * Menu functions
 */
#ifndef SDLMENU_H
#define SDLMENU_H 1

#define LINE_MAX_LENGTH 81

SDL_Window *current_window = NULL;
int current_y = 0;
int selected_index = -1;

int Render(SDL_Window *window, int mouse_x, int mouse_y, char *title, char *choice, char menu[][LINE_MAX_LENGTH], int count)
{
  
  int y = MARGIN;                              /* Posición vertical (eje y) donde se empieza a pintar la línea*/
  int line_height = 0;
  int selected = 0;
  int i = 0;
  int mouse_detect = 0;
  char menu_entry[LINE_MAX_LENGTH + 20];

  mouse_detect = (mouse_x || mouse_y);

  SetBackgroundColor(window, 0x80, 0x80, 0x80);

  line_height = CalculateTextHeight(window, title, FONT_SIZE * 2, MARGIN); 
  PrintText(window, title, FONT_SIZE * 2, 0, MARGIN, y, 0xFF, 0xFF, 0xFF);  

  y += line_height + MARGIN;

  line_height = CalculateTextHeight(window, choice, FONT_SIZE, MARGIN); 
  PrintText(window, choice, FONT_SIZE, 0, MARGIN, y, 0xFF, 0xFF, 0xFF);  


  do
  {
    y += line_height + MARGIN;

    snprintf (menu_entry, sizeof(menu_entry), "%d) %s", i + 1, menu[i]);

    /* Mido la altura del texto, compruebo si el ratón está encima y lo pinto */
    line_height = CalculateTextHeight(window, menu_entry, FONT_SIZE, MARGIN);
    if (mouse_detect)
    {
      selected = IsMouseOver(mouse_x, mouse_y, MARGIN, y, SCREEN_WIDTH - (MARGIN * 2), line_height);
    }
    else
    {
      selected = (selected_index == i);
    }
    PrintText(window, menu_entry, FONT_SIZE, selected, MARGIN, y, 0xFF, 0xFF, 0xFF);
    
    if (mouse_detect && selected)
    {
      selected_index = i;
    }
  }
  while (++i < count);

  y += line_height + MARGIN;

  SDL_UpdateWindowSurface(window);

  return y;

}

int OptionSelected(int count, int (*handler)(int)) {
  if ( selected_index >= 0 && selected_index < (count - 1) ) {
    int ret = handler (selected_index);
    if (ret != 0)
    {
      /* Salimos si se nos solicita */
      return ret;
    }
  }
  /* La última opcion es salir */
  return (selected_index == (count - 1));
}

void HandleKeypress(SDL_Keycode key, int count, int *quit, int *render, int *select)
{
  *render = 0;
  *select = 0;
  switch(key)
  {
    case SDLK_UP: /* Tecla flecha arriba */
      if (selected_index > 0) 
      {
        selected_index--;
        *render = 1;
      }
    break;
    case SDLK_DOWN: /* Tecla flecha abajo */
      if (selected_index < (count - 1)) 
      {
        selected_index++;
        *render = 1;
      }
    break;
    case SDLK_RETURN:
    case SDLK_RETURN2:
      *render = 1;
      *select = 1;
      break;
    case SDLK_ESCAPE:
      *quit = 1;
      break;
  }
}


int CreateMenu (char *title, char *choice, char menu[][LINE_MAX_LENGTH], int size, int (*handler)(int))
{
  const int count = (size / LINE_MAX_LENGTH) + 1;
  char extended_menu[count][LINE_MAX_LENGTH];
  SDL_Window *window = NULL;
  int initialized = 0;
  int quit = 0;
  int render;
  int select;
  SDL_Event event;

  selected_index = -1;

  if(current_window == NULL)
  {
    if (InitializeSDL() < 0) {
      fprintf(stderr, "could not initialize sdl2: %s\n", SDL_GetError());
      return 1;
    }

    window = SDL_CreateWindow(
            "SDLText Menu",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH, SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN
            );
    
    if (window == NULL) {
      fprintf(stderr, "could not create window: %s\n", SDL_GetError());
      return 1;
    }

    current_window = window;

    initialized = 1;

  }
  else
  {
    window = current_window;
  }

  /* Copio el menú y le añado la opción de salir */
  memcpy((char *)extended_menu, (char *)menu, count * LINE_MAX_LENGTH);
  strncpy(extended_menu[count - 1], "Exit", LINE_MAX_LENGTH);

  current_y = Render(window, 0, 0, title, choice, extended_menu, count);

  while (!quit)
  {
      SDL_WaitEvent(&event);
      switch (event.type)
      {
          case SDL_QUIT:
            quit++;
            break;
          case SDL_MOUSEMOTION:
            current_y = Render(window, event.motion.x, event.motion.y, title, choice, extended_menu, count);
            break;
          case SDL_MOUSEBUTTONUP:
            quit = OptionSelected(count, handler);
            break;
          case SDL_KEYUP: /* Se soltó alguna tecla del teclado */
            HandleKeypress(event.key.keysym.sym, count, &quit, &render, &select);
            if (render)
            {
              current_y = Render(window, 0, 0, title, choice, extended_menu, count);
            }
            if (select)
            {
              quit = OptionSelected(count, handler);
            }
            break;
          default:
            SDL_UpdateWindowSurface(window);
            break;
      }
  }
  
  selected_index = -1;

  if (initialized)
  {
    SDL_DestroyWindow(window);
    SDL_Quit();
  }
  else
  {
    RefreshWindow();
  }

  return 0;

}

void Write(char *text)
{
  int line_height = CalculateTextHeight(current_window, text, FONT_SIZE, MARGIN);
  /* int position = SCREEN_HEIGHT - (line_height + MARGIN); */
  int position = current_y;
  DrawRectangle(current_window, MARGIN - 1, position - 1, SCREEN_WIDTH, line_height + 2,  0x80, 0x80, 0x80);
  PrintText(current_window, text, FONT_SIZE, 0, MARGIN, position, 0xFF, 0xFF, 0xFF);  

  SDL_UpdateWindowSurface(current_window);
}

void WriteLine(char *text)
{
  int line_height = CalculateTextHeight(current_window, text, FONT_SIZE, MARGIN);
  /* int position = SCREEN_HEIGHT - (line_height + MARGIN); */
  int position = current_y;
  DrawRectangle(current_window, MARGIN - 1, position - 1, SCREEN_WIDTH, line_height + 2,  0x80, 0x80, 0x80);
  PrintText(current_window, text, FONT_SIZE, 0, MARGIN, position, 0xFF, 0xFF, 0xFF);  

  current_y += line_height;

  SDL_UpdateWindowSurface(current_window);
}

int ReadNumber () {
  
  char text[10];
  int done = 0;
  int textlen = 0;
  SDL_Event event;
  
  while (!done) {
      /* Check for events */
      while (SDL_PollEvent(&event)) {
          switch(event.type) {
              case SDL_KEYDOWN:
                  switch (event.key.keysym.sym)
                  {
                      case SDLK_ESCAPE:
                      case SDLK_RETURN:
                      case SDLK_RETURN2:
                          done = 1;
                          Write(text);
                          break;
                      case SDLK_BACKSPACE:
                          textlen=SDL_strlen(text);
                          if (textlen == 0)
                          {
                              break;
                          }
                          text[textlen-1]=0x00;
                          Write(text);
                          break;
                    }
              break;
              case SDL_TEXTINPUT:
                  if (SDL_strlen(event.text.text) == 0 || event.text.text[0] == '\n')
                      break;

                  if (SDL_strlen(text) + SDL_strlen(event.text.text) < sizeof(text))
                      SDL_strlcat(text, event.text.text, sizeof(text));

                  Write(text);
              
              break;
          }
          SDL_FlushEvent(event.type);
      }
  }

  char *end;
  int res = strtol (text, &end, 10);
  if (res < 0) {
    res = 0;
  }
  return res;
}

#endif