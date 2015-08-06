
class Pac
{
  public:
    SDL_Rect thisRect;
    double xVel, yVel;
    unsigned short orient;
    int numStatics;
    //Gun theGun;

  Pac( int x, int y, int statics )
  {
     //starting position
    thisRect.h = DOT_CIRCUM;
    thisRect.w = DOT_CIRCUM;
    thisRect.x = x;
    thisRect.y = y;
    pacRect = thisRect;

    xVel = 0;
    yVel = 0;
    orient = 4;
    numStatics = statics;
  }


  void handle_input()
  {
    if( event.type == SDL_KEYDOWN )
    {
      switch( event.key.keysym.sym )
      {
        case SDLK_UP: yVel -= pacSpeed; orient = 1; break;
        case SDLK_DOWN: yVel += pacSpeed; orient = 2; break;
        case SDLK_LEFT: xVel -= pacSpeed; orient = 3; break;
        case SDLK_RIGHT: xVel += pacSpeed; orient = 4; break;
      }
    }
    else if( event.type == SDL_KEYUP )
    {
      switch( event.key.keysym.sym )
      {
        case SDLK_UP: yVel = 0; break;
        case SDLK_DOWN: yVel = 0; break;
        case SDLK_LEFT: xVel = 0; break;
        case SDLK_RIGHT: xVel = 0; break;
      }
    }

    //shoot();
  }

  bool collision()
  {
    for ( int i = 0; i < numStatics - 2 /*accounts for startbox/starbox*/; i++ )
    {
      if ( check_collision( &curArrayOfRects[i], &thisRect ) ){return true;}
    }
	return false;
  }


  void move()
  {
    thisRect.x = pacRect.x;
    thisRect.y = pacRect.y;
    thisRect.x += xVel;
    thisRect.y += yVel;
    if( ( thisRect.x < 0 ) || ( thisRect.x + 20 > SCREEN_WIDTH ) ||
        collision() ){ thisRect.x -= xVel;}
    if( ( thisRect.y < 0 ) || ( thisRect.y + 18 > SCREEN_HEIGHT ) ||
        collision() ){ thisRect.y -= yVel;}
    pacRect.x = thisRect.x;
    pacRect.y = thisRect.y;
    display();
  }

  void setLocation( int x, int y)
  {
    thisRect.x = x;
    thisRect.y = y;
  }

  /*void shoot()
  {
    if( !theGun.isSpent() )
    {
      theGun.reload( pacRect.x, pacRect.y );
      theGun.fire();
    }
  }*/


  void reset( int x, int y )
  {
    pacRect.x = x;
    pacRect.y = y;
    orient = 4;
  }


  // 1-up, 2-down, 3-left, 4-right
  void display()
  {
    switch(orient)
    {
      case 1: apply_surface( pacRect.x, pacRect.y, pacPic_UP, screen ); break;
      case 2: apply_surface( pacRect.x, pacRect.y, pacPic_DOWN, screen ); break;
      case 3: apply_surface( pacRect.x, pacRect.y, pacPic_LEFT, screen ); break;
      case 4: apply_surface( pacRect.x, pacRect.y, pacPic_RIGHT, screen ); break;
    }
  }
    


};


