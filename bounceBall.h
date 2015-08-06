
class Bounceball
{
  public:
  //int x,y;
  double speed, speedScale;
  int screenCenterX, screenCenterY;
  int patrolRadius;
  int bounceLen, bounceTriang;
  SDL_Rect thisRect;
  
  Bounceball( int X, int Y, double ballSpeed )
  {
    speed = ballSpeed; 
    speedScale = (0.001*M_PI)*speed;
    patrolRadius = 90;
    screenCenterX = SCREEN_WIDTH/2;
    screenCenterY = SCREEN_HEIGHT/2 - 55;
    bounceLen = 90;
    bounceTriang = bounceLen/sqrt(2);

    initRect( &thisRect, X-5, Y-5, bounceLen, bounceLen );
  }

  void bounce( SDL_Rect *bouncedRect )
  {
    if( bouncedRect->y < thisRect.y + 20)
    {
      if( bouncedRect->x < thisRect.x + 20 ){ bouncedRect->x -= bounceTriang; bouncedRect->y -= bounceTriang; }
      else if( bouncedRect->x > thisRect.x + 70 ){ bouncedRect->x += bounceTriang; bouncedRect->y -= bounceTriang; }
      else{ bouncedRect->y -= bounceLen; }
    }
    else if( bouncedRect->y > thisRect.y + 70 )
    {
      if( bouncedRect->x < thisRect.x + 20 ){ bouncedRect->x -= bounceTriang; bouncedRect->y += bounceTriang; }
      else if( bouncedRect->x > thisRect.x + 70 ){ bouncedRect->x += bounceTriang; bouncedRect->y += bounceTriang; }
      else{ bouncedRect->y += bounceLen; }
    }
    else
    {
      if( bouncedRect->x < thisRect.x + 20 ){ bouncedRect->x -= bounceLen; }
      else if( bouncedRect->x > thisRect.x + 70 ){ bouncedRect->x += bounceLen; }
    }
  }
      
  
  void collision()
  {
    if( check_collision(&enemyRect, &thisRect ) ){ bounce(&enemyRect); }
    if( check_collision(&enemy2Rect, &thisRect ) ){ bounce(&enemy2Rect); }
    if( check_collision(&enemy3Rect, &thisRect ) ){ bounce(&enemy3Rect); }
    if( check_collision(&enemy4Rect, &thisRect ) ){ bounce(&enemy4Rect); }
    if( check_collision(&pacRect, &thisRect ) ){ bounce(&pacRect); }
  }


  void move()
  {
    double angle = SDL_GetTicks() * speedScale;
    thisRect.x = screenCenterX + sin(angle)*patrolRadius;
    thisRect.y = screenCenterY + cos(angle)*patrolRadius;
    collision();
    display();
  }

  void display()
  {
    apply_surface( thisRect.x, thisRect.y, bounceBallPic, screen ); 
  }

};




