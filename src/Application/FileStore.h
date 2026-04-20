//
// FileStore.h
//
//
//

#include <string>
#include <list>
#include <stdio.h>

class FileStore
{
   public:
      FileStore();
      ~FileStore();
      void open(const std::string fileName);
      void close();
      bool goToSection(const std::string sectionName);
      void readLine();
      void writeLine();
      int readInt();
      std::string readString();
      void save(const std::string fileName) const;
      void load(const std::string fileName);
      void print() const;
   private:
      bool compress_file;
      bool binary_file;
      bool status; //TRUE open / FALSE not opened
      std::list<std::string> buffer;
      std::list<std::string> directories;
      FILE* handle;     
};
