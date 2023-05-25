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
      void save(const string fileName) const;
      void load(const string fileName);
      void print() const;
   private:
      Corporation* corporation;
      string name;
      bool managed_by_computer;
      unsigned int score;
      unsigned int money;
      unsigned int fame;
      unsigned int loyalty;
};
