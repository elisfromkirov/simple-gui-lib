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
    : CompositeWidget{size, Vector2i{0, 0}} {
    ResourceManager* resource_manager = ResourceManager::GetInstance();
    assert(resource_manager != nullptr);

    VerticalList* list = new VerticalList(Vector2u{200, 200}, Vector2i{50, 50});
    list->ApplyStyle(new FilledStyle(Color(0.f, 0.f, 1.f, 1.f)));
    
    list->InsertItem(new Label("string 1", resource_manager->LoadFont(kBoldFont)));
    list->InsertItem(new Label("string 2", resource_manager->LoadFont(kBoldFont)));
    list->InsertItem(new Label("string 3", resource_manager->LoadFont(kBoldFont)));
    list->InsertItem(new Label("string 4", resource_manager->LoadFont(kBoldFont)));

    Attach(list);

    DropDownList* drop_down_list = new DropDownList(Vector2u{300, 300}, Vector2i{400, 400});
    drop_down_list->InsertItem(new Label("string 1", resource_manager->LoadFont(kBoldFont)));
    drop_down_list->InsertItem(new Label("string 2", resource_manager->LoadFont(kBoldFont)));
    drop_down_list->InsertItem(new Label("string 3", resource_manager->LoadFont(kBoldFont)));

    Attach(drop_down_list);
}

MainPanel::~MainPanel() {}

void MainPanel::OnRender(Renderer* renderer) {
    assert(renderer != nullptr);

    IRenderTarget* surface = renderer->GetRenderTarget();
    renderer->SetRenderTarget(&surface_);

    renderer->Clear(Color(0.2, 0.2, 0.2, 1.0));

    RenderChildren(renderer);

    renderer->Display();

    renderer->SetRenderTarget(surface);
    renderer->CopyTexture(&surface_, position_);
}