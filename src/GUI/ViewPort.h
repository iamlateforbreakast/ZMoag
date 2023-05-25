//
// ViewPort.h
//
//
//

#include <Widget.h>

class ViewPort : public Widget
{
   public:
      ViewPort(string name, int x, int y, int w, int h);
      ~ViewPort();
      void     draw(SDLSurface* window);
      void     processEvent(MMIEvent& e);
      void update();
      string   getName() const;
      void save(const string fileName) const;
      void load(const string fileName);
      void print() const;
   private:
};
