//
// Object.h
// 
//
//

class Object;

#ifndef _OBJECT_H_
#define _OBJECT_H_

//#include <Logger.h>
#include <string>

class Application;

class Object
{
   public:
      Object(Object *parent=0, std::string name="");
      ~Object();
      void         info(const char* format ...) const;
      void         error(const char* format ...) const;
      void         debug(const char* format ...) const;
      void         fatal(const char* format ...) const;
      virtual void save(const std::string fileName) const = 0;
      virtual void load(const std::string fileName) = 0;
      virtual void print() const = 0;
      unsigned int size() const;
   protected:
      static Application *appl;
 //     static Logger *logger;
      Object      *parent;
      std::string       object_name;
   private:
      Object(const Object &);
      Object & operator = (const Object &);
};

#endif
