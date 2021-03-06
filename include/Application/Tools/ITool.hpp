#ifndef __I_TOOL_HPP__
#define __I_TOOL_HPP__

#include "Core/Math/Vector2.hpp"

class Widget;
class RenderTexture;

class ITool {
public:
    virtual ~ITool() {}

    virtual void BeginDraw(RenderTexture* canvas, const Vector2i& position) = 0;

    virtual void Draw(RenderTexture* canvas, const Vector2i& position, const Vector2i& old_position) = 0;

    virtual void EndDraw(RenderTexture* canvas, const Vector2i& position) = 0;

    virtual const char* GetIconFileName() const = 0;

    virtual const char* GetName() const = 0;

    virtual Widget* GetPreferencesPanel() = 0;
};

#endif // __I_TOOL_HPP__