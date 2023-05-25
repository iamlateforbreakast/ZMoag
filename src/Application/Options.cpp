//
//
//
//
//

#include <fstream.h>

#include <Options.h>
#include <Application.h>

Options::Options(string fileName)
{
   optionFileName = fileName;
   load(fileName);
}

Options::~Options()
{
   save(optionFileName);
}

int Options::getIntOption(string optionName)
{
   return(atoi(options[optionName].data()));
}

string Options::getStringOption(string optionName)
{
   debug("Option name = %s\n",optionName.c_str());
   return(options[optionName]);
}

void Options::save(const string fileName) const
{
}

void Options::load(const string fileName)
{
   ifstream options_file;
   string optionName;
   string optionValue;
   string buffer;
   unsigned int line_number;
   int equal_position;
   
   options_file.open(fileName.data(),fstream::in);
   if (!options_file.is_open())
   {
      error("Cannot open option file %s\n",fileName.c_str());
   }
   else
   {
      info("Opened the option file %s successfully\n",fileName.c_str());
      line_number = 1;
   
      while(!options_file.eof())
      {
         getline(options_file ,buffer);
         info("Read %s\n",buffer.data());
         if (buffer.find_first_of("#")==-1)
         {
            equal_position = buffer.find_first_of("=");
            if (equal_position!=-1)
            {
               optionName = buffer.substr(0,equal_position);
               optionName = optionName.substr(optionName.find_first_not_of(" "),optionName.find_last_not_of(" ")+1);
               optionValue = buffer.substr(equal_position+1,buffer.length());
               optionValue = optionValue.substr(optionValue.find_first_not_of(" "),optionValue.find_last_not_of(" "));
               info("Read option %s,%s\n",optionName.data(),optionValue.c_str());
            }
            else
            {
               error("Option file skipped line %d missing =\n",line_number);
            }
          }
          options[optionName]=optionValue;
          line_number++;
      }
      options_file.close();
   }
}

void Options::print() const
{
   debug("printing Options at %x",this);
}

unsigned int Options::size() const
{
}
