//These dudes move toward you when you're in their radius
//No Rects required because they go through everything

class Ghost
{
  public:
  unsigned short ghostHeight, ghostWidth;
  int startx, starty;
  int xVel, yVel;
  int targetx, targety; 
  int range; //field within which pacman will be chased
  double speed;
  SDL_Rect thisRect;
  Ghost( int startingx, int startingy, double ghostSpeed )
  {
    ghostHeight = DOT_CIRCUM - 5;
    ghostWidth = DOT_CIRCUM - 5;
    startx = startingx;
    starty = startingy;
    initRect( &thisRect, startx, starty, ghostHeight, ghostWidth );

    speed = ghostSpeed;
    range = 250;
    xVel = 0;
    yVel = 0;
  }

  void seek()
  {
    targetx = pacRect.x + ( pacRect.w / 2 ); //Center of pacman
    targety = pacRect.y + ( pacRect.h / 2 );

    if ( abs(targetx-startx) < range && abs(targety-starty) < range ) //See if pacman is in radius
    {
      if( (targetx - thisRect.x) > 0 ){ xVel = speed; }
      else{ xVel = -speed; }
      if( (targety - thisRect.y) > 0 ){ yVel = speed; }
      else{ yVel = -speed; }
    }
    else
    {
      xVel = 0;
      yVel = 0;
    }
  }  

  void move()
  {
    seek();
    if (enemySpeed == 0){ xVel = yVel = 0; }
    thisRect.x += xVel;
    thisRect.y += yVel;
    if ( check_collision(&pacRect, &thisRect) )
    { 
      death = true;
      thisRect.x = startx;
      thisRect.y = starty;
    }
    if ( check_collision( &startRect, &thisRect ) )
    {
      thisRect.x -= xVel;
      thisRect.y -= yVel;
    }
    
    display();
  }

  void display()
  {
    apply_surface( thisRect.x, thisRect.y, seekGhostPic, screen );
  }

};







  
