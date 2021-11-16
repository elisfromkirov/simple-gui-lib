#include "Core/Platform/Font.hpp"
#include "Core/Platform/Texture.hpp"
#include "Core/ResourceManager/Resources.hpp"
#include "Core/ResourceManager/ResourceManager.hpp"

ResourceManager* ResourceManager::singleton{nullptr};

ResourceManager::ResourceManager()
    : loaded_fonts_{},
      fonts_directory_{kFontsDirectory},
      loaded_textures_{},
      textures_directory_{kImagesDirectory} {
    LoadFont(kBoldFont);
    LoadFont(kLightFont);
    LoadFont(kMediumFont);
    LoadFont(kRegularFont);
    LoadFont(kSemiBoldFont);

    LoadTexture(kBrushImage);
    LoadTexture(kCloseImage);
    LoadTexture(kColorPickerImage);
    LoadTexture(kDownArrowImage);
    LoadTexture(kEraserImage);
    LoadTexture(kFillerImage);
    LoadTexture(kLeftArrowImage);
    LoadTexture(kPaletteImage);
    LoadTexture(kPencilImage);
    LoadTexture(kRightArrowImage);
    LoadTexture(kToolsImage);
    LoadTexture(kUpArrowImage);
}

ResourceManager::~ResourceManager() {}

const Font* ResourceManager::LoadFont(const std::string& name) {
    if (loaded_fonts_.count(name) != 0) {
        return loaded_fonts_[name];
    }

    Font* font = new Font(fonts_directory_ + name);
    loaded_fonts_[name] = font;

    return font;
}

const Texture* ResourceManager::LoadTexture(const std::string& name) {
    if (loaded_textures_.count(name) != 0) {
        return loaded_textures_[name];
    }

    Texture* texture = new Texture(textures_directory_ + name);
    loaded_textures_[name] = texture;

    return texture;
}

ResourceManager* ResourceManager::GetResourceManager() {
    if (singleton == nullptr) {
        singleton = new ResourceManager();
    }
    return singleton;
}
