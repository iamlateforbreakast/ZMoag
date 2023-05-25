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
      FileSelection(string name, int x, int y, int w, int h);
      ~FileSelection();
      void draw(SDLSurface* window);
      virtual void    save(const string fileName) const;
      virtual void    load(const string fileName);
      virtual void    print() const;
   private:
      string name;
      unsigned x;
      unsigned int y;
      unsigned int width;
      unsigned int height;
};
