//
// main.cpp:
// Main entry point for the application
//
//

#include <windows.h>

#include <Application.h>

Application* app;
      
int WINAPI
WinMain (HINSTANCE hThisInstance,
         HINSTANCE hPrevInstance,
         LPSTR lpszArgument,
         int nFunsterStil)
{
   try
   {
      int argc = 0;
      char **argv;
      
      app = new Application(argc, argv);
      app->start();
   }
   catch (...)
   {
      cout << "An unhandled exception has occurred" << endl;
   }
}
