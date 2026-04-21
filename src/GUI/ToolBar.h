//
// ToolBar.h
//
//
//

#include <Widget.h>
#include "SDLSurface.h"

class ToolBar : public Widget
{
   public:
      ToolBar(std::string name, int x, int y, int w, int h);
      ~ToolBar();
      void     draw(SDLSurface* window);
      void     processEvent(MMIEvent& e);
      std::string   getName() const;
      void save(const std::string fileName) const;
      void load(const std::string fileName);
      void print() const;
   private:
};
