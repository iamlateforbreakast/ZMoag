//
// CommandLine.cpp
//
//
//

#include <CommandLine.h>

CommandLine::CommandLine(Application* parent_object) : Object(NULL, "CommandLine")
{
    (void)parent_object;
}

CommandLine::~CommandLine()
{
}

void    CommandLine::save(const std::string fileName) const
{
    (void)fileName;
}

void    CommandLine::load(const std::string fileName)
{
    (void)fileName;
}

void CommandLine::print() const
{
}


