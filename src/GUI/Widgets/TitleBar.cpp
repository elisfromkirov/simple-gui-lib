#include "Config.hpp"
#include "GUI/Widgets/TitleBar.hpp"

TitleBar::TitleBar(Widget* widget, const std::string& name) {
    assert(widget);

    Image* image = new Image(kCloseButtonFileName);

    Label* label = new Label(name);

    


}

TitleBar::~TitleBar() {}

void TitleBar::Render(Renderer* renderer) const {

}

void TitleBar::Resize(const Vector2u& size) {

}
