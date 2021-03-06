
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 700;
const int SCREEN_BPP = 32;
const int FRAMES_PER_SECOND = 30;

const int DOT_CIRCUM = 20; //actually 20 pixels mostly
const int NUGGET_SIZE = 15;


Timer myTimer, fps; //Former for the in-game clock, latter regulate fps


// Game logic attributes
short lives = 10;
bool death = false;
bool gameOver = false; //Lose all lives or level beaten
bool level_beaten = false; //Allows access to next level when true
double enemySpeed = 6;
double pacSpeed = 7;


SDL_Surface *pacPic_UP = NULL;
SDL_Surface *pacPic_DOWN = NULL;
SDL_Surface *pacPic_LEFT = NULL;
SDL_Surface *pacPic_RIGHT = NULL;
SDL_Surface *ballPic = NULL;
SDL_Surface *bounceBallPic = NULL;
SDL_Surface *seekGhostPic = NULL;
SDL_Surface *cannonPic = NULL;
SDL_Surface *cannonballPic = NULL;
SDL_Surface *explosion1Pic = NULL;
SDL_Surface *explosion2Pic = NULL;
SDL_Surface *explosion3Pic = NULL;

//powerups
SDL_Surface *freezePic = NULL;
SDL_Surface *speedPic = NULL;
SDL_Surface *teleportPic = NULL;

//statics
SDL_Surface *wheel1Pic = NULL;
SDL_Surface *wheel2Pic = NULL;
SDL_Surface *wheel3Pic = NULL;
SDL_Surface *wheel4Pic = NULL;
SDL_Surface *starPic = NULL;
SDL_Surface *shiningStarPic = NULL;
SDL_Surface *nuggetPic = NULL;
SDL_Surface *longHorizPic = NULL;
SDL_Surface *longVert2Pic = NULL;
SDL_Surface *longVertPic = NULL;
SDL_Surface *padPic = NULL;
SDL_Surface *startPic = NULL;
SDL_Surface *screen = NULL;
SDL_Surface *background = NULL;

//text
SDL_Surface *timeDisplay = NULL;
SDL_Surface *levelSign = NULL;

SDL_Event event;

TTF_Font *font = NULL;
SDL_Color textColor;

                                //Game objects
//statics
SDL_Rect startRect, starRect;
SDL_Rect bump1Rect, bump2Rect, longHorizRect, longHoriz2Rect, longVertRect, longVert2Rect, longVert3Rect, longVert4Rect; 

//enemies
SDL_Rect enemyRect, enemy2Rect, enemy3Rect, enemy4Rect;

SDL_Rect pacRect;

