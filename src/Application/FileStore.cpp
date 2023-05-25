//
// FileStore.cpp
//
//
//

#include <FileStore.h>

FileStore::FileStore()
{
   list<string> temp;
   list<string>::iterator p;
   string s;
   
   binary_file = false;
   compress_file = false;
   //temp.push_front("/home/thomas/.zemoag2");
   //temp.push_front("/usr/local/games/zemoag2");
   temp.push_front("H:/perso/zemoag2/campaigns");
   
   //directories = empty();
   
   for (p=temp.begin();p==temp.end();p++)
   {
      directories.push_back(*p+"/gfx/");
      directories.push_back(*p+"/sfx/");
      directories.push_back(*p+"/missions/");
   }
}

FileStore::~FileStore()
{
}

void FileStore::open(const string fileName)
{
   list<string>::iterator p;
   string s;
   
   handle=NULL;
   p=directories.begin();
   while ((handle==NULL) && (p!=directories.end()))
   {
      s=*p+fileName;
      handle=fopen(s.c_str(),"rb");
      p++;
   }
}

void FileStore::close()
{
   fclose(handle);
}

bool FileStore::goToSection(const string sectionName)
{
}

void FileStore::readLine()
{
}

void FileStore::writeLine()
{
}

int FileStore::readInt()
{
}

string FileStore::readString()
{
}
