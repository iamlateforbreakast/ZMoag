//
// FileSelection.cpp
//
//
//

#include <FileSelection.h>

FileSelection::FileSelection(string name, int x, int y, int w, int h) : Widget(FILE_SELECTOR)
{
   this->name = name;
   this->x = x;
   this->y = y;
   this->width = w;
   this->height = h;
}

FileSelection::~FileSelection()
{
}

void FileSelection::draw(SDLSurface* window)
{
    Uint32 green;
    int i,j;
    
    //green = SDL_MapRGB(window->format, 0x23, 0xD4, 0x48);

    /* Lock the screen for direct access to the pixels */
    for (unsigned int j=y; j<y+height; j++)
    {
       window->drawPixel(x, j, green);
       window->drawPixel(x+width, j, green);
    }
    for (unsigned int i=x; i<x+width; i++)
    {
       window->drawPixel(i, y, green);
       window->drawPixel(i, y+height, green);
    }

    //SDL_UpdateRect(window, 0, 0, 1024, 768);
}

void    FileSelection::save(const string fileName) const
{
}

void    FileSelection::load(const string fileName)
{
}

void    FileSelection::print() const
{
}

