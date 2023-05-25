//
// PixmapArray.h
//
//
//

#include <Pixmap.h>

class PixmapArray : public Pixmap
{
   public:
      PixmapArray(string filename, int nb_frames, int nb_states);
      ~PixmapArray();
   private:
      Pixmap *     pixmap;
      unsigned int nb_frames;
      unsigned int nb_states;
};
