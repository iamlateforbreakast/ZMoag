//
// CommandLine.h
//
//
//

class CommandLine;

#ifndef _COMMANDLINE_H_
#define _COMMANDLINE_H_

#include <string>

#include <Object.h>
#include <Application.h>

class CommandLine : public Object
{
   public:
      CommandLine(Application* parent_object);
      ~CommandLine();
      bool getArgument(const char option,string &parameter);
      virtual void    save(const string fileName) const;
      virtual void    load(const string fileName);
      virtual void    print() const;
   private:
};

#endif
