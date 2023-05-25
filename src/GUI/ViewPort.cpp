//
// ViewPort.cpp
//
//
//

#include <Viewport.h>
#include <Application.h>

ViewPort::ViewPort(string name, int x, int y, int w, int h) : Widget(VIEWPORT)
{
   this->name = name;
   this->x = x;
   this->y = y;
   this->width = w;
   this->height = h;
}

ViewPort::~ViewPort()
{
}

void ViewPort::draw(SDLSurface* window)
{
    Uint32 green;
    int i,j;

    window->setColor(0,255,255);
    for (unsigned int j=y; j<y+height; j++)
    {
       window->drawPixel(x, j, green);
       window->drawPixel(x+width, j, green);
    }
    for (unsigned int i=x; i<x+width; i++)
    {
       window->drawPixel(i, y+height, green);
       window->drawPixel(i, y, green);
    }
          
    window->setColor(255,255,255);
    window->printFormattedText(name,x,y);
    //SDL_UpdateRect(window, 0, 0, 1024, 768);
}

void ViewPort::processEvent(MMIEvent& e)
{
   /*int xmouse,ymouse;
   
   SDL_GetMouseState(&xmouse,&ymouse);
   if ((xmouse>=x)&&(xmouse<(x+width))&&(ymouse>=y)&&(ymouse<(y+height)))
   {
      focus = true;
   }
   else
   {
      focus = false;
   }
   if (SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(1))
   {
      clicked = true;
      released = false;
   }
   else if (clicked)
   {
      clicked = false;
      released = true;
   }
   if ((released)&&(focus))
   {
         //app->debug("Button press %d,%d,%d,%d,%d,%d\n",xmouse,ymouse,x,y,x+width,y+height);
         e.type = NAV;
         e.parameter.screen_parameter = navScreen;
   }
   else
   {
         //e.type = NONE;
   }
   released = false;*/
}

void ViewPort::update()
{
   /* Get Render Pixmap */
   /* BiBlit Pixmap */
}

string ViewPort::getName() const
{
   return name;
}

void ViewPort::print() const
{
   debug("Print ViewPort at %X\n",this);
}

void ViewPort::save(const string fileName) const
{
}

void ViewPort::load(const string fileName)
{
}
