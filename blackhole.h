
class Blackhole
{
  public:
  int suck_radius;
  int suckPower;
  unsigned short count;
  SDL_Rect thisRect;
  
  Blackhole( int X, int Y, int radius )
  {
    initRect( &thisRect, X, Y, 50, 50 );
    suck_radius = radius;
    suckPower = 3;
    count = 1;
  }

  void suck()
  {
    int centerX = thisRect.x + 25;
    int centerY = thisRect.y + 25;
    int pacCenterX = pacRect.x + 10;
    int pacCenterY = pacRect.y + 10;
    if ( abs(pacCenterX-centerX) < suck_radius && abs(pacCenterY-centerY) < suck_radius )
    {
      if( (pacCenterX - centerX) > 0 ){ pacRect.x -= suckPower; }
      else{ pacRect.x += suckPower; }
      if( (pacCenterY - centerY) > 0 ){ pacRect.y -= suckPower; }
      else{ pacRect.y += suckPower; }
    }
    if ( check_collision(&pacRect, &thisRect) ){ death = true; }
    display();
  }

  void display()
  {
    switch( count )
    {
      case 1: apply_surface( thisRect.x, thisRect.y, wheel1Pic , screen ); break;
      case 2: apply_surface( thisRect.x, thisRect.y, wheel2Pic , screen ); break;
      case 3: apply_surface( thisRect.x, thisRect.y, wheel3Pic , screen ); break;
      case 4: apply_surface( thisRect.x, thisRect.y, wheel4Pic , screen ); break;
    }
    count++;
    if( count == 5 ){ count = 1; }
  }

};



      
