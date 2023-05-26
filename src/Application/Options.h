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
      Options(std::string fileName);
      ~Options();
      int getIntOption(std::string optionName);
      std::string getStringOption(std::string optionName);
      void save(const std::string fileName) const;
      void load(const std::string fileName);
      void print() const;
      unsigned int size() const;
   private:
      Application *app;
      std::string optionFileName;
      std::map<std::string, std::string> options;
};

#endif
