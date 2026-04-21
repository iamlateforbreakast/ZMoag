//
//
//
//
//

#include <MiniMap.h>

MiniMap::MiniMap(std::string name, int x, int y, int w, int h) : Widget(MINIMAP)
{
   this->name = name;
   this->x = x;
   this->y = y;
   this->width = w;
   this->height = h;
}

MiniMap::~MiniMap()
{
}

void MiniMap::draw(SDLSurface* window)
{
    Uint32 green;

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

void MiniMap::processEvent(MMIEvent& e)
{
   (void)e;
}
      
std::string MiniMap::getName() const
{
   return name;
}
      
void    MiniMap::save(const std::string fileName) const
{
   (void)fileName;
}

void    MiniMap::load(const std::string fileName)
{
   (void)fileName;
}

void    MiniMap::print() const
{
   debug("Print Minimap at %X\n",this);
}
