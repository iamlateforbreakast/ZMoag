//
// SDLSurface.h
//
//
//

class SDLSurface;

#ifndef _SDLSURFACE_H_
#define _SDLSURFACE_H_

#include <string>

#include <SDL.h>
#include <SDL_ttf.h>

#include <Object.h>

class SDLSurface : public Object
{
   public:
      SDLSurface(unsigned int w, unsigned int h);
      ~SDLSurface();
      void         clear();
      void         drawPixel(int x, int y, Uint32 pixel);
      int          bitBlit(SDL_Surface *pixmap, unsigned int x, unsigned int y);
      void         printFormattedText(std::string text,unsigned int x, unsigned int y);
      void         setFont(const std::string fontName);
      void         update();
      void         setColor(unsigned int r, unsigned int g, unsigned int b);
      virtual void save(const std::string fileName) const;
      virtual void load(const std::string fileName);
      virtual void print() const;
   private:
      SDL_Surface *surface;
      TTF_Font    *font;
      Uint32       color;
};

#endif
