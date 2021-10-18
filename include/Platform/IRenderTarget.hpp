#ifndef __I_RENDER_TARGET_HPP__
#define __I_RENDER_TARGET_HPP__

class IRenderTarget {
public:
    virtual ~IRenderTarget() {}

    virtual void* GetRenderTarget() = 0;
};

#endif // __I_RENDER_TARGET_HPP__
