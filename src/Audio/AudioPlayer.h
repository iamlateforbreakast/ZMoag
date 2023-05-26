//
// AudioPlayer.h
//
//
//

#ifndef _AUDIOPLAYER_H_
#define _AUDIOPLAYER_H_

#include <Object.h>
#include <string>

class AudioPlayer : public Object
{
   public:
      AudioPlayer(Object* parent_object);
      ~AudioPlayer();
      virtual void save(const std::string fileName) const;
      virtual void load(const std::string fileName);
      virtual void print() const;
   private:
};

#endif

