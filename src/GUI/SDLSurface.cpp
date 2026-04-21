//
//
//
//
//

#include <SDLSurface.h>
#include <Application.h>

SDLSurface::SDLSurface(unsigned int w, unsigned int h) : Object(NULL, "SDLSurface")
{
   if (!SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO))
   {
      error("Unable to init SDL: %s\n", SDL_GetError());
      exit(1);
   }
   else
   {
      info("SDL Display successfully opened\n");
   }
   atexit(SDL_Quit);
   
   //surface = SDL_SetVideoMode(w, h, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
   window = SDL_CreateWindow("ZMoag", w, h, SDL_WINDOW_RESIZABLE);
   surface = SDL_GetWindowSurface(window);
   if (surface == NULL)
   {
      error("Unable to set video mode: %s\n", SDL_GetError());
      exit(1);
   }
   else
   {
      info("SDL Surface successfully created\n");
   }
   if(!TTF_Init()) 
   {
      error("TTF_Init: %s\n", SDL_GetError());
      exit(2);
   }
   else
   {
      info("TTF successfully initialised\n");
   }
   
   font=TTF_OpenFont("./arial.ttf", 16);
   if(!font) {
      error("TTF_OpenFont: %s\n", SDL_GetError());
   }
}

SDLSurface::~SDLSurface()
{
   SDL_DestroySurface(surface);
   TTF_CloseFont(font);
}

void SDLSurface::clear()
{
    SDL_FillSurfaceRect(surface, NULL, 0);
}

void SDLSurface::drawPixel(int x, int y, Uint32 pixel)
{
    int bpp = SDL_BYTESPERPIXEL(surface->format);
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    /* Lock the screen for direct access to the pixels */
    if ( SDL_MUSTLOCK(surface) ) {
        if (!SDL_LockSurface(surface)) {
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

void SDLSurface::printFormattedText(std::string text, unsigned int x, unsigned int y)
{
// Turn on byte swapping for UNICODE text
   SDL_Surface *text_surface;
   SDL_Color c;
   Uint8 r,g,b;
   const SDL_PixelFormatDetails * fmtDetails = SDL_GetPixelFormatDetails(surface->format);

   //app->debug("printf %d,%d\n",x,y);
   SDL_GetRGB(color, fmtDetails, NULL, &r, &g, &b);
   c.r = r;
   c.g = g;
   c.b = b;
   if (!(text_surface=TTF_RenderText_Solid(font,text.c_str(), text.length(), c))) 
   {
	  //handle error here, perhaps print TTF_GetError at least
   }
   bitBlit(text_surface,x,y);
}

void SDLSurface::setFont(const std::string fontName)
{
   (void)fontName;
   // load font.ttf at size 16 into font
   font=TTF_OpenFont("./arial.ttf", 16);
   if(!font) {
      error("TTF_OpenFont: %s\n", SDL_GetError());
   }
}

void SDLSurface::update()
{
   SDL_UpdateWindowSurface(window);
}

void SDLSurface::setColor(unsigned int r, unsigned int g, unsigned int b)
{
   const SDL_PixelFormatDetails * fmtDetails = SDL_GetPixelFormatDetails(surface->format);

   color = SDL_MapRGB(fmtDetails, NULL, r, g, b);
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
   return 0;
}

void SDLSurface::save(const std::string fileName) const
{
   (void)fileName;
}

void SDLSurface::load(const std::string fileName)
{
   (void)fileName;
}

void SDLSurface::print() const
{
}
