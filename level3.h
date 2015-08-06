void level3Reset(Pac *man, Nugget *nugs)
{
  SDL_Delay(1500);
  lives--;
  death = false;
  if( lives == 0)
  {
    displayText( "Game Over", levelSign, 350, 150, 60, 1 );
    SDL_Flip( screen );
    SDL_Delay(3000);
    gameOver = true;
  }
  else{ man->reset( 0, 660 ); nugs->reset(); }  // Need to reset bouncing balls
}

void level3Finish()
{
  apply_surface( starRect.x, starRect.y, shiningStarPic, screen );
  if ( check_collision( &starRect, &pacRect ) )
  {
    displayText( "LEVEL 3 COMPLETE!", levelSign, 450, 10, 60, 1 );
    SDL_Flip( screen );
    SDL_Delay(4000);
    lives = 3;
    level_beaten = true;
    gameOver = true;
  }
}


int level3()
{
  load_files_Level3();

  const int NUM_STATICS = 7;
  int nugLocations[11][2] = { {300,250}, {215,100}, {920,620}, {1150,600},
                       {300,20}, {800,100}, {1150,300}, {30,210}, {300,680}, {1000, 300}, {1100, 350} };

  initRect( &longVertRect, 370, 380, 325, 5 );
  initRect( &longVert2Rect, 370, 0, 335, 5 );
  initRect( &longVert3Rect, 825, 380, 335, 3 );
  initRect( &longVert4Rect, 860, 0, 335, 5 );
  initRect( &longHorizRect, 0, 380, 15, 335 );
  initRect(&starRect, 580, 330, 40, 40);
  initRect(&startRect, 0, 650, 50, 50);
  myTimer.start();

  SDL_Rect arrayOfRects3[NUM_STATICS] = { longVertRect, longVert2Rect, longVert3Rect, longVert4Rect,
  longHorizRect, starRect, startRect}; 
  accessArray( arrayOfRects3 ); 

  Pac man( 0, 660, NUM_STATICS );
  Nugget nugs(11);
  Cannon cannonT( 600, 600, NUM_STATICS );
  Ball enemy( &enemyRect, 0, 250, NUM_STATICS );
  Ball enemy2( &enemy2Rect, 300, 200, NUM_STATICS );
  Ball enemy3( &enemy3Rect, 300, 50, NUM_STATICS );
  Ghost ghost1( 500, 100, 3.5 ), ghost2( 700, 600, 3.5 );

  Blackhole ahole( 1150, 350, 300 );
  Powerups fast( 1, 800, 350 );
  Powerups teleport( 5,15, 1100,15 );

  while ( !gameOver ) 
  {
    fps.start();

    if (death){ level3Reset( &man, &nugs ); } 

    while( SDL_PollEvent( &event ) )
    {
      man.handle_input();
      if( event.type == SDL_QUIT ){ clean_up3(); return true; }
    }

    apply_surface( 0, 0, background, screen );
    apply_surface( startRect.x, startRect.y + 5, startPic, screen );
    apply_surface( starRect.x, starRect.y, starPic, screen );
    displayText( myTimer.formatTime(), timeDisplay, 1000, 0, 30, 2 );
    displayText( "Lives: " + toString(lives) , levelSign, 0, 0, 30, 2 );

    nugs.scan( nugLocations ); 
    if ( nugs.anyLeft() == true )
    {
      apply_surface( starRect.x, starRect.y, starPic, screen );
    }
    else
    {
      level3Finish();
    }

    apply_surface( longVertRect.x, longVertRect.y, longVertPic , screen );
    apply_surface( longVert2Rect.x, longVert2Rect.y, longVertPic , screen );
    apply_surface( longVert3Rect.x, longVert3Rect.y, longVertPic , screen );
    apply_surface( longVert4Rect.x, longVert4Rect.y, longVertPic , screen );
    apply_surface( longHorizRect.x, longHorizRect.y, longHorizPic , screen );

    ahole.suck();
    fast.taken();
    teleport.taken();

    if( myTimer.get_ticks() < 3000 ){ displayText( "LEVEL 3!", levelSign, 450, 10, 60, 1 ); }
    else if( myTimer.get_ticks() > 180000 )
    {
      displayText( "Game Over", levelSign, 450, 10, 60, 1 );
    }
    if( myTimer.get_ticks() > 180002 ){ gameOver = true; }

    man.move();
    enemy.move(); enemy2.move(); enemy3.move();
    cannonT.moveShoot(); 
    ghost1.move(); ghost2.move();

    SDL_Flip( screen );
    if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
    {
      SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
    }

  }
  clean_up3();
  return true;
}
  
