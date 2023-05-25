//
//
//
//
//

#ifndef _PIXMAP_H_
#define _PIXMAP_H_

#include <string>
#include <SDL/SDL_image.h>
#include <Object.h>

class Pixmap : public Object
{
   public:
      Pixmap();
      Pixmap(string filename);
      ~Pixmap();
      unsigned int getWidth() const;
      unsigned int getHeight() const;
      void setPixmap(SDL_Surface* image);
      SDL_Surface* getPixmap() const;
      void save(const string fileName) const;
      void load(const string fileName);
      void print() const;
   private:
      unsigned int width;
      unsigned int height;
      SDL_Surface* data;
};

#endif

