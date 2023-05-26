//
// Player.h
// Implements the characteristic of a player
//
//

#include <string>

#include <Corporation.h>

class Player
{
   public:
      Player();
      ~Player();
      void save(const std::string fileName) const;
      void load(const std::string fileName);
      void print() const;
   private:
      Corporation* corporation;
      std::string name;
      bool managed_by_computer;
      unsigned int score;
      unsigned int money;
      unsigned int fame;
      unsigned int loyalty;
};
