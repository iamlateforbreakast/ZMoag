//
// ScreenAction.h
//
//
//


class ScreenAction
{
   public:
      ScreenAction();
      ~ScreenAction();
      bool isActive();
   private:
      ScreenActionType type;      
};

class KeyPressScreenAction
{
   public:
      KeyPressScreenAction();
      ~KeyPressScreenAction();
   private:
      SDLKey k;
};

class TimeOutScreenAction
{
}

class ButtonPressScreenAction
{
}
