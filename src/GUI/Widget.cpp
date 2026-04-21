//
// Widget.cpp
//
//
//

#include <Widget.h>
#include <Application.h>

Widget::Widget(WidgetType t) : Object(NULL, "Button")
{
   type = t;
   clicked = false;
   focus = false;
   released = false;
}

Widget::~Widget()
{
}

void Widget::processEvent(MMIEvent& e)
{
   (void)e;
   debug("Called Widget processEvnts\n");
}

WidgetType Widget::getType()
{
   return type;
}

void    Widget::save(const std::string fileName) const
{
   (void)fileName;
}

void    Widget::load(const std::string fileName)
{
   (void)fileName;

}

void    Widget::print() const
{
   
}
   
