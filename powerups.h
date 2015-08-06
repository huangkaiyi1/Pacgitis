// 0 - freeze, 1 - speed, 2 - teleport
struct aPowerupStruct
{
  int x, y;
  bool taken;
  int whenTaken;
};

class Powerups
{
  public:
  const int POWER_DIMEN;
  //const int NUM_FREEZE;
  //const int NUM_SPEEDUP;
  int ID;
  int duration;
  int speedHolder;
  int destX, destY;
  aPowerupStruct aPowerup;
  Powerups( int identity, int x, int y ): POWER_DIMEN(18)
  {
    duration = 4000; 
    ID = identity;
    switch(ID)
    {
      case 0: speedHolder = enemySpeed; break;
      case 1: speedHolder = pacSpeed; break;
    }
    aPowerup.x = x;
    aPowerup.y = y;
    aPowerup.taken = false;
  }

  Powerups( int x, int y, int toX, int toY ): POWER_DIMEN(18)
  {
    ID = 2;
    destX = toX;
    destY = toY;
    aPowerup.x = x;
    aPowerup.y = y;
    aPowerup.taken = false;
  }

  void freeze()
  {
    if( SDL_GetTicks() - aPowerup.whenTaken < duration ){ enemySpeed = 0; }
    else{ enemySpeed = speedHolder; }
  }

  void pacSpeedup()
  {
    if( SDL_GetTicks() - aPowerup.whenTaken < duration ){ pacSpeed = speedHolder * 2; }
    else{ pacSpeed = speedHolder; }
  }

  void teleport()
  {
    pacRect.x = destX;
    pacRect.y = destY;
  }

  void taken_check()
  {
    int xCenter = aPowerup.x + (POWER_DIMEN/2); //center of nugget
    int yCenter = aPowerup.y + (POWER_DIMEN/2); 
    if( xCenter < (pacRect.x + pacRect.w) && xCenter > pacRect.x 
        && yCenter < (pacRect.y + pacRect.h) && yCenter > pacRect.y && (aPowerup.taken == false) )
      {
	aPowerup.whenTaken = SDL_GetTicks(); 
	aPowerup.taken = true;
      } 
  }

  void taken()
  {
    taken_check();
    if ( aPowerup.taken == false )
    {    
      switch(ID)
      {
	case 0: apply_surface( aPowerup.x, aPowerup.y, freezePic, screen ); break;
	case 1: apply_surface( aPowerup.x, aPowerup.y, speedPic, screen ); break;
        case 2: apply_surface( aPowerup.x, aPowerup.y, teleportPic, screen ); break;
      }
    }
    else
    {
      switch(ID)
      {
	case 0: freeze(); break;
	case 1: pacSpeedup(); break;
	case 2: teleport(); ID = -1; break;
      }
    }
  }

};
      








