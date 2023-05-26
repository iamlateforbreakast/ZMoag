//
// Renderer.h
// Implement a class drawing the world on a SDL surface
//
//

class GameRenderer;

#ifndef _RENDERER_H_
#define _RENDERER_H_

#include <string>
#include <vector>
#include <SDL_image.h>

#include <Object.h>
#include <Application.h>
#include <GameWorld.h>
#include <PixmapArray.h>

#include <GameWorldStruct.h>

class GameRenderer : public Object
{
   public:
      GameRenderer(GameWorld* world);
      ~GameRenderer();
      void render();
      Pixmap* renderPixmap(const std::string fileName);
      WorldPoint convertToWorldCoordinates(int x, int y);      
      void save(const std::string fileName) const;
      void load(const std::string fileName);
      void print() const;
   private:
      std::vector<PixmapArray*> gfx_data;
      GameWorld* world;
};

#endif
