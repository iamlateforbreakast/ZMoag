//
// Application.h:
// Header file for Application.cpp
//
//

class Application;

#ifndef  _APPLICATION_H_
#define  _APPLICATION_H_

#ifdef WIN32
#include <windows.h>
#endif
#include <string>

#include <Object.h>
#include <CommandLine.h>
#include <Options.h>
#include <Struct.h>
#include <MMI.h>
#include <AudioPlayer.h>
#include <GameWorld.h>
#include <Renderer.h>

class Application : public Object
{
   public:
      Application(int argc, char**argv);     
      ~Application();
      void                start();
      void                terminate();
      void                help() const;
      std::string         getVersion() const;
      GameRenderer*       getRenderer() const;
      std::string         getStringOption(std::string optionname);
      virtual void        save(const std::string fileName) const;
      virtual void        load(const std::string fileName);
      void                print() const;
      unsigned int        size() const;
      
   private:
      std::string              name;
      std::string              version;
      CommandLine        *commandLine;
      Options            *options;
      MMI                *mmi;
      GameRenderer       *renderer;
      GameWorld          *world;
      AudioPlayer        *audio;

      void handle_main_menu_events(MMIEvent MMI_event);
      void handle_options_menu_events(MMIEvent MMI_event);
      void handle_mission_selection_events(MMIEvent MMI_events);
      void handle_agents_selection_events(MMIEvent MMI_events);
      void handle_corporation_creation_events(MMIEvent MMI_events);
      void handle_mission_events(MMIEvent MMI_events);
      
      Application(const Application &);
      Application & operator = (const Application &);
};
#endif
