//
// Logger.h
//
//
//

#include <Logger.h>

Logger::Logger(string fileName)
{
   output = NULL;
   if (!fileName.empty())
   {
      output = fopen(fileName.c_str(),"wt");
      if (!output)
      {
         printf("Cannot open %s. Using STDOUT instead\n",fileName.c_str());
      }
      if (output==NULL)
      {
         output = stdout;
      }
      fprintf(output,"Log file %s started\n",fileName.c_str());
   }
   debugLevel = MAX_DEBUG_LEVEL;
}

Logger::~Logger()
{
   fclose(output);
}

void Logger::print() const
{
}

void Logger::setDebugLevel(int level)
{
   debugLevel = level;   
}

int Logger::getDebugLevel()
{
   return debugLevel;
}

void Logger::info(const char* format, ...) const
{
   va_list arg;
   va_list *params;
   
   va_start(arg,format);
   params = va_arg(arg, va_list*);
   fprintf(output,"INF: ");
   vfprintf(output,format,*params);
   va_end(arg);
   fflush(output);
}

void Logger::error(const char* format, ...) const
{
   va_list arg;
   va_list *params;
   
   va_start(arg,format);
   params = va_arg(arg, va_list*);
   fprintf(output,"ERR: ");
   vfprintf(output,format,*params);
   va_end(arg);
   fflush(output);
}

void Logger::fatal(const char* format, ...) const
{
   va_list arg;
   va_list *params;
   
   va_start(arg,format);
   params = va_arg(arg, va_list*);
   fprintf(output,"FTL: ");
   vfprintf(output,format,*params);
   va_end(arg);
   fflush(output);
   exit(1);
}

void Logger::debug(const char* format, ...) const
{
   va_list arg;
   va_list *params;
   
   va_start(arg,format);
   params = va_arg(arg, va_list*);
   fprintf(output,"DBG: ");
   vfprintf(output,format,*params);
   va_end(arg);
   fflush(output);
}
