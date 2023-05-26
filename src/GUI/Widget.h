//
// Widget.h
//
//
//

class Widget;

#ifndef _WIDGET_H_
#define _WIDGET_H_

#include <SDL.h>

#include <Object.h>
#include <SDLSurface.h>

#include <Struct.h>


class Widget : public Object
{
   public:
      Widget(WidgetType t);
      ~Widget();
      virtual void    draw(SDLSurface* window) = 0;
      virtual void    processEvent(MMIEvent& e);
      WidgetType      getType();
      virtual void    save(const std::string fileName) const;
      virtual void    load(const std::string fileName);
      virtual void    print() const;
   protected:
      bool            clicked;
      bool            focus;
      bool            released;
      WidgetType      type;
      unsigned        int x;
      unsigned        int y;
      unsigned        int width;
      unsigned        int height;
      std::string name;
   private:    
      Widget(const Widget &);
      Widget & operator = (const Widget &);
};

#endif
