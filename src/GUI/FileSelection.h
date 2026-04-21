//
// FileSelection.h
//
//
//

#include <Widget.h>
#include <SDLSurface.h>
#include <Application.h>

class FileSelection : public Widget
{
   public:
      FileSelection(std::string name, int x, int y, int w, int h);
      ~FileSelection();
      void draw(SDLSurface* window);
      virtual void    save(const std::string fileName) const;
      virtual void    load(const std::string fileName);
      virtual void    print() const;
   private:
      std::string name;
      unsigned int x;
      unsigned int y;
      unsigned int width;
      unsigned int height;
};
