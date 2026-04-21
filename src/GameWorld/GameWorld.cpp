//
//
//
//
//

#include <GameWorld.h>
#include <FileStore.h>

GameWorld::GameWorld(Application* parent_object)
{
   (void)parent_object;
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
   (void)p;
}

void GameWorld::fireSelectedUnit(WorldPoint p)
{
   (void)p;
}

void GameWorld::selectUnit(WorldPoint p)
{
   (void)p;
}

void GameWorld::selectGroupOfUnits(WorldPoint p1, WorldPoint p2)
{
   (void)p1;
   (void)p2;
}

void GameWorld::activateItem(WorldPoint p)
{
   (void)p;
}
      
void GameWorld::save(const std::string fileName) const
{
   (void)fileName;
}

void GameWorld::load(const std::string fileName)
{
   FileStore* save_file;
   
   save_file = new FileStore();
   save_file->open(fileName);
   if (save_file !=NULL)
   {
      save_file->goToSection(std::string("[INFO]"));
      save_file->readString(); // Campaign name
      //add Campaign name to list of directories for gfx and sfx
      //save_file->readBool();
      
      save_file->goToSection(std::string("[PLAYER INFO]"));
      // 
      save_file->goToSection(std::string("[MISSIONS]"));
      if (tactical_mode)
      {
         save_file->goToSection(std::string("[MAP]"));
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

