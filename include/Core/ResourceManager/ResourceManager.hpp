#ifndef __RESOURCE_MANAGER_HPP__
#define __RESOURCE_MANAGER_HPP__

#include <cassert>
#include <cstdint>
#include <cstring>

#include "Platform/Font.hpp"
#include "Platform/Sprite.hpp"

class ResourceManager {
private:
    static const char* kDefaultFontsDir;

    static const char* kDefaultImagesDir;

    static ResourceManager* singleton;

private:
    ResourceManager();

public:
    ~ResourceManager();

    Font* LoadFont(const char* name);

    void FreeFont(const Font* font);

    void SetFontsDir(const char* fonts_dir);

    Sprite* LoadSprite(const char* name);

    void FreeSprite(const Sprite* sprite);

    void SetImagesDir(const char* images_dir);

    static ResourceManager* GetResourceManager();

private:
    const char* fonts_dir_;

    const char* images_dir_;
};

#endif // __RESOURCE_MANAGER_HPP__
