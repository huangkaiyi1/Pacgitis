

class Cannon
{
  public:
  const int CANNON_DIMEN;
  int yVel, numStatics;
  SDL_Rect thisRect;
Cannonball upLeft, upRight, lowLeft, lowRight;

  Cannon(int xCoord, int yCoord, int statics ): CANNON_DIMEN(40), 
         upLeft( thisRect.x, thisRect.y, -enemySpeed *2, -enemySpeed *2 ),
         upRight( thisRect.x + CANNON_DIMEN, thisRect.y, enemySpeed *2, -enemySpeed *2 ),
         lowLeft( thisRect.x, thisRect.y + CANNON_DIMEN, -enemySpeed *2, enemySpeed *2 ),
	 lowRight( thisRect.x + CANNON_DIMEN, thisRect.y + CANNON_DIMEN, enemySpeed *2, enemySpeed *2 )
  {
    numStatics = statics;
    yVel = enemySpeed;
    initRect( &thisRect, xCoord, yCoord, CANNON_DIMEN, CANNON_DIMEN );
  }

  void shoot()
  {
    if( upLeft.isExploded() ){ upLeft.posUpdate( thisRect.x, thisRect.y ); }
    else{ upLeft.fire(); }
    if( upRight.isExploded() ){ upRight.posUpdate( thisRect.x + CANNON_DIMEN, thisRect.y ); }
    else{ upRight.fire(); }
    if( lowLeft.isExploded() ){ lowLeft.posUpdate( thisRect.x, thisRect.y + CANNON_DIMEN ); }
    else{ lowLeft.fire(); }
    if( lowRight.isExploded() ){ lowRight.posUpdate( thisRect.x + CANNON_DIMEN, thisRect.y + CANNON_DIMEN ); }
    else{ lowRight.fire(); }
  }


  bool collision()
  {
    for ( int i = 0; i < numStatics; i++ )
    {
      if ( check_collision( &curArrayOfRects[i], &thisRect ) ){return true;}
    }
  }

  void moveShoot()
  {

    if( (thisRect.y <= 0) || (thisRect.y + CANNON_DIMEN >= SCREEN_HEIGHT) || collision() )
    { 
      yVel *= -1; 
    }
    if ( enemySpeed != 0 ){ thisRect.y += yVel; }
  
    display();
    shoot();
  }
  
  void display()
  {
    apply_surface( thisRect.x, thisRect.y, cannonPic, screen ); 
  }
};






