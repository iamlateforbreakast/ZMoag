//
//
//
//
//

#include <SDLSurface.h>
#include <Application.h>

SDLSurface::SDLSurface(unsigned int w, unsigned int h) : Object(NULL, "SDLSurface")
{
   if( SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER) <0 )
   {
      error("Unable to init SDL: %s\n", SDL_GetError());
      exit(1);
   }
   else
   {
      info("SDL Display successfully opened\n");
   }
   atexit(SDL_Quit);
   
   surface = SDL_SetVideoMode(w, h, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
        
   if(TTF_Init()==-1) 
   {
      error("TTF_Init: %s\n", TTF_GetError());
      exit(2);
   }
   else
   {
      info("TTF successfully initialised\n");
   }
   
   font=TTF_OpenFont("./arial.ttf", 16);
   if(!font) {
      error("TTF_OpenFont: %s\n", TTF_GetError());
   }
}

SDLSurface::~SDLSurface()
{
   SDL_FreeSurface(surface);
   TTF_CloseFont(font);
}

void SDLSurface::clear()
{
    SDL_FillRect(surface, NULL, 0);
}

void SDLSurface::drawPixel(int x, int y, Uint32 pixel)
{
    int bpp = surface->format->BytesPerPixel;
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    /* Lock the screen for direct access to the pixels */
    if ( SDL_MUSTLOCK(surface) ) {
        if ( SDL_LockSurface(surface) < 0 ) {
            fprintf(stderr, "Can't lock screen: %s\n", SDL_GetError());
            return;
        }
    }
    switch(bpp) {
    case 1:
        *p = pixel;
        break;

    case 2:
        *(Uint16 *)p = pixel;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
            p[0] = (pixel >> 16) & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = pixel & 0xff;
        } else {
            p[0] = pixel & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = (pixel >> 16) & 0xff;
        }
        break;

    case 4:
        *(Uint32 *)p = pixel;
        break;
    }
}

void SDLSurface::printFormattedText(string text, unsigned int x, unsigned int y)
{
// Turn on byte swapping for UNICODE text
   SDL_Surface *text_surface;
   SDL_Color c;
   Uint8 r,g,b;
   
   //app->debug("printf %d,%d\n",x,y);
   SDL_GetRGB(color, surface->format, &r, &g, &b);
   c.r = r;
   c.g = g;
   c.b = b;
   if (!(text_surface=TTF_RenderText_Solid(font,text.c_str(), c))) 
   {
	  //handle error here, perhaps print TTF_GetError at least
   }
   bitBlit(text_surface,x,y);
}

void SDLSurface::setFont(const string fontName)
{
   // load font.ttf at size 16 into font
   font=TTF_OpenFont("./arial.ttf", 16);
   if(!font) {
      error("TTF_OpenFont: %s\n", TTF_GetError());
   }
}

void SDLSurface::update()
{
   SDL_UpdateRect(surface, 0, 0, surface->w, surface->h);
}

void SDLSurface::setColor(unsigned int r, unsigned int g, unsigned int b)
{

   color = SDL_MapRGB(surface->format, r, g, b);
}

int SDLSurface::bitBlit(SDL_Surface *pixmap,unsigned int x, unsigned int y)
{
   SDL_Rect pos;
   
   if (pixmap)
   {
     pos.x = x;
     pos.y = y;
   
     SDL_BlitSurface(pixmap, NULL, surface, &pos);
   }
}

void SDLSurface::save(const string fileName) const
{
}

void SDLSurface::load(const string fileName)
{
}

void SDLSurface::print() const
{
}
