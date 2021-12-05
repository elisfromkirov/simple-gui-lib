#ifndef __EDITOR_HPP__
#define __EDITOR_HPP__

#include <cassert>
#include <cstdint>
#include <string>

#include "Application/UI/Canvas.hpp"
#include "GUI/Widgets/ContainerWidget.hpp"
#include "GUI/Widgets/TitleBar.hpp"

class Editor : public ContainerWidget {
public:
    Editor(const Rect2& rect, const std::string& name);
    virtual ~Editor() override;

protected:
    TitleBar* title_bar_;
    Canvas*   canvas_;
};

#endif // __EDITOR_HPP__