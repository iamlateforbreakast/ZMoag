//
// ToolBar.h
//
//
//

#include <Widget.h>

class ToolBar : public Widget
{
   public:
      ToolBar(string name, int x, int y, int w, int h);
      ~ToolBar();
      void     draw(SDLSurface* window);
      void     processEvent(MMIEvent& e);
      string   getName() const;
      void save(const string fileName) const;
      void load(const string fileName);
      void print() const;
   private:
};
