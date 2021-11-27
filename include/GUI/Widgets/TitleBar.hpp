#ifndef __TITLE_BAR_HPP__
#define __TITLE_BAR_HPP__

#include <cassert>
#include <cstdint>

#include "GUI/Widgets/Button.hpp"
#include "GUI/Widgets/ContainerWidget.hpp"
#include "GUI/Widgets/Icon.hpp"
#include "GUI/Widgets/Label.hpp"

class TitleBar : public ContainerWidget {
public:
    static const uint32_t kDefaultHeight{48};
    static const uint32_t kDefaultCharSize{24};

public:
    TitleBar(Widget* titled_widget, const std::string& title);
    virtual ~TitleBar() override;

    virtual bool OnMouseButtonPressEvent(const MouseButtonPressEvent* event) override;

    virtual bool OnMouseButtonReleaseEvent(const MouseButtonReleaseEvent* event) override;

    virtual bool OnMouseMoveEvent(const MouseMoveEvent* event) override;

    void CloseTitledWidget();

protected:
    Widget* titled_widget_;
    Label*  title_;
    Button* close_button_;
};

#endif // __TITLE_BAR_HPP__