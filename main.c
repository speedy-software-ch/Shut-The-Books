#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>

SDL_Surface *back;
SDL_Surface *image;
SDL_Surface *buch1;
SDL_Surface *buch2;
SDL_Surface *Kusit1;
SDL_Surface *screen;
SDL_Surface *p1;
SDL_Surface *p2;
SDL_Surface *p3;
SDL_Surface *GameOver;
SDL_Surface *PressSpace;

void DrawIMG();
int InitImages();
void DrawBG();
void DrawPen();
void DrawPen1();
void DrawPen2();
void Point1();
void Point2();
void Point3();
void Point0();

int xpos=275,ypos=402;
int j=0;
int f=0;
int h=0;
int b=0;
int w=-800;
int w2=-800;
int PenB=1;
int buecher=0;
int points=3;

int InitImages()
{
  back = SDL_LoadBMP("BGNew.bmp");
  image = SDL_LoadBMP("image.bmp");
  buch1 = SDL_LoadBMP("Buch1.bmp");
  buch2 = SDL_LoadBMP("Buch2.bmp");
  Kusit1 = SDL_LoadBMP("Bleistift.bmp");
  p1 = SDL_LoadBMP("01.bmp");
  p2 = SDL_LoadBMP("02.bmp");
  p3 = SDL_LoadBMP("03.bmp");
  GameOver = SDL_LoadBMP("GameOver.bmp");
  PressSpace= SDL_LoadBMP("PressSpace.bmp");  
  return 0;
}
                
void DrawIMG(SDL_Surface *img, int x, int y)
{
  SDL_Rect dest;
  dest.x = x;
  dest.y = y;
  SDL_BlitSurface(img, NULL, screen, &dest);
}

void DrawIMG(SDL_Surface *img, int x, int y,
                                int w, int h, int x2, int y2)
{
  SDL_Rect dest;
  dest.x = x;
  dest.y = y;
  SDL_Rect dest2;
  dest2.x = x2;
  dest2.y = y2;
  dest2.w = w;
  dest2.h = h;
  SDL_BlitSurface(img, &dest2, screen, &dest);
}


void DrawBG()
{
  DrawIMG(back, 0, 0);
}

void DrawScene();

void DrawScene()
{
                            if(w<0)
     {
                  w=w+10;
             DrawIMG(back,0,w);
             }
             else
             {
                 if(w2<0)
                 {
                  w2=w2+10;
                  w=w+10;
                  DrawIMG(back,0,w2);
                  DrawIMG(back,0,w);
                  }
                  else
                  {
                      w=-800;
                      DrawIMG(back,0,w);
                      }
                 }           
                            if(points==1)
                                                        {
                                                        Point1();
                                                        }
                                                        if(points==2)
                                                        {
                                                                     Point2();
                                                                     }
                                                                     if(points==3)
                                                                     {
                                                                                  Point3();
                                                                                  }
     SDL_SetColorKey(image, SDL_SRCCOLORKEY, 
                           SDL_MapRGB(image->format, 255, 0, 0));
  DrawIMG(image, xpos, ypos);
}

int main(int argc, char *argv[])
{
    srand( (unsigned int)time( NULL ) );
    b = rand() % 435;
  Uint8* keys;
    if ( SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO) < 0 )
  {
    printf("Unable to init SDL: %s\n", SDL_GetError());
    exit(1);
  }
  atexit(SDL_Quit);

  screen=SDL_SetVideoMode(640,480,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);
  if ( screen == NULL )
  {
    printf("Unable to set 640x480 video: %s\n", SDL_GetError());
    exit(1);
  }
  InitImages();  
  DrawBG();
  NewGame:
  int done=0;
  Point3();
  while(done == 0)
  {
             if(h>480)
             {
                                                                              if(points==1)
                                                        {
                                                                              points--;
                                                        Point0();
                                                        }
                                                        if(points==2)
                                                        {
                                                                     points--;
                                                                     Point1();
                                                                     }
                                                                     if(points==3)
                                                                     {
                                                                                  points--;
                                                                                  Point2();
                                                                                  }
                      PenB=0;
                      buecher=rand () % 3;
                      }
             if(ypos<h+45&&ypos>h&&xpos>b-80&&xpos<b+45)
             {
                                                        
                                       PenB=0;
                                       buecher= rand () % 3;
                                       if(buecher==3)
                                       {
                                                     h=0;
                                                     }
                              }
             if(PenB)
             {
                     if(points>0)
                     {
                     if(buecher==0)
                     {
                      h=h+10;
                      DrawPen();      
                      }
                      if(buecher==1)
                      {
                                    h=h+10;
                                    DrawPen1();
                                                                 
                                    }
                                    if(buecher==2)
                                    {
                                                  h=h+10;
                                                  DrawPen2();
                                                  }
                                                  }
                                                  SDL_Flip(screen);
              }
              else
              {
                  b = rand () % 435;
                  h=0;
                  PenB=1;
                  }
    SDL_Event event;
    while ( SDL_PollEvent(&event) )
    {
      if ( event.type == SDL_QUIT )  {  done = 1;  }

      if ( event.type == SDL_KEYDOWN )
      {
        if ( event.key.keysym.sym == SDLK_ESCAPE ) { done = 1; }
        if ( event.key.keysym.sym ==SDLK_SPACE){xpos=275;ypos=402;
j=0;
f=0;
h=0;
PenB=1;
buecher=0;
points=3;goto NewGame;}
      }
    }
    keys = SDL_GetKeyState(NULL);
    if ( keys[SDLK_UP] ) { ypos -=10;    }
    if ( keys[SDLK_DOWN] ) { 
         if(ypos<400)
         {
         ypos += 10;
         }
          }
    if ( keys[SDLK_LEFT] ) { xpos -= 10; }
    if ( keys[SDLK_RIGHT] ) { xpos += 10; }
    if(points>0)
    {
    DrawIMG(back,0,0,800,800,0,0);
    DrawScene();
}
  }
  return 0;
}

void DrawPen(void)
{
     if(points>0)
     {
                    SDL_SetColorKey(buch1, SDL_SRCCOLORKEY, 
                           SDL_MapRGB(buch1->format, 0, 0, 0));
                    DrawIMG(buch1,b,h);
                    }
}

void DrawPen1(void)
{
     if(points>0)
     {
                                  SDL_SetColorKey(buch2, SDL_SRCCOLORKEY, 
                           SDL_MapRGB(buch2->format, 0, 0, 0));
                                  DrawIMG(buch2,b,h);
                                  }
}

void DrawPen2(void)
{
     if(points>0)
     {
     SDL_SetColorKey(Kusit1, SDL_SRCCOLORKEY, 
                           SDL_MapRGB(Kusit1->format, 0, 0, 0));
     DrawIMG(Kusit1,b,h);
     }
     }

void Point1(void)
{
     SDL_SetColorKey(p1, SDL_SRCCOLORKEY, 
                           SDL_MapRGB(p1->format, 255, 0, 0));
     DrawIMG(p1,480,320);
 }

void Point2(void)
{
     SDL_SetColorKey(p2, SDL_SRCCOLORKEY, 
                           SDL_MapRGB(p2->format, 255, 0, 0));
     DrawIMG(p2,480,320);
     }

void Point3(void)
{
     SDL_SetColorKey(p3, SDL_SRCCOLORKEY, 
                           SDL_MapRGB(p3->format, 255, 0, 0));
     DrawIMG(p3,480,320);
     }

void Point0(void)
{
         DrawIMG(back,0,0,800,800,0,0);
     DrawIMG(GameOver,180,80);
     DrawIMG(PressSpace,0,440);
     SDL_Flip(screen);
     }
