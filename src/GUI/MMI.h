//
// MMI.h:
// MMI Class header file
//
//

class MMI;

#ifndef _MMI_H_
#define _MMI_H_

#ifdef WIN32
#include <windows.h>
#endif
#include <list>
#include <string>

#include <Screen.h>
#include <SDLSurface.h>
#include <Object.h>

class MMI : public Object
{
   public:
      MMI(Application* parent_object);
      ~MMI();
      MMIEvent update();
      ScreenState getScreenState();
      void addScreen(Screen* screen);
      void navigateToScreen(ScreenState newScreen);
      void save(const std::string fileName) const;
      void load(const std::string fileName);
      void print() const;
   private:
      SDLSurface *top_window;
      std::list<Screen*> screens;
      Screen *currentScreen;
      static std::string MMI_TITLE;
      static const int MMI_WIDTH = 1024;
      static const int MMI_HEIGHT = 768;
      MMI(const MMI &);
      MMI & operator = (const MMI &);
};

#endif
