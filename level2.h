
void level2Reset(Pac *man, Nugget *nugs)
{
  SDL_Delay(1500);
  lives--;
  death = false;
  if( lives == 0)
  {
    displayText( "Game Over", levelSign, 350, 150, 60, 0 );
    SDL_Flip( screen );
    SDL_Delay(3000);
    gameOver = true;
  }
  else{ man->reset( 0, 335 ); nugs->reset(); }  // Need to reset bouncing balls
}

void level2Finish()
{
  apply_surface( starRect.x, starRect.y, shiningStarPic, screen );
  if ( check_collision( &starRect, &pacRect ) )
  {
    displayText( "LEVEL 2 COMPLETE!", levelSign, 350, 150, 60, 0 );
    SDL_Flip( screen );
    SDL_Delay(4000);
    lives = 3;
    level_beaten = true;
    gameOver = true;
  }
}

int level2()
{

  load_files_Level2();

  const int NUM_STATICS = 6 ;
  int nugLocations[10][2] = { {100,50}, {215,680}, {920,620}, {456,567},
                       {300,20}, {600,100}, {480,300}, {30,400}, {550,200}, {1000, 300} };

  Ball enemy( &enemyRect, 300, 100, NUM_STATICS ), enemy2( &enemy2Rect, 800, 100, NUM_STATICS ); 
  //enemy3( &enemy3Rect, 300, 400, NUM_STATICS ), enemy4( &enemy4Rect, 600, 300, NUM_STATICS );
  Pac man( 0, 335, 6 );
  Nugget nugs(10);
  Ghost ghost1( 1000, 500, 3.5 ), ghost2( 300, 50, 3.5 ), ghost3( 70, 680, 3.5 );
  Cannon cannon( 500, 300, NUM_STATICS );
  Powerups freeze( 0, 400, 400 );
  myTimer.start();

   //statics
  initRect(&bump1Rect, 500, 100, 50, 15);
  initRect(&bump2Rect, 1000, 350, 50, 15);
  initRect(&longVertRect, 230, 300, 440, 50);
  initRect(&longVert2Rect, 840, 0, 550, 50);
  initRect(&startRect, 0, 325, 50, 50);
  initRect(&starRect, 1140, 20, 50, 50);

  SDL_Rect arrayOfRects2[NUM_STATICS] = { bump1Rect, bump2Rect, longVertRect, longVert2Rect, starRect, startRect };
  accessArray( arrayOfRects2 ); //updates collision box depository for level

  while (!gameOver)
  {
    fps.start();

    if (death){ level2Reset( &man, &nugs ); }    //Resets objects after death

    while( SDL_PollEvent( &event ) )
    {
      man.handle_input();
      if( event.type == SDL_QUIT ){ return true;}
    }

    apply_surface( 0, 0, background, screen );
    apply_surface( startRect.x, startRect.y + 5, startPic, screen );
    displayText( myTimer.formatTime(), timeDisplay, 1000, 0, 30, 0 );
    displayText( "Lives: " + toString(lives) , levelSign, 0, 0, 30, 0 );

    nugs.scan( nugLocations ); //applies surface for all nuggets
    if ( nugs.anyLeft() == true )
    {
      apply_surface( starRect.x, starRect.y, starPic, screen );
    }
    else
    {
      level2Finish();
    }

    apply_surface( longVertRect.x, longVertRect.y, longVertPic, screen );
    apply_surface( longVert2Rect.x, longVert2Rect.y, longVert2Pic, screen );
    apply_surface( bump1Rect.x, bump1Rect.y, padPic, screen );
    apply_surface( bump2Rect.x, bump2Rect.y, padPic, screen );
    freeze.taken();

    if( myTimer.get_ticks() < 3000 ){ displayText( "LEVEL 1!", levelSign, 350, 150, 60, 0 ); }
    else if( myTimer.get_ticks() > 180000 )
    {
      displayText( "Game Over", levelSign, 350, 150, 60, 0 );
    }
    if( myTimer.get_ticks() > 180002 ){ gameOver = true; }

    man.move();

    ghost1.move(); ghost2.move(); ghost3.move();
    cannon.moveShoot();
    enemy.move(); enemy2.move();// enemy3.move(); enemy4.move();

    SDL_Flip( screen );

    if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
    {
      SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
    }
  }

  clean_up2();

  return true;
}
