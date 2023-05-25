//
// SDLSurface.h
//
//
//

class SDLSurface;

#ifndef _SDLSURFACE_H_
#define _SDLSURFACE_H_

#include <string>

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include <Object.h>

class SDLSurface : public Object
{
   public:
      SDLSurface(unsigned int w, unsigned int h);
      ~SDLSurface();
      void         clear();
      void         drawPixel(int x, int y, Uint32 pixel);
      int          bitBlit(SDL_Surface *pixmap, unsigned int x, unsigned int y);
      void         printFormattedText(string text,unsigned int x, unsigned int y);
      void         setFont(const string fontName);
      void         update();
      void         setColor(unsigned int r, unsigned int g, unsigned int b);
      virtual void save(const string fileName) const;
      virtual void load(const string fileName);
      virtual void print() const;
   private:
      SDL_Surface *surface;
      TTF_Font    *font;
      Uint32       color;
};

#endif
