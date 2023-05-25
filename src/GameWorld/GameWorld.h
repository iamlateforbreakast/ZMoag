//
// GameWorld.h
//
//
//

class GameWorld;

#ifndef _GAMEWORLD_H_
#define _GAMEWORLD_H_

#include <string>
#include <list>

#include <Object.h>
#include <Application.h>
#include <Player.h>
#include <Mission.h>

#include <GameWorldStruct.h>

class GameWorld : public Object
{
   public:
      GameWorld(Application* parent_object);
      ~GameWorld();
      void update();
      void moveSelectedUnit(WorldPoint p);
      void fireSelectedUnit(WorldPoint p);
      void selectUnit(WorldPoint p);
      void selectGroupOfUnits(WorldPoint p1, WorldPoint p2);
      void activateItem(WorldPoint p);
      void createNewPlayer();
      void selectCorporation();
      void save(const string fileName) const;
      void load(const string fileName);
      void print() const;
      unsigned int size() const;
   private:
      list<Player*> players;
      list<Mission*> missions;
      //Map* theMap;
      // bool tactical_mode;
      void generate_missions();
      string gfx_theme;
      bool tactical_mode;
};

#endif
