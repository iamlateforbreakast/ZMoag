//
// Struct.h
//
//
//

#ifndef _STRUCT_H_
#define _STRUCT_H_

enum WidgetType { BUTTON = 0,
                  TEXTBOX,
                  FILE_SELECTOR,
                  VIEWPORT,
                  MINIMAP,
                  TOOLBAR,
                };
                
enum ScreenState { SPLASH = 0,
                   MOVIE, 
                   MAIN_MENU, 
                   OPTIONS_MENU,
                   SAVE,
                   LOAD,
                   NEW_GAME, 
                   MISSION_SELECTION, 
                   AGENTS_SELECTION,  
                   BUY_AGENTS,
                   MISSION,
                   GAME_MENU
                 };
                                 
enum MMIEventType { NONE,
                    NAV,
                    SAVE_GAME, 
                    LOAD_GAME,
                    QUIT_GAME };

union MultiTypeParameter { int int_parameter;
                           ScreenState screen_parameter; 
                           float float_parameter; 
                           char* string_parameter; };

struct MMIEvent 
{ 
   MMIEventType type; 
   union MultiTypeParameter parameter;
   //MMIEvent& operator = (const MMIEvent& e) {};
};

#endif
