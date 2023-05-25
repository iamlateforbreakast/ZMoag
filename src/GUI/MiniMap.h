//
// MiniMap.h
//
//
//

#include <Widget.h>

class MiniMap : public Widget
{
   public:
      MiniMap(string name, int x, int y, int w, int h);
      ~MiniMap();
      void     draw(SDLSurface* window);
      void     processEvent(MMIEvent& e);
      string   getName() const;
      virtual void    save(const string fileName) const;
      virtual void    load(const string fileName);
      virtual void    print() const;
   private:
};
