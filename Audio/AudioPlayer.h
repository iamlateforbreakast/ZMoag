//
// AudioPlayer.h
//
//
//

#ifndef _AUDIOPLAYER_H_
#define _AUDIOPLAYER_H_

#include <Object.h>

class AudioPlayer : public Object
{
   public:
      AudioPlayer(Object* parent_object);
      ~AudioPlayer();
      virtual void save(const string fileName) const;
      virtual void load(const string fileName);
      virtual void print() const;
   private:
};

#endif

