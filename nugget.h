
class Nugget
{
  public:
  int len;
  std::vector<bool> left;
  Nugget( int numNuggets ): left(10)
  {
    len = numNuggets;
    for( int i = 0; i<len; i++ ){ left[i] = 1; }
  }

  bool eaten_check( int x, int y )
  {
    x = x + 2; //set to nugget's center
    y = y + 2;
    if( x < (pacRect.x + pacRect.w) && x > pacRect.x )
    {
      if( y < (pacRect.y + pacRect.h) && y > pacRect.y ){return true;}
    }
    return false;
  }

  void scan( int location[][2] )
  {
    for ( int i=0; i<len; i++ )
    {
      if ( left[i] == 1 && eaten_check(location[i][0], location[i][1] ) != true )
      {
	apply_surface( location[i][0], location[i][1], nuggetPic, screen );
      }
      else
      {
        left[i] = 0;
      }
    }
  }


  bool anyLeft()
  {
    for ( int i=0; i<len; i++ )
    {
      if( left[i] == 1 ){ return true; }
    }
    return false;
  }

  void reset()
  {
    for ( int i=0; i<len; i++ )
    {
      left[i] = 1;
    }
  }

};



