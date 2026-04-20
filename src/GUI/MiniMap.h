//
// MiniMap.h
//
//
//

#include <Widget.h>
#include <SDLSurface.h>

class MiniMap : public Widget
{
   public:
      MiniMap(std::string name, int x, int y, int w, int h);
      ~MiniMap();
      void     draw(SDLSurface* window);
      void     processEvent(MMIEvent& e);
      std::string   getName() const;
      virtual void    save(const std::string fileName) const;
      virtual void    load(const std::string fileName);
      virtual void    print() const;
   private:
};
