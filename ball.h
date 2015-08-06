

class Ball
{
  public:
  int x, y, numStatics;
  double xVel, yVel;
  SDL_Rect *thisRect;

  Ball( SDL_Rect *identity = NULL, int startx = 0, int starty = 0, int statics = 0 )
  {
    thisRect = identity;
    initRect( thisRect, startx, starty, DOT_CIRCUM, DOT_CIRCUM );
    numStatics = statics;

    xVel = -enemySpeed;
    yVel = enemySpeed;
  }


  bool collision()
  {
    for ( int i = 0; i < numStatics; i++ )
    {
      if ( check_collision( &curArrayOfRects[i], thisRect ) ){return true;}
    }
    if ( (thisRect != &enemyRect) && check_collision(&enemyRect, thisRect ) ){return true;}
    if ( (thisRect != &enemy2Rect) && check_collision(&enemy2Rect, thisRect ) ){return true;}
    if ( (thisRect != &enemy3Rect) && check_collision(&enemy3Rect, thisRect ) ){return true;}
    if ( (thisRect != &enemy4Rect) && check_collision(&enemy4Rect, thisRect ) ){return true;}
  }

 
  void move()
  {
    double variance = SDL_GetTicks()%2;
    if ( enemySpeed != 0 )
    {
      if ( xVel>0 ){ xVel = enemySpeed + variance;} 
      if ( yVel<0 ){ yVel = -enemySpeed + variance;}
      thisRect->x += xVel;
      thisRect->y += yVel;
    }

    if( (thisRect->x <= 0) || (thisRect->x + DOT_CIRCUM >= SCREEN_WIDTH) || collision() )
    { 
      xVel *= -1; 
      thisRect->x += xVel;
    }
    if( (thisRect->y <= 0) || (thisRect->y + DOT_CIRCUM >= SCREEN_HEIGHT) || collision() )
    { 
      yVel *= -1; 
      thisRect->y += yVel;
    }
    

    //If pacman is touched, he dies and level restarts
    if ( check_collision(&pacRect, thisRect) ){ death = true; } 
    
    display();
  }


  void display()
  {
    apply_surface( thisRect->x, thisRect->y, ballPic, screen ); 
  }

};






