//
// ViewPort.h
//
//
//

#include <Widget.h>
#include "SDLSurface.h"

class ViewPort : public Widget
{
   public:
      ViewPort(std::string name, int x, int y, int w, int h);
      ~ViewPort();
      void     draw(SDLSurface* window);
      void     processEvent(MMIEvent& e);
      void update();
      std::string   getName() const;
      void save(const std::string fileName) const;
      void load(const std::string fileName);
      void print() const;
   private:
};
