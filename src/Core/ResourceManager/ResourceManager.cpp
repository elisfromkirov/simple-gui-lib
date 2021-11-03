#include "Core/ResourceManager/ResourceManager.hpp"

const char* ResourceManager::kDefaultFontsDir{"assets/Fonts"};

const char* ResourceManager::kDefaultImagesDir{"assets/Images"};

ResourceManager* ResourceManager::singleton{nullptr};

ResourceManager::ResourceManager()
    : fonts_dir_{kDefaultFontsDir},
      images_dir_{kDefaultImagesDir} {}

ResourceManager::~ResourceManager() {}

Font* ResourceManager::LoadFont(const char* name) {
    assert(fonts_dir_ != nullptr);
    assert(name       != nullptr);

    char buffer[128];
    memset(buffer, 0, 128 * sizeof(char));

    snprintf(buffer, 128, "%s/%s", fonts_dir_, name);

    Font* font = new Font(buffer);
    return font;
}

void ResourceManager::FreeFont(const Font* font) {
    assert(font);

    delete font;
}

void ResourceManager::SetFontsDir(const char* fonts_dir) {
    assert(fonts_dir != nullptr);

    fonts_dir_ = fonts_dir;
}

Sprite* ResourceManager::LoadSprite(const char* name) {
    assert(images_dir_ != nullptr);
    assert(name        != nullptr);

    char buffer[128];
    memset(buffer, 0, 128 * sizeof(char));

    snprintf(buffer, 128, "%s/%s", images_dir_, name);

    Sprite* font = new Sprite(buffer);
    return font;
}

void ResourceManager::FreeSprite(const Sprite* sprite) {
    assert(sprite != nullptr);

    delete sprite;
}

void ResourceManager::SetImagesDir(const char* images_dir) {
    assert(images_dir != nullptr);

    images_dir_ = images_dir;
}

ResourceManager* ResourceManager::GetResourceManager() {
    if (singleton == nullptr) {
        singleton = new ResourceManager();
    }

    return singleton;
}
