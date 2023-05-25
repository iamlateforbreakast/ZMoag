//
// Logger.h
// Implements a class logging message in a file
//
//

class Logger;

#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <stdarg.h>
#include <string>
#include <stdio.h>
#include <cstdarg>

class Logger
{
   public:
      Logger(string fileName);
      ~Logger();
      void setDebugLevel(int level);
      int getDebugLevel();
      void info(const char* format, ...) const;
      void error(const char* format, ...) const;
      void fatal(const char* format, ...) const;
      void debug(const char* format, ...) const;
      void print() const;
      
      static const int MAX_DEBUG_LEVEL = 0;
      static const int MIN_DEBUG_LEVEL = 10;
      static const int MEDIUM_DEBUG_LEVEL = 5;
   private:
      int debugLevel;
      FILE* output;
};

#endif
