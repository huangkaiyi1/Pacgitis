SDL_Rect *curArrayOfRects;

void accessArray( SDL_Rect curArray[] )
{
  curArrayOfRects = curArray;
}

bool check_collision(SDL_Rect *targetRect, SDL_Rect *meRect)
  {
    //Rect checked against
    int leftA = targetRect->x;
    int rightA = targetRect->x + targetRect->w;
    int topA = targetRect->y;
    int bottomA = targetRect->y + targetRect->h;
    //My rect
    int leftB = meRect->x;
    int rightB = meRect->x + meRect->w;
    int topB = meRect->y;
    int bottomB = meRect->y + meRect->h;

    if( bottomA <= topB ){return false;}
    if( topA >= bottomB ){return false;}
    if( rightA <= leftB ){return false;}
    if( leftA >= rightB ){return false;}
    return true;
  }
