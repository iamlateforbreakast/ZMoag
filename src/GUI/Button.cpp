//
//
//
//
//

#include <Button.h>

Button::Button(string name, unsigned int x, unsigned int y, unsigned int width, unsigned int height) : Widget(BUTTON)
{
   this->name = name;
   this->x = x;
   this->y = y;
   this->width = width;
   this->height = height;
}

Button::~Button()
{
}

void Button::draw(SDLSurface* window)
{
    Uint32 green;
    int i,j;

    for (unsigned int j=y; j<y+height; j++)
       for (unsigned int i=x; i<x+width; i++)
          window->drawPixel(i, j, green);
    window->setColor(255,255,255);
    window->printFormattedText(name,x,y);
    //SDL_UpdateRect(window, 0, 0, 1024, 768);
}

void Button::processEvent(MMIEvent& e)
{
   int xmouse,ymouse;
   
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
   released = false;
}

string Button::getName() const
{
   return name;
}

void Button::setNav(ScreenState s)
{
   navScreen = s;
}

void Button::print() const
{
   debug("Button at %X\n",this);
   debug("  Name = %s\n",name.c_str());
   debug("  X = %d\n",x);
   debug("  y = %d\n",y);
   debug("  w = %d\n",width);
   debug("  h = %d\n",height);
   debug("  Nav = %d\n", navScreen);
}

void Button::save(const string fileName) const
{
}

void Button::load(const string fileName)
{
}
