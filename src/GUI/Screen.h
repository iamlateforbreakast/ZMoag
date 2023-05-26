//
// Screen.h:
// Screen Class header file
//
//

class Screen;

#ifndef _SCREEN_H_
#define _SCREEN_H_


#include <list>
#include <string>

#include <Object.h>                          
#include <Widget.h>
#include <Button.h>
#include <Pixmap.h>
#include <Application.h>
#include <SDLSurface.h>
                             
class Screen : public Object
{
   public:
      Screen();
      Screen(ScreenState screenId, Pixmap* background);
      ~Screen();
      void draw(SDLSurface* window);
      ScreenState getId() const;
      MMIEvent processEvent(SDL_Event event);
      void addWidget(Widget* w);
      void addNavOnTimeOut(int time, ScreenState newScreen);
      void addNavOnKeyPress(int key, ScreenState newScreen);
      void addNavOnButtonPress(std::string buttonName, ScreenState newScreen);
      void save(const std::string fileName) const;
      void load(const std::string fileName);
      void print() const;
   private:
      ScreenState screenId;
      SDL_Surface* background;
      std::list<Widget*> widgets;
      unsigned int timeout;
      /*SDLKey*/ int key;
      ScreenState navTimeout;
      ScreenState navKey;
      std::string music_score;
      Screen(const Screen&);
      Screen & operator = ( const Screen &);
};

#endif
