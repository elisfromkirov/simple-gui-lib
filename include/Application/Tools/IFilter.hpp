#ifndef __I_FILTER_HPP__
#define __I_FILTER_HPP__

class RenderTexture;

class IFilter {
public:
    virtual ~IFilter() {}

    virtual void Apply(RenderTexture* canvas) = 0;

    virtual const char* GetName() const = 0;
};

#endif // __I_FILTER_HPP__