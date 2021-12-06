#ifndef __I_TOOL_HPP__
#define __I_TOOL_HPP__

#include "Core/Math/Vector2.hpp"

class ContainerWidget;
class RenderTexture;

class ITool {
public:
    virtual ~ITool() {}

    virtual void BeginDraw(RenderTexture* canvas, Vector2i position) = 0;

    virtual void Draw(RenderTexture* canvas, Vector2i position, Vector2i old_position) = 0;

    virtual void EndDraw(RenderTexture* canvas, Vector2i position) = 0;

    virtual const char* GetIconFileName() const = 0;

    virtual const char* GetName() const = 0;

    virtual ContainerWidget* GetPreferencesPanel() = 0;
};

#endif // __I_TOOL_HPP__