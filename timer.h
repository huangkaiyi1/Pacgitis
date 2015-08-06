

class Timer
{
  private:
  int startTicks;
  int pausedTicks;
  bool paused;
  bool started;

  public:
  Timer()
  {
    startTicks = 0;
    pausedTicks = 0;
    paused = false;
    started = false;
  }

  //The various clock actions
  void start()
  {
    started = true;
    paused = false;
    startTicks = SDL_GetTicks();
  }

  void stop()
  {
    started = false;
    paused = false;
  }

  void pause()
  {
    if( ( started == true ) && ( paused == false ) )
    {
      paused = true;
      pausedTicks = SDL_GetTicks() - startTicks;

    }
  }

  void unpause()
  {
    if( paused == true )
    {
        paused = false;
        startTicks = SDL_GetTicks() - pausedTicks;
        pausedTicks = 0;
    }
  }


  int get_ticks()
  {
    if( started == true )
    {
      if( paused == true ){return pausedTicks;}
      else{ return SDL_GetTicks() - startTicks; }
    }
  }

  std::string formatTime()
  {
    std::string result;
    int min = get_ticks()/60000;
    int sec = get_ticks()%60000;
    sec = sec - sec%100; 
    std::stringstream one, two;

    one << min;
    two << sec;
    result = "Time: " + one.str() + " : " + two.str();
    result = result.substr ( 0, result.length()-2); //Erase extra zeroes
    return ( result ); 
  }
  
  int get_startTicks(){ return startTicks; }
  bool isPaused(){ return paused; }
  bool isStarted(){ return started; }

};

