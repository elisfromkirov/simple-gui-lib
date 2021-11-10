#include "GUI/Config.hpp"
#include "Editor/MainPanel.hpp"

void PressedResponse() {
    printf("Pressed response called!\n");
}

void ClickResponse() {
    printf("Click response called!\n");
}

MainPanel::MainPanel(const Vector2u& size) 
    : Widget{size} {
    ButtonBase* button = new ButtonBase(Vector2u(50, 50), Vector2i(100, 100));
    Attach(button);

    button->Pressed.Connect(PressedResponse);
    button->Click.Connect(ClickResponse);

    Image* image = new Image(kCloseButtonFileName, Vector2i(0, 0));
    Attach(image);

    Label* label = new Label("some text", Color(1.f, 1.f, 1.f, 1.f));
    Attach(label);
}

MainPanel::~MainPanel() {}
