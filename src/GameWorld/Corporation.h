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
      void save(const std::string fileName) const;
      void load(const std::string fileName);
      void print();
   private:
      std::string name;
      unsigned int number_of_droids;
      unsigned int number_of_clones;
};
