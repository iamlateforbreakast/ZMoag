//
// Object.cpp
//
//
//

#include <Object.h>
#include <stdarg.h>

extern Application * app;

Object::Object(Object *parent=0, std::string name="")
{
   if (!logger)
   {
      logger = new Logger("./log_file.txt");
   }
   this->parent = parent;
   this->object_name = name;
   this->appl = app;
   debug("Creating %s at %x with app%x\n",name.c_str(),this,app);
}

Object::~Object()
{
}

Logger * Object::logger = 0;
Application * Object::appl = 0;

void Object::info(const char* format ...) const
{
   va_list vargs;
   va_start(vargs,format);
   
   logger->info(format,&vargs);
   
   va_end(vargs);
}

void Object::error(const char* format ...) const
{
   va_list vargs;
   va_start(vargs,format);

   logger->error(format,&vargs);
      
   va_end(vargs);
}

void Object::debug(const char* format ...) const
{
   va_list vargs;
   va_start(vargs,format);
   
   logger->debug(format,&vargs);
      
   va_end(vargs);
}

void Object::fatal(const char* format ...) const
{
   va_list vargs;
   va_start(vargs,format);
   
   logger->fatal(format,&vargs);
      
   va_end(vargs);
}

unsigned int Object::size() const
{
   return 0;
}
