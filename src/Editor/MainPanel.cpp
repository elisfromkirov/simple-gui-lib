#include "Config.hpp"
#include "Editor/ColorSheme.hpp"
#include "Editor/MainPanel.hpp"

class EmptyFunctor {
public:
    void operator()() {}
};

MainPanel::MainPanel(const Vector2u& size) 
    : Widget{size} {
    Image* image = new Image(kCloseButtonFileName);
    Attach(new Button<EmptyFunctor>(Vector2u(100, 100), Vector2i(0, 0),
                                    image,
                                    kButtonColorOnPress,
                                    kButtonColorOnRelease,
                                    kButtonColorOnHover));

    Label* label = new Label("Close", Color{1.f, 1.f, 1.f, 1.f});
    Attach(new Button<EmptyFunctor>(Vector2u(100, 100), Vector2i(200, 0),
                                    label,
                                    kButtonColorOnPress,
                                    kButtonColorOnRelease,
                                    kButtonColorOnHover));
    
}

MainPanel::~MainPanel() {}
