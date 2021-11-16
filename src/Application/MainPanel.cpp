#include "Application/MainPanel.hpp"
#include "Application/ColorSheme.hpp"
#include "Core/ResourceManager/Resources.hpp"
#include "Core/ResourceManager/ResourceManager.hpp"
#include "GUI/Style/FilledStyle.hpp"
#include "GUI/Widgets/ButtonBase.hpp"
#include "GUI/Widgets/Icon.hpp"
#include "GUI/Widgets/Label.hpp"

#include <cstdio>

void ClickResponse() {
    printf("CLICK RESPONSE!\n");
}

MainPanel::MainPanel(const Vector2u& size)
    : CompositeWidget{size} {
    ButtonBase* button = new ButtonBase(Vector2u{50, 50}, Vector2i{50, 50});
    button->Clicked.Connect(ClickResponse);
    button->ApplyStyle(new FilledStyle(kButtonColorOnRelease, kButtonColorOnPress, kButtonColorOnHover));

    Attach(button);
}

MainPanel::~MainPanel() {}

void MainPanel::OnRender(Renderer* renderer) {
    assert(renderer != nullptr);

    IRenderTarget* surface = renderer->GetRenderTarget();
    renderer->SetRenderTarget(&surface_);

    renderer->Clear();

    RenderChildren(renderer);

    renderer->Display();

    renderer->SetRenderTarget(surface);
    renderer->CopyTexture(&surface_, position_);
}