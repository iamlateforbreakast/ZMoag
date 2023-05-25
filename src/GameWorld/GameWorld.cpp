//
//
//
//
//

#include <GameWorld.h>
#include <FileStore.h>

GameWorld::GameWorld(Application* parent_object)
{
   tactical_mode = false;
}

GameWorld::~GameWorld()
{
}

void GameWorld::update()
{
}

void GameWorld::moveSelectedUnit(WorldPoint p)
{
}

void GameWorld::fireSelectedUnit(WorldPoint p)
{
}

void GameWorld::selectUnit(WorldPoint p)
{
}

void GameWorld::selectGroupOfUnits(WorldPoint p1, WorldPoint p2)
{
}

void GameWorld::activateItem(WorldPoint p)
{
}
      
void GameWorld::save(const string fileName) const
{
}

void GameWorld::load(const string fileName)
{
   FileStore* save_file;
   
   save_file = new FileStore();
   save_file->open(fileName);
   if (save_file !=NULL)
   {
      save_file->goToSection(string("[INFO]"));
      save_file->readString(); // Campaign name
      //add Campaign name to list of directories for gfx and sfx
      //save_file->readBool();
      
      save_file->goToSection(string("[PLAYER INFO]"));
      // 
      save_file->goToSection(string("[MISSIONS]"));
      if (tactical_mode)
      {
         save_file->goToSection(string("[MAP]"));
         // map = new Map();
         // map->load();
      }
      save_file->close();
   }
   else
   {
      fatal("Argghhhhhhh\n");
   }
}

void GameWorld::print() const
{
}

