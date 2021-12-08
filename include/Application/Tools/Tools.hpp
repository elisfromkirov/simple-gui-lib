#ifndef __TOOLS_HPP__
#define __TOOLS_HPP__

#include <cassert>
#include <cstdio>

#include "Application/Tools/ITool.hpp"
#include "Core/Platform/Color.hpp"
#include "Core/Platform/Rectangle.hpp"
#include "Core/Platform/RenderTexture.hpp"

class Pencil : public ITool {
public:
    Pencil();
    virtual ~Pencil() override;

    virtual void BeginDraw(RenderTexture* canvas, const Vector2i& position) override;

    virtual void Draw(RenderTexture* canvas, const Vector2i& position, const Vector2i& old_position) override;

    virtual void EndDraw(RenderTexture* canvas, const Vector2i& position) override;

    virtual const char* GetIconFileName() const override;

    virtual const char* GetName() const override;

    virtual Widget* GetPreferencesPanel() override;

    void SetColor(const Color& color);

protected:
    Rectangle        rectangle_;

    Widget* preferences_panel_;
};

class Eraser : public ITool {
public:
    Eraser();
    virtual ~Eraser() override;

    virtual void BeginDraw(RenderTexture* canvas, const Vector2i& position) override;

    virtual void Draw(RenderTexture* canvas, const Vector2i& position, const Vector2i& old_position) override;

    virtual void EndDraw(RenderTexture* canvas, const Vector2i& position) override;

    virtual const char* GetIconFileName() const override;

    virtual const char* GetName() const override;

    virtual Widget* GetPreferencesPanel() override;

    void SetThickness(uint32_t thickness);

protected:
    Rectangle        rectangle_;

    Widget* preferences_panel_;
};

class Brush : public ITool {
public:
    Brush();
    virtual ~Brush() override;

    virtual void BeginDraw(RenderTexture* canvas, const Vector2i& position) override;

    virtual void Draw(RenderTexture* canvas, const Vector2i& position, const Vector2i& old_position) override;

    virtual void EndDraw(RenderTexture* canvas, const Vector2i& position) override;

    virtual const char* GetIconFileName() const override;

    virtual const char* GetName() const override;

    virtual Widget* GetPreferencesPanel() override;

    void SetColor(const Color& color);
    void SetThickness(uint32_t thickness);

protected:
    Rectangle        rectangle_;

    Widget* preferences_panel_;
};

#endif // __TOOLS_HPP__