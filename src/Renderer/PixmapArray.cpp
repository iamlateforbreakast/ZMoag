//
// PixmapArray.cpp
//
//
//

#include <PixmapArray.h>

PixmapArray::PixmapArray(string filename, int nb_frames, int nb_state)
{
   this->pixmap = new Pixmap(filename);
   this->nb_frames = nb_frames;
   this->nb_states = nb_states;
   debug("Created pixmap from %s with Nb frames=%d, Nb States=%d\n",filename.c_str(),nb_frames,nb_state);
}

PixmapArray::~PixmapArray()
{
}


