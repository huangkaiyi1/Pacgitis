

SDL_Surface *load_image( std::string filename )
{
  SDL_Surface* loadedImage = NULL;
  SDL_Surface* optimizedImage = NULL;

  loadedImage = IMG_Load( filename.c_str() );
  if( loadedImage != NULL )
  {
    optimizedImage = SDL_DisplayFormat( loadedImage );
    SDL_FreeSurface( loadedImage );
      if( optimizedImage != NULL )
      {
        Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 255, 255, 255 );
        SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
      }
  }
  return optimizedImage;
}

bool init()
{
  if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ) { return false; }
  screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
  if( screen == NULL ){return false;}
  return true;
}

void load_files_global()
{
  startPic = SDL_LoadBMP( "globalPics/startBox.bmp" );
  nuggetPic = load_image( "globalPics/nugget.png" );
  freezePic = load_image( "globalPics/ice.png" );
  speedPic = load_image( "globalPics/speedUp.png" );
  teleportPic = load_image( "globalPics/teleport.png" ); 
  starPic = load_image( "globalPics/star.png" );
  shiningStarPic = load_image( "globalPics/shiningStar.png" );

  seekGhostPic = load_image( "globalPics/ghost.png" );

  pacPic_UP = load_image( "globalPics/pac_UP.png" );
  pacPic_DOWN = load_image( "globalPics/pac_DOWN.png" );
  pacPic_LEFT = load_image( "globalPics/pac_LEFT.png" );
  pacPic_RIGHT = load_image( "globalPics/pac_RIGHT.png" );
}

void load_files_menu()
{
  background = SDL_LoadBMP( "globalPics/menuBack.bmp" );
  ballPic = load_image( "globalPics/dot.png" );
}

void load_files_Level1()
{
  SDL_WM_SetCaption( "PACGITIS Level 1", NULL );
  background = load_image( "pics1/skyBack.png" );
  bounceBallPic = load_image( "pics1/dodge.png" );
  ballPic = SDL_LoadBMP( "pics2/angry.bmp" );
  longHorizPic = load_image( "pics1/horiz_Level3.png" );
  longVertPic = load_image( "pics1/vert_Level3.png" );
  wheel1Pic = load_image( "pics3/wheel1.png" );
  wheel2Pic = load_image( "pics3/wheel2.png" );
  wheel3Pic = load_image( "pics3/wheel3.png" );
  wheel4Pic = load_image( "pics3/wheel4.png" );

}

void load_files_Level2()
{
  SDL_WM_SetCaption( "PACGITIS Level 2", NULL );
  
  background = load_image( "pics2/background.png" );
  padPic = SDL_LoadBMP( "pics2/pad.bmp" );
  longVertPic = load_image( "pics2/longVert.png" );
  longVert2Pic = load_image( "pics2/longVert2.png" );
  ballPic = SDL_LoadBMP( "pics2/angry.bmp" );
  cannonPic = load_image( "pics2/cannon.png" );
  cannonballPic = load_image( "pics2/cannonball.png" );
  explosion1Pic = load_image( "pics2/explosion1.png" );
  explosion2Pic = load_image( "pics2/explosion2.png" );
  explosion3Pic = load_image( "pics2/explosion3.png" );
}

void load_files_Level3()
{
  SDL_WM_SetCaption( "PACGITIS Level 3", NULL );
  background = load_image( "pics3/greenbackground.png" );
  longVertPic = load_image( "pics3/level2_Vert.png" );
  longHorizPic = load_image( "pics3/long_horizon.png" );
  ballPic = load_image( "pics3/ball_level2.png" );
  cannonPic = load_image( "pics3/cannon_level2.png" );
  cannonballPic = load_image( "pics3/cannonball.png" );
  explosion1Pic = load_image( "pics3/explosion1.png" );
  explosion2Pic = load_image( "pics3/explosion2.png" );
  explosion3Pic = load_image( "pics3/explosion3.png" );
  wheel1Pic = load_image( "pics3/wheel1.png" );
  wheel2Pic = load_image( "pics3/wheel2.png" );
  wheel3Pic = load_image( "pics3/wheel3.png" );
  wheel4Pic = load_image( "pics3/wheel4.png" );
}




void apply_surface( int x, int y, SDL_Surface *source, SDL_Surface *destination, SDL_Rect* clip = NULL ) {
 SDL_Rect offset;
 offset.x = x;
 offset.y = y;
 SDL_BlitSurface( source, NULL, destination, &offset);
}

void clean_up_global()
{
  SDL_FreeSurface( background );
  SDL_FreeSurface( startPic );
  SDL_FreeSurface( nuggetPic );
  SDL_FreeSurface( freezePic );
  SDL_FreeSurface( speedPic );
  SDL_FreeSurface( teleportPic );
  SDL_FreeSurface( starPic ); 
  SDL_FreeSurface( shiningStarPic );  
  
  SDL_FreeSurface( seekGhostPic );

  SDL_FreeSurface( pacPic_UP );
  SDL_FreeSurface( pacPic_DOWN );
  SDL_FreeSurface( pacPic_LEFT );
  SDL_FreeSurface( pacPic_RIGHT );
}

void clean_upMenu()
{
  SDL_FreeSurface( background );
  SDL_FreeSurface( ballPic );
}

void clean_up1()
{
  SDL_FreeSurface( background );
  SDL_FreeSurface( bounceBallPic );
  SDL_FreeSurface( ballPic );
  SDL_FreeSurface( longHorizPic );
  SDL_FreeSurface( longVertPic );
  SDL_FreeSurface( wheel1Pic );
  SDL_FreeSurface( wheel2Pic );
  SDL_FreeSurface( wheel3Pic );
  SDL_FreeSurface( wheel4Pic );
}

void clean_up2()
{
  SDL_FreeSurface( background );
  SDL_FreeSurface( padPic );
  SDL_FreeSurface( longVertPic );
  SDL_FreeSurface( longVert2Pic );
  SDL_FreeSurface( ballPic );
  SDL_FreeSurface( seekGhostPic );
  SDL_FreeSurface( cannonPic );
  SDL_FreeSurface( cannonballPic );
  SDL_FreeSurface( explosion1Pic );
  SDL_FreeSurface( explosion2Pic );
  SDL_FreeSurface( explosion3Pic ); 
}

void clean_up3()
{
  SDL_FreeSurface( background );
  SDL_FreeSurface( longVertPic );
  SDL_FreeSurface( longHorizPic );
  SDL_FreeSurface( ballPic );
  SDL_FreeSurface( cannonPic );
  SDL_FreeSurface( cannonballPic );
  SDL_FreeSurface( explosion1Pic );
  SDL_FreeSurface( explosion2Pic );
  SDL_FreeSurface( explosion3Pic );
  SDL_FreeSurface( wheel1Pic );
  SDL_FreeSurface( wheel2Pic );
  SDL_FreeSurface( wheel3Pic );
  SDL_FreeSurface( wheel4Pic );
}





