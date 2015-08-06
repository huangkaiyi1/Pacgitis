

class Gun
{ 
  int x, y;
  int xVel, yVel;
  public:
  bool spent;

  Gun()
  {
    spent = false;
    x = pacRect.x;
    y = pacRect.y;
      std::cout<<x<<std::endl;
  }

  void fire()
  {
    if( !spent && event.type == SDL_MOUSEBUTTONDOWN ){ 
        if( event.button.button == SDL_BUTTON_LEFT )
    {
      xVel = (event.button.x - x);
      yVel = (event.button.y - y);
      spent = true;
      //std::cout<<xVel;
    }}
    if( x > SCREEN_WIDTH || y > SCREEN_HEIGHT )
    { 
      xVel = 0;
      yVel = 0;
      spent = false; 
      //std::cout<<"spent";
    }
    //x += xVel;
      std::cout<<x<<std::endl;
    y += yVel; 
    display();
  }

  void reload(int newX, int newY)
  {
    x = newX;
    y = newY;
  }

  bool isSpent(){ return spent; }

  void display()
  {    
    apply_surface( x, y, cannonballPic, screen );
  }

};




