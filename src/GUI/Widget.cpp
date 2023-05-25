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
   debug("Called Widget processEvnts\n");
}

WidgetType Widget::getType()
{
   return type;
}

void    Widget::save(const string fileName) const
{
}

void    Widget::load(const string fileName)
{
}

void    Widget::print() const
{
   
}
   
