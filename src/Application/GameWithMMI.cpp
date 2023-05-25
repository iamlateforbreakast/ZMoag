//
// GameWithMMI.cpp:
// Class describing a generic game with an MMI
//
//

#include <GameWithMMI.h>

GameWithMMI::GameWithMMI(int argc,char **argv) : Application(argc, argv)
{  
   logger = new Logger(this, "./log_file.txt");
   commandLine = new CommandLine(this);
   options = new Options(this, "./options.txt");
   audio = new AudioPlayer(this);
   world = new GameWorld(this);
   renderer = new GameRenderer(this);
   mmi = new MMI(this);
   
   /*if (commandLine->getArgument("",saveFileName))
   {
      world->load(saveFileName);
      mmi->load(saveFileName);
   }
   else
   {
   }*/

}

GameWithMMI::~GameWithMMI()
{
}

// The main function which transmit events between MMI abd the GameWorld depending on the screen
void GameWithMMI::start()
{
   MMIEvent MMI_event;
   bool exit;
   
   exit = false;
   
   info("Starting Main loop\n");
   
   while (!exit)
   {
      world->update();
      renderer->render(world);
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
            handle_mission_events(MMI_event);
            break;
         default:
            break;
      }
   } 
}

void GameWithMMI::handle_main_menu_events(MMIEvent MMI_event)
{
   switch(MMI_event.type)
   {
      case SAVE_GAME:
         //save(MMI_event.saveFileName);
         //mmi->save(MMI_event.saveFileName);
         break;
      case LOAD_GAME:
         //load(MMI_event.loadFileName);
         //mmi->load(MMI_event.loadFileName);
         break;
      case QUIT_GAME:
         exit(0);
         break;
      default:
         break;
   }
}

void GameWithMMI::handle_options_menu_events(MMIEvent MMI_event)
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

void GameWithMMI::handle_mission_selection_events(MMIEvent MMI_events)
{
   /*switch(MMI_event.type)
   {
      case SELECT_MISSION:
      default:
   }*/
}

void GameWithMMI::handle_agents_selection_events(MMIEvent MMI_events)
{
   /*switch(MMI_event.type)
   {
      case BUY_AGENT:
      default:
   }*/
}

void GameWithMMI::handle_corporation_creation_events(MMIEvent MMI_events)
{
   /*switch(MMI_event.type)
   {
      case CREATE_CORPORATION:
      default:
   }*/
}

void GameWithMMI::handle_mission_events(MMIEvent MMI_events)
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

GameRenderer* GameWithMMI::getRenderer() const
{
   return renderer;
}

void GameWithMMI::save(const string fileName) const
{
}

void GameWithMMI::load(const string fileName)
{
}

