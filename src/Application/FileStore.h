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
      void open(const string fileName);
      void close();
      bool goToSection(const string sectionName);
      void readLine();
      void writeLine();
      int readInt();
      string readString();
      void save(const string fileName) const;
      void load(const string fileName);
      void print() const;
   private:
      bool compress_file;
      bool binary_file;
      bool status; //TRUE open / FALSE not opened
      list<string> buffer;
      list<string> directories;
      FILE* handle;     
};
