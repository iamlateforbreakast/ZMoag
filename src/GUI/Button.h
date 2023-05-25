//
//
//
//
//

#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include <string>

#include <Application.h>
#include <Widget.h>
#include <SDLSurface.h>

class Button : public Widget
{
   public:
      Button(string name, unsigned int x, unsigned int y, unsigned int width, unsigned int height);
      ~Button();
      ScreenState         getNavScreen();
      void                draw(SDLSurface* window);
      virtual void        processEvent(MMIEvent& e);
      string              getName() const;
      void                setNav(ScreenState s);
      virtual void        save(const string fileName) const;
      virtual void        load(const string fileName);
      virtual void        print() const;
   private:
      string name;
      unsigned int x;
      unsigned int y;
      unsigned int width;
      unsigned int height;
      ScreenState navScreen;
      Button(const Button&);
      Button & operator = (const Button &);
      //virtual void draw(SDL_Surface* window);
};

#endif
