


void initRect(SDL_Rect *target, int xCoord, int yCoord, int height, int width)
{
  target->x = xCoord;
  target->y = yCoord;
  target->h = height;
  target->w = width;
}


//0 - blue, 1 - black, 2 - red
void displayText( std::string message, SDL_Surface *surface, int x, int y, int fontSize, unsigned short colorKey )
{
  font = TTF_OpenFont( "Alexis.ttf", fontSize );

  switch( colorKey )
  {
    case 0: textColor.r = 0; textColor.g = 119; textColor.b = 255; break;
    case 1: textColor.r = 0; textColor.g = 0; textColor.b = 0; break;
    case 2: textColor.r = 232; textColor.g = 4; textColor.b = 4; break;
  }
  surface = TTF_RenderText_Solid( font, message.c_str(), textColor );
  apply_surface( x, y, surface, screen );
  SDL_FreeSurface( surface );
  TTF_CloseFont( font );
}

std::string toString( int integer )
{
  std::string theString;
  std::stringstream out;
  out << integer;
  theString = out.str();
  return theString;
}



