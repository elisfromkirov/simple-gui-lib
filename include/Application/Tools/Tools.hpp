#ifndef __TOOLS_HPP__
#define __TOOLS_HPP__

#include <cassert>
#include <cstdio>

#include "Application/Tools/ITool.hpp"

class Pencil : public ITool {
public:
    Pencil();
    virtual ~Pencil() override;

    virtual void BeginDraw(RenderTexture* canvas, const Vector2i& position) override;

    virtual void Draw(RenderTexture* canvas, const Vector2i& position, const Vector2i& old_position) override;

    virtual void EndDraw(RenderTexture* canvas, const Vector2i& position) override;

    virtual const char* GetIconFileName() const override;
};

#endif // __TOOLS_HPP__
