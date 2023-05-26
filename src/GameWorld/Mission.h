//
//
//
//
//

#include <string>

#include <Map.h>

class Mission
{
   public:
      Mission();
      ~Mission();
      void start();
      void save(const std::string fileName) const;
      void load(const std::string fileName);
      void print() const;
   private:
      unsigned int money_reward;
      unsigned int difficulty;
      //Map* map;
      //List Items
      //GfxTheme;
      //SfxTheme;
};
