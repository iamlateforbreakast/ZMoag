//
//
//
//
//

#include <string>

class Corporation
{
   public:
      Corporation();
      ~Corporation();
      void save(const string fileName) const;
      void load(const string fileName);
      void print();
   private:
      string name;
      unsigned int number_of_droids;
      unsigned int number_of_clones;
};
