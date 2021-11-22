#include "Application/MainPanel.hpp"
#include "Application/ColorSheme.hpp"
#include "Core/ResourceManager/Resources.hpp"
#include "Core/ResourceManager/ResourceManager.hpp"
#include "GUI/Styles/FilledStyle.hpp"
#include "GUI/Widgets/Button.hpp"
#include "GUI/Widgets/Icon.hpp"
#include "GUI/Widgets/List.hpp"
#include "GUI/Widgets/Label.hpp"

#include <cstdio>

void ClickResponse() {
    printf("CLICK RESPONSE!\n");
}

MainPanel::MainPanel(const Vector2u& size)
    : CompositeWidget{size} {
    ResourceManager* resource_manager = ResourceManager::GetInstance();
    assert(resource_manager != nullptr);

    Button* button = new Button(Vector2u{100, 100}, Vector2i{300, 300});
    button->ApplyStyle(new FilledStyle(Color(0.f, 1.f, 0.f, 1.f), Color(1.f, 0.f, 0.f, 1.f), Color(1.f, 0.f, 0.f, 1.f)));
    button->Clicked.Connect(ClickResponse);

    Attach(button);

    VerticalList* list = new VerticalList(Vector2u{200, 200});
    list->ApplyStyle(new FilledStyle(Color(1.f, 0.f, 0.f, 1.f)));
    
    list->InsertItem(new Label("string 1", resource_manager->LoadFont(kBoldFont)));
    list->InsertItem(new Label("string 2", resource_manager->LoadFont(kBoldFont)));
    list->InsertItem(new Label("string 3", resource_manager->LoadFont(kBoldFont)));
    list->InsertItem(new Label("string 4", resource_manager->LoadFont(kBoldFont)));

    Attach(list);
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