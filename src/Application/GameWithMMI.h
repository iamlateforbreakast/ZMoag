//
// GameWithMMI.h:
// Header File for GameWithMMI.cpp
//
//

class GameWithMMI;

#ifndef _GAMEWITHMMI_H_
#define _GAMEWITHMMI_H_

#include <windows.h>

#include <Application.h>
#include <Renderer.h>
#include <GameWorld.h>
#include <AudioPlayer.h>
#include <MMI.h>

struct MMIEvent;

class GameWithMMI : public Application
{
   public:
      GameWithMMI(int argc, char **argv);
      ~GameWithMMI();
      
      // FIXME: Add a copy constructor and a copy operator
      GameRenderer* getRenderer() const;
      virtual void save(const string fileName) const;
      virtual void load(const string fileName);
      void print() const;
      unsigned int size() const;
      virtual void start();
      
   private:
      void handle_main_menu_events(MMIEvent MMI_event);
      void handle_options_menu_events(MMIEvent MMI_event);
      void handle_mission_selection_events(MMIEvent MMI_events);
      void handle_agents_selection_events(MMIEvent MMI_events);
      void handle_corporation_creation_events(MMIEvent MMI_events);
      void handle_mission_events(MMIEvent MMI_events);
      MMI* mmi;
      GameRenderer *renderer;
      GameWorld *world;
      AudioPlayer *audio;
};

#endif
