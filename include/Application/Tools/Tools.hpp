#ifndef __TOOLS_HPP__
#define __TOOLS_HPP__

#include <cassert>
#include <cstdio>

#include "Application/Tools/ITool.hpp"
#include "Core/Platform/Color.hpp"

class Pencil : public ITool {
public:
    Pencil();
    virtual ~Pencil() override;

    virtual void BeginDraw(RenderTexture* canvas, Vector2i position) override;

    virtual void Draw(RenderTexture* canvas, Vector2i position, Vector2i old_position) override;

    virtual void EndDraw(RenderTexture* canvas, Vector2i position) override;

    virtual const char* GetIconFileName() const override;

    virtual const char* GetName() const override;

    virtual ContainerWidget* GetPreferencesPanel() override;

    void SetThickness(uint32_t thickness);
    uint32_t GetMaxThickness() const;

    void SetColor(const Color& color);
    const Color& GetColor();

protected:
    uint32_t thickness_;
    Color    color_;

    ContainerWidget* preferences_panel_;
};

#endif // __TOOLS_HPP__
