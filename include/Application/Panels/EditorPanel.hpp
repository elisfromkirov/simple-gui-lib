#ifndef __EDITOR_PANEL_HPP__
#define __EDITOR_PANEL_HPP__

#include <cassert>
#include <cstdint>
#include <string>

#include "Application/Events/ApplicationEvent.hpp"
#include "GUI/Widgets/LayeredWidget.hpp"

class EditorPanel : public LayeredWidget {
private:
    static const Vector2u kDefaultSize;

public:
    EditorPanel(const Rect2& rect);
    virtual ~EditorPanel() override;

    void InsertEditor(const std::string& name);

    bool OnOpenEditorEvent(const OpenEditorEvent* event);
};

#endif // __EDITOR_PANEL_HPP__