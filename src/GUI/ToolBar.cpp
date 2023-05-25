//
//
//
//
//

#include <ToolBar.h>

ToolBar::ToolBar(string name, int x, int y, int w, int h) : Widget(TOOLBAR)
{
   this->name = name;
   this->x = x;
   this->y = y;
   this->width = w;
   this->height = h;
}

ToolBar::~ToolBar()
{
}

void ToolBar::draw(SDLSurface* window)
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
}

void ToolBar::processEvent(MMIEvent& e)
{
}

string ToolBar::getName() const
{
}

void ToolBar::save(const string fileName) const
{
}

void ToolBar::load(const string fileName)
{
}

void ToolBar::print() const
{
   debug("Print Toolbar at %X\n",this);
}
