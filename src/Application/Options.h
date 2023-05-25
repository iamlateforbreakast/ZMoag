//
//
//
//
//

class Options;

#ifndef _OPTIONS_H_
#define _OPTIONS_H_

#include <string>
#include <list>
#include <map>

#include <Object.h>

class Options : public Object
{
   public:
      Options(string fileName);
      ~Options();
      int getIntOption(string optionName);
      string getStringOption(string optionName);
      void save(const string fileName) const;
      void load(const string fileName);
      void print() const;
      unsigned int size() const;
   private:
      Application *app;
      string optionFileName;
      map<string, string> options;
};

#endif
