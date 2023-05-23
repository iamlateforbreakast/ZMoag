//
// Application.cpp:
// 
//
//

#include <string>
#include <cstdarg>

#include <Application.h>

Application::Application(int argc, char **argv) : Object(NULL, "Application")
{ 
   version = "0.1.0";
   name = "Zemoag";
}

Application::~Application()
{
   //delete commandLine;
   //delete logger;
   //delete options;
}

void Application::help() const
{
}

string Application::getVersion() const
{
   return version;
}

void Application::print() const
{
   debug("Print Application at %X\n",this);
   commandLine->print();
   options->print();
}

void Application::save(const string fileName) const
{
   world->save(fileName);
   renderer->save(fileName);
   mmi->save(fileName);
   //audio->save(fileName);
}

void Application::load(const string fileName)
{
   world->load(fileName);
   renderer->load(fileName);
   mmi->load(fileName);
   //audio->load(fileName);
}

// The main function which transmit events between MMI and the GameWorld depending on the screen
void Application::start()
{
   MMIEvent MMI_event;
   bool exit;

   commandLine = new CommandLine(this);
   options = new Options("./options.txt");
   audio = new AudioPlayer(this);
   world = new GameWorld(this);
   renderer = new GameRenderer(world);
   mmi = new MMI(this);
   exit = false;

   info("Starting Main loop\n");
   
   while (!exit)
   {
      MMI_event = mmi->update();
      switch(mmi->getScreenState())
      {
         case MAIN_MENU:
            handle_main_menu_events(MMI_event);
            break;
         case OPTIONS_MENU:
            handle_options_menu_events(MMI_event);
            break;
         case MISSION_SELECTION:
            handle_mission_selection_events(MMI_event);
            break;
         case AGENTS_SELECTION:
            handle_agents_selection_events(MMI_event);
            break;
         //case CORPORATION_CREATION:
         //   handle_corporation_creation_events(MMI_event);
         //   break;
         case MISSION:
            world->update();
            renderer->render();
            handle_mission_events(MMI_event);
            break;
         default:
            break;
      }
      
   }
}

void Application::handle_main_menu_events(MMIEvent MMI_event)
{
   switch(MMI_event.type)
   {
      case SAVE_GAME:
         //save(MMI_event.saveFileName);
         //mmi->save(MMI_event.saveFileName);
         break;
      case LOAD_GAME:
         load(string(MMI_event.parameter.string_parameter));
         break;
      case QUIT_GAME:
         exit(0);
         break;
      default:
         break;
   }
}

void Application::handle_options_menu_events(MMIEvent MMI_event)
{
   /*switch(MMI_event.type)
   {
      case SET_VOLUME:
         audio->setVolume(MMI_event.volume);
         break;
      case SET_DEBUG_LEVEL:
         logger->setDebugLevel(MMI_event.debug_level);
         default:
   }*/
}

void Application::handle_mission_selection_events(MMIEvent MMI_events)
{
   /*switch(MMI_event.type)
   {
      case SELECT_MISSION:
      default:
   }*/
}

void Application::handle_agents_selection_events(MMIEvent MMI_events)
{
   /*switch(MMI_event.type)
   {
      case BUY_AGENT:
      default:
   }*/
}

void Application::handle_corporation_creation_events(MMIEvent MMI_events)
{
   /*switch(MMI_event.type)
   {
      case CREATE_CORPORATION:
      default:
   }*/
}

void Application::handle_mission_events(MMIEvent MMI_events)
{
   /*switch(MMI_event.type)
   {
      case MOVE:
         world->moveSelectedUnit(renderer->convertToWorldCoordinates(x,y));
      case FIRE:
         world->fireSelectedUnit(renderer->convertToWorldCoordinates(x,y));
      case STOP:
         world->stopSelectedUnit();
      case SELECT:
         world->selectUnit(renderer->convertToWorldCoordinates(x,y));
      case GROUP_SELECT:
         world->selectGroupOfUnits(renderer->convertToWorldCoordinates(x1,y1,x2,y2));
      case ACTIVATE:
         GameWorld->activateItem(Render->convertToWorldCoordinates(x,y))
      case SCROLL:
         renderer->moveViewport(dx,dy);
      default:
   }*/
}

GameRenderer* Application::getRenderer() const
{
   return renderer;
}

string Application::getStringOption(string optionname)
{
   debug("Here again \n");
   print();
   return options->getStringOption(optionname);
}
