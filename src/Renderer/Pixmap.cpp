//
// Pixmap.h
//
//
//

#include <Pixmap.h>

Pixmap::Pixmap() : Object(NULL, "Pixmap")
{
}

Pixmap::Pixmap(string filename) : Object(NULL, "Pixmap")
{
   data = IMG_Load(filename.c_str());
   if (!data)
   {
      error("Not able to load picture %s",filename.c_str());
      exit(1);
   }
   else
   {
      info("Picture %s loaded OK\n",filename.c_str());
   }
}

Pixmap::~Pixmap()
{
   SDL_FreeSurface(data);
}

unsigned int Pixmap::getWidth() const
{
}

unsigned int Pixmap::getHeight() const
{
}

void Pixmap::setPixmap(SDL_Surface* image)
{
   data = image;
}

SDL_Surface* Pixmap::getPixmap() const
{
   debug("Get Pixmap\n");
   return data;
}

void Pixmap::save(const string fileName) const
{
}

void Pixmap::load(const string fileName)
{
}

void Pixmap::print() const
{
}
