//
// Screen.cpp
//
//
//

#include <SDL/SDL.h>

#include <Screen.h>

Screen::Screen()
{
   timeout = 0;
}

Screen::~Screen()
{
}

Screen::Screen(ScreenState screenId, Pixmap* background) : Object(NULL,"Screen")
{
   timeout = 0;
   this->screenId = screenId;
   
   debug("   Screen.background = %x\n",background);
   if (background!=NULL)
      this->background = background->getPixmap();
   else
      debug("Created with a NULL background\n");
   print();
}

void Screen::draw(SDLSurface* window)
{
    list<Widget*>::const_iterator p;
    
    window->clear();
    print();
    if (background!=NULL)
    {
       debug("Going blitting\n");
       if (window->bitBlit(background,0,0)< 0) 
          error("BlitSurface error: %s\n", SDL_GetError());
    }
    else
    {
       debug("Background is NULL\n");
    }
    p = widgets.begin();
    while (p!=widgets.end())
    {
       (*p)->draw(window);
       p++;
    }
    window->update();
    /* Free the allocated BMP surface */
    //
   //Play music
}

MMIEvent Screen::processEvent(SDL_Event event)
{
   MMIEvent returned_event;
   list<Widget*>::const_iterator p;
   
   SDL_PumpEvents();
   returned_event.type = NONE;

   if ((SDL_GetTicks()>=timeout) && (timeout!=0))
   {
      returned_event.type = NAV;
      returned_event.parameter.screen_parameter = navTimeout;
      timeout = 0;
   }
  
   Uint8 *keystate = SDL_GetKeyState(NULL);
   
   if ( keystate[key] )
   {
      returned_event.type = NAV;
      returned_event.parameter.screen_parameter = navKey;
   }
   
   p = widgets.begin();
   while (p!=widgets.end())
   {
      if (p!=NULL)
         (*p)->processEvent(returned_event);  
      p++;
   }
 
   return returned_event;
}

void Screen::addNavOnTimeOut(int time, ScreenState newScreen)
{
   timeout = SDL_GetTicks() + time * 1000;
   navTimeout = newScreen;
}

void Screen::addNavOnKeyPress(SDLKey key, ScreenState newScreen)
{
   this->key = key;
   this->navKey = newScreen;
}

void Screen::addNavOnButtonPress(string buttonName, ScreenState newScreen)
{
   list<Widget*>::const_iterator p;
   
   p = widgets.begin();
   while (p!=widgets.end())
   {
      if ((*p)->getType() == BUTTON)
      {
         if (((Button*)*p)->getName() == buttonName)
         {
            ((Button*)*p)->setNav(newScreen);
            debug("Setting Nav\n");
         }         
      }
      p++;
   }
}

void Screen::addWidget(Widget* w)
{
   debug("Adding Widget %d\n",w);
   widgets.push_front(w);
}

ScreenState Screen::getId() const
{
   return screenId;
}

void Screen::print() const
{
   list<Widget*>::const_iterator p;
   
   //      ScreenState screenId;
   debug("   Screen.background = %x\n",background);
   
   for (p=widgets.begin();p!=widgets.end();p++)
      (*p)->print();
   
   debug("   Screen.timeout = %d\n", timeout);

      //SDLKey key;
      
      ScreenState navTimeout;
      ScreenState navKey;
      string music_score;
}

void Screen::save(const string fileName) const
{
}

void Screen::load(const string fileName)
{
}
