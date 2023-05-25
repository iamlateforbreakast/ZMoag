//
// MMI.cpp:
// Class describing an MMI with screens
//
//

#include <SDL/SDL.h>

#include <Button.h>
#include <ViewPort.h>
#include <MiniMap.h>
#include <ToolBar.h>
#include <FileSelection.h>

#include <MMI.h>

MMI::MMI(Application* app) : Object(app,"MMI")
{   
   Screen *splash, *intro_movie, *main_menu, *load_dialog, *save_dialog;
   Screen *options_dialog, *new_game_dialog, *buy_agents_dialog, *select_agents_dialog;
   Screen *select_mission_dialog, *mission, *game_menu;
   
   top_window = new SDLSurface(MMI_WIDTH,MMI_HEIGHT);

   //SDL_WM_SetCaption (MMI_TITLE.data(), MMI_TITLE.data());
   splash = new Screen(SPLASH, app->getRenderer()->renderPixmap("./gfx/splash.png"));
   splash->addNavOnTimeOut(10, MAIN_MENU);
   splash->addNavOnKeyPress(SDLK_ESCAPE, MAIN_MENU);
   addScreen(splash);
   
   //intro_movie = new Screen();
   //addScreen(MOVIE, intro_movie);
   //intro_movie->addKeyPress("Esc","NAV",MAIN_MENU);

   // Create the Main Menu screen
   main_menu = new Screen(MAIN_MENU, app->getRenderer()->renderPixmap("./gfx/main_menu1.png"));
   main_menu->addWidget(new Button("New Game",432,150,160,50));
   main_menu->addNavOnButtonPress("New Game", NEW_GAME);
   main_menu->addWidget(new Button("Load Game",432,210,160,50));
   main_menu->addNavOnButtonPress("Load Game", LOAD);
   main_menu->addWidget(new Button("Game Options",432,270,160,50));
   main_menu->addNavOnButtonPress("Game Options", OPTIONS_MENU);
   main_menu->addWidget(new Button("Quit Game",432,330,160,50));
   addScreen(main_menu);

   // Create the Save Menu
   save_dialog = new Screen(SAVE, app->getRenderer()->renderPixmap("./gfx/main_menu1.png"));
   save_dialog->addWidget(new Button("Cancel",320,150,160,50));
   save_dialog->addNavOnButtonPress("Cancel", MAIN_MENU);
   save_dialog->addWidget(new Button("Save",320,210,160,50));
   save_dialog->addNavOnButtonPress("Save", MAIN_MENU);
   save_dialog->addWidget(new FileSelection("FileList", 8, 100, 500, 500));
   addScreen(save_dialog);
   
   // Create the Load Menu
   load_dialog = new Screen(LOAD, app->getRenderer()->renderPixmap("./gfx/main_menu1.png"));
   load_dialog->addWidget(new Button("Cancel",800,150,160,50));
   load_dialog->addNavOnButtonPress("Cancel", MAIN_MENU);
   load_dialog->addWidget(new Button("Load",800,210,160,50));
   load_dialog->addNavOnButtonPress("Load", MISSION);
   addScreen(load_dialog);
   
   // Create the Options Menu
   options_dialog = new Screen(OPTIONS_MENU, app->getRenderer()->renderPixmap("./gfx/main_menu1.png"));
   options_dialog->addWidget(new Button("OK",800,390,160,50));
   options_dialog->addNavOnButtonPress("OK", MAIN_MENU);
   addScreen(options_dialog);
   
   // Create the New Game Menu
   new_game_dialog = new Screen(NEW_GAME, app->getRenderer()->renderPixmap("./gfx/main_menu1.png"));
   new_game_dialog->addWidget(new Button("Cancel",800,150,160,50));
   new_game_dialog->addNavOnButtonPress("Cancel", MAIN_MENU);
   new_game_dialog->addWidget(new Button("Create",800,210,160,50));
   new_game_dialog->addNavOnButtonPress("Create", BUY_AGENTS);
   addScreen(new_game_dialog);
   
   // Create the Team Buying screen
   buy_agents_dialog = new Screen(BUY_AGENTS, app->getRenderer()->renderPixmap("./gfx/main_menu1.png"));
   buy_agents_dialog->addWidget(new Button("Cancel",800,150,160,50));
   buy_agents_dialog->addNavOnButtonPress("Cancel", NEW_GAME);
   buy_agents_dialog->addWidget(new Button("Proceed",800,210,160,50));
   buy_agents_dialog->addNavOnButtonPress("Proceed", AGENTS_SELECTION);
   addScreen(buy_agents_dialog);
   
   // Create the Team Selection SCreen
   select_agents_dialog = new Screen(AGENTS_SELECTION, app->getRenderer()->renderPixmap("./gfx/main_menu1.png"));
   select_agents_dialog->addWidget(new Button("Cancel",800,150,160,50));
   select_agents_dialog->addNavOnButtonPress("Cancel", MAIN_MENU);
   select_agents_dialog->addWidget(new Button("Done",800,210,160,50));
   select_agents_dialog->addNavOnButtonPress("Done", MISSION_SELECTION);
   addScreen(select_agents_dialog);
   
   // Create the Mission Selection screen
   select_mission_dialog = new Screen(MISSION_SELECTION, app->getRenderer()->renderPixmap("./gfx/main_menu1.png"));
   select_mission_dialog->addWidget(new Button("Cancel",800,150,160,50));
   select_mission_dialog->addNavOnButtonPress("Cancel", NEW_GAME);
   select_mission_dialog->addWidget(new Button("Start",800,210,160,50));
   select_mission_dialog->addNavOnButtonPress("Start", MISSION);
   addScreen(select_mission_dialog);
   
   // Create In Mission Screen
   mission = new Screen(MISSION, NULL);
   mission->addWidget(new ViewPort("View",7,7,752,752));
   mission->addWidget(new ToolBar("ToolBar",780,256,236,496));
   mission->addWidget(new MiniMap("MiniMap",780,7,236,236));
   mission->addNavOnKeyPress(SDLK_ESCAPE, GAME_MENU);
   addScreen(mission);
   
   // Create the In Game menu screen
   game_menu = new Screen(GAME_MENU, app->getRenderer()->renderPixmap("./gfx/main_menu1.png"));
   game_menu->addWidget(new Button("Resume Game",432,150,160,50));
   game_menu->addNavOnButtonPress("Resume Game", MISSION);
   game_menu->addWidget(new Button("Save Game",432,210,160,50));
   game_menu->addNavOnButtonPress("Save Game", SAVE);
   game_menu->addWidget(new Button("Load Game",432,270,160,50));
   game_menu->addNavOnButtonPress("Load Game", LOAD);
   game_menu->addWidget(new Button("Game Options",432,330,160,50));
   game_menu->addNavOnButtonPress("Game Options", OPTIONS_MENU);
   game_menu->addWidget(new Button("Quit Game",432,390,160,50));
   addScreen(game_menu);
   //mission_win =
   
   //mission_fail =
   
   //game_win =
   
   //game_fail =
   
   currentScreen = splash;
   if (currentScreen !=NULL)
   {
      currentScreen->draw(top_window);
   }
   else
      debug("The screen you are navigating is NULL\n");
}

MMI::~MMI()
{
   delete top_window;
}

MMIEvent MMI::update()
{
   MMIEvent mmi_event;
   
   mmi_event.type = NONE;
   
   SDL_Event event;
   
   // Process Window Manager event QUIT, ICONISE, RESIZE, EXPOSE
   if (SDL_PollEvent(&event)>=0)
   {
      switch (event.type)
      {
         case SDL_MOUSEBUTTONDOWN:
            // FIXME:
            break;
         case SDL_QUIT:
            //FIXME:
            exit(0);
            break;
         default:
            break;
      }
   }
   
   // Process Screen event
   mmi_event = currentScreen->processEvent(event);
   
   if (mmi_event.type == NAV)
   {
      navigateToScreen(mmi_event.parameter.screen_parameter);
   }
   return mmi_event;
}

ScreenState MMI::getScreenState()
{
}

void MMI::addScreen(Screen* screen)
{
   screens.push_front(screen);
}

void MMI::navigateToScreen(ScreenState newScreen)
{  
   list<Screen*>::const_iterator p;
   
   if (newScreen == SPLASH)
      debug("navigating to splash\n");
   else if (newScreen == MAIN_MENU)
      debug("navigating to menu\n");
   else
      debug("navigating to other\n");
      
   p = screens.begin();
   
   while (((*p)->getId()!=newScreen) && (p!=screens.end()))
   {
      p++;
   }
      
   if ((*p)->getId() == newScreen)
   {
      currentScreen = *p;
      if (currentScreen !=NULL)
         currentScreen->draw(top_window);
      else
         debug("The screen you are navigating is NULL\n");
   }
   else
   {
      error("Could not find screen #%d\n",newScreen);
   }
}

void MMI::print() const
{
   list<Screen*>::const_iterator p;
   
   debug("Print MMI at %X\n", this);
   debug("   MMI.top_window = %X\n", top_window);
   
   for (p=screens.begin();p!=screens.end();p++)
   {
      (*p)->print();
   }

   currentScreen->print();
   
   //app->debug("MMI.MMI_TITLE%s\n",MMI_TITLE.data());
   debug("MMI.MMI_WIDTH = %d\n",MMI_WIDTH);
   debug("MMI.MMI_HEIGHT = %d\n",MMI_HEIGHT);
}   

void MMI::save(const string fileName) const
{
}

void MMI::load(const string fileName)
{
}

   
   
