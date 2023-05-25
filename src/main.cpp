//
// main.cpp:
// Main entry point for the application
//
//

#ifdef WIN32
#include <windows.h>
#endif

#include <iostream>
#include <Application.h>

Application* app;

#ifdef WIN32      
int WINAPI
WinMain (HINSTANCE hThisInstance,
         HINSTANCE hPrevInstance,
         LPSTR lpszArgument,
         int nFunsterStil)
#else
int main()
#endif
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
      std::cout << "An unhandled exception has occurred" << std::endl;
   }
}
